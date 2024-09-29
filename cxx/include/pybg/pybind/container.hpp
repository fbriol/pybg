#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include "pybg/container.hpp"
#include "pybg/ndarray.hpp"

namespace pybg::pybind {

namespace {

template <typename T, template <typename> typename Container, std::size_t N,
          std::size_t... Is>
void emplace_back_coordinates(Container<T> *self,
                              const Matrix<T, N> &coordinates, std::size_t i,
                              std::index_sequence<Is...>) {
  self->emplace_back(coordinates(i, Is)...);
}

template <typename T, template <typename> typename Container, std::size_t N,
          std::size_t... Is>
void init_constructor_impl(Container<T> *self, Matrix<T, N> &coordinates,
                           std::index_sequence<Is...>) {
  new (self) Container<T>();
  self->reserve(coordinates.size());

  for (auto i = 0; i < coordinates.shape(0); ++i) {
    emplace_back_coordinates<T, Container, N>(self, coordinates, i,
                                              std::index_sequence<Is...>{});
  }
}

template <typename T, template <typename> typename Container, std::size_t N>
void init_constructor(Container<T> *self, Matrix<T, N> &coordinates) {
  init_constructor_impl<T, Container, N>(self, coordinates,
                                         std::make_index_sequence<N>());
}

}  // namespace

template <typename Point>
using NDims = boost::geometry::traits::dimension<Point>;

template <typename T, template <typename> typename Container,
          template <typename> typename Item, size_t N>
auto bind_container(nanobind::module_ &m,
                    const char *const name) -> nanobind::class_<Container<T>> {
  auto cl = nanobind::class_<Container<T>>(m, name);
  cl.def(
      "__init__",
      [](Container<T> *self, std::optional<pybg::Matrix<T, N>> &coordinates) {
        if (coordinates) {
          init_constructor<T, Container, N>(self, *coordinates);
        }
      },
      nanobind::arg("coordinates") = std::nullopt);

  pybg::bind_container(cl);
  return cl;
}

template <typename T, template <typename> typename Container,
          template <typename> typename Item>
auto bind_container(nanobind::module_ &m,
                    const char *const name) -> nanobind::class_<Container<T>> {
  auto cl = nanobind::class_<Container<T>>(m, name);
  cl.def(
      "__init__",
      [](Container<T> *self, std::optional<std::vector<Item<T>>> &items) {
        if (items) {
          new (self) Container<T>();
          self->reserve(items->size());
          for (auto &&item : *items) {
            self->emplace_back(std::move(item));
          }
        }
      },
      nanobind::arg("items") = std::nullopt);

  pybg::bind_container(cl);
  return cl;
}

}  // namespace pybg::pybind
