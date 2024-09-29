#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include <string>

#include "pybg/utility.hpp"

namespace pybg::pybind {

template <typename T, template <typename> typename Point>
auto bind_point_2d(nanobind::module_ &m, const char *const name) -> void {
  nanobind::class_<Point<T>>(m, name)
      .def("__init__", [](Point<T> *self) { new (self) Point<T>(); })

      .def_prop_rw(
          "x", [](const Point<T> &self) { return self.template get<0>(); },
          [](Point<T> &self, T x) { self.template set<0>(x); })

      .def_prop_rw(
          "y", [](const Point<T> &self) { return self.template get<1>(); },
          [](Point<T> &self, T y) { self.template set<1>(y); })

      .def("__repr__", [](const Point<T> &self) {
        return "Point(" + utility::point_coordinates_to_string(self) + ")";
      });
}

template <template <typename> typename Point>
auto instantiate_point_2d(nanobind::module_ &m) -> void {
  bind_point_2d<double, Point>(m, "Point");
}

}  // namespace pybg::pybind
