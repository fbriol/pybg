#pragma once

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "pybg/pybind/container.hpp"

namespace pybg::pybind {

template <typename T, template <typename> typename MultiLinestring,
          template <typename> typename Linestring>
auto bind_multilinestring(nanobind::module_ &m,
                          const char *const name) -> void {
  auto cl =
      pybg::pybind::bind_container<T, MultiLinestring, Linestring>(m, name);
  cl.def("__repr__", [](const MultiLinestring<T> &self) {
    return "<MultiLinestring with " + std::to_string(self.size()) +
           " linestrings>";
  });
}

template <template <typename> typename MultiLinestring,
          template <typename> typename Linestring>
auto instantiate_multilinestring(nanobind::module_ &m) -> void {
  bind_multilinestring<double, MultiLinestring, Linestring>(
      m, "MultiLinestring");
}

}  // namespace pybg::pybind
