#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "pybg/pybind/container.hpp"

namespace pybg::pybind {

template <typename T, template <typename> typename Ring,
          template <typename> typename Point>
auto bind_ring(nanobind::module_ &m, const char *const name) -> void {
  auto cl = pybg::pybind::bind_container<T, Ring, Point, 2>(m, name);
  cl.def("__repr__", [](const Ring<T> &self) {
    return "<Ring with " + std::to_string(self.size()) + " points>";
  });
}

template <template <typename> typename Ring, template <typename> typename Point>
auto instantiate_ring(nanobind::module_ &m) -> void {
  bind_ring<double, Ring, Point>(m, "RingFloat64");
  bind_ring<float, Ring, Point>(m, "RingFloat32");
}

}  // namespace pybg::pybind
