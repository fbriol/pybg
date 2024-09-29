#pragma once
#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/string.h>

namespace pybg::pybind {

template <typename Polygon, typename Ring, typename Point>
auto bind_polygon(nanobind::module_ &m,
                  const char *const name) -> nanobind::class_<Polygon> {
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
