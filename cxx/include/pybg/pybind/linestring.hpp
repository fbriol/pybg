#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "pybg/pybind/container.hpp"

namespace pybg::pybind {

template <typename T, template <typename> typename Linestring,
          template <typename> typename Point>
auto bind_linestring(nanobind::module_ &m, const char *const name) -> void {
  auto cl = pybg::pybind::bind_container<T, Linestring, Point, 2>(m, name);
  cl.def("__repr__", [](const Linestring<T> &self) {
    return "<Linestring with " + std::to_string(self.size()) + " points>";
  });
}

template <template <typename> typename Linestring,
          template <typename> typename Point>
auto instantiate_linestring(nanobind::module_ &m) -> void {
  bind_linestring<double, Linestring, Point>(m, "LinestringFloat64");
  bind_linestring<float, Linestring, Point>(m, "LinestringFloat32");
}

}  // namespace pybg::pybind
