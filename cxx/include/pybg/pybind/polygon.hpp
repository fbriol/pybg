#pragma once
#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/string.h>

namespace pybg::pybind {

template <typename Polygon, typename Ring, typename Point>
auto bind_polygon(nanobind::module_ &m, const char *const name)
    -> nanobind::class_<Polygon> {
  return nanobind::class_<Polygon>(m, name)
      .def(
          "__init__",
          [](Polygon *self, std::optional<Ring> outer,
             std::optional<std::vector<Ring>> inners) {
            new (self) Polygon();
            if (outer) {
              self->outer() = std::move(*outer);
            }
            if (inners) {
              self->inners().resize(inners->size());
              for (size_t ix = 0; ix < inners->size(); ++ix) {
                auto &item = (*inners)[ix];
                self->inners()[ix] = std::move(item);
              }
            }
          },
          nanobind::arg("points") = std::nullopt,
          nanobind::arg("inners") = std::nullopt)
      .def_prop_rw(
          "outer", [](const Polygon &self) { return self.outer(); },
          [](Polygon &self, const Ring &outer) { self.outer() = outer; },
          "The outer ring of the polygon.")
      .def_prop_rw(
          "inners", [](const Polygon &self) { return self.inners(); },
          [](Polygon &self, const std::vector<Ring> &inners) {
            self.inners() = inners;
          },
          "The inner rings of the polygon.")
      .def("__repr__", [](const Polygon &self) {
        return "<Polygon with " + std::to_string(self.outer().size()) +
               " outer points and " + std::to_string(self.inners().size()) +
               " inner rings>";
      });
}

template <template <typename> typename Polygon,
          template <typename> typename Ring, template <typename> typename Point>
auto instantiate_polygon(nanobind::module_ &m) -> void {
  bind_polygon<Polygon<double>, Ring<double>, Point<double>>(m, "Polygon");
}

}  // namespace pybg::pybind
