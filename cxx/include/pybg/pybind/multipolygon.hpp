#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "pybg/pybind/container.hpp"

namespace pybg::pybind {

template <typename T, template <typename> typename MultiPolygon,
          template <typename> typename Polygon>
auto bind_multipolygon(nanobind::module_ &m, const char *const name) -> void {
  auto cl = pybg::pybind::bind_container<T, MultiPolygon, Polygon>(m, name);
  cl.def("__repr__", [](const MultiPolygon<T> &self) {
    return "<MultiPolygon with " + std::to_string(self.size()) + " polygons>";
  });
}

template <template <typename> typename MultiPolygon,
          template <typename> typename Polygon>
auto instantiate_multipolygon(nanobind::module_ &m) -> void {
  bind_multipolygon<double, MultiPolygon, Polygon>(m, "MultiPolygon");
}

}  // namespace pybg::pybind
