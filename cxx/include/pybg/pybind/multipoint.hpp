#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "pybg/pybind/container.hpp"

namespace pybg::pybind {

template <typename T, template <typename> typename MultiPoint,
          template <typename> typename Point>
auto bind_multipoint(nanobind::module_ &m, const char *const name) -> void {
  auto cl = pybg::pybind::bind_container<T, MultiPoint, Point>(m, name);
  cl.def("__repr__", [](const MultiPoint<T> &self) {
    return "<MultiPoint with " + std::to_string(self.size()) + " points>";
  });
}

template <template <typename> typename MultiPoint,
          template <typename> typename Point>
auto instantiate_multipoint(nanobind::module_ &m) -> void {
  bind_multipoint<double, MultiPoint, Point>(m, "MultiPoint");
}

}  // namespace pybg::pybind
