#pragma once
#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/string.h>

#include "pybg/utility.hpp"

namespace pybg::pybind {

template <typename Segment, typename Point>
auto bind_segment(nanobind::module_ &m,
                  const char *const name) -> nanobind::class_<Segment> {
  return nanobind::class_<Segment>(m, name)
      .def(
          "__init__",
          [](Segment *self, Point p1, Point p2) {
            new (self) Segment();
            self->first = std::move(p1);
            self->second = std::move(p2);
          },
          nanobind::arg("p1"), nanobind::arg("p2"))
      .def_prop_rw(
          "p1", [](const Segment &self) -> Point { return self.first; },
          [](Segment &self, Point p1) { self.first = std::move(p1); })
      .def_prop_rw(
          "p2", [](const Segment &self) -> Point { return self.second; },
          [](Segment &self, Point p2) { self.second = std::move(p2); })
      .def("__repr__", [](const Segment &self) {
        return "Segegment((" +
               utility::point_coordinates_to_string(self.first) + "), (" +
               utility::point_coordinates_to_string(self.second) + "))";
      });
}

template <template <typename> typename Segment,
          template <typename> typename Point>
auto instantiate_segment(nanobind::module_ &m) -> void {
  bind_segment<Segment<double>, Point<double>>(m, "Segment");
}

}  // namespace pybg::pybind
