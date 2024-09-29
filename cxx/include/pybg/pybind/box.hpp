#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/string.h>

#include "pybg/utility.hpp"

namespace pybg::pybind {

template <typename Box, typename Point>
auto bind_box(nanobind::module_ &m,
              const char *const name) -> nanobind::class_<Box> {
  return nanobind::class_<Box>(m, name)
      .def(
          "__init__",
          [](Box *self, std::optional<Point> min_corner,
             std::optional<Point> max_corner) {
            new (self) Box();
            if (min_corner) {
              self->min_corner() = std::move(*min_corner);
            }
            if (max_corner) {
              self->max_corner() = std::move(*max_corner);
            }
          },
          nanobind::arg("min_corner") = std::nullopt,
          nanobind::arg("max_corner") = std::nullopt)
      .def("__repr__", [](const Box &self) {
        return "Box((" +
               utility::point_coordinates_to_string(self.min_corner()) +
               "), (" +
               utility::point_coordinates_to_string(self.max_corner()) + "))";
      });
}

template <template <typename> typename Box, template <typename> typename Point>
auto instantiate_box(nanobind::module_ &m) -> void {
  bind_box<Box<double>, Point<double>>(m, "BoxFloat64");
  bind_box<Box<float>, Point<float>>(m, "BoxFloat32");
}

}  // namespace pybg::pybind
