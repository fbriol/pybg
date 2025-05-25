#include <nanobind/nanobind.h>

namespace pybg::pybind {

template <typename T, template <typename> typename Spheroid>
auto bind_spheroid(nanobind::module_& m, const char* const name) -> void {
  nanobind::class_<Spheroid<T>>(m, name)
      .def("__init__", [](Spheroid<T>* self) { new (self) Spheroid<T>(); })
      .def(
          "__init__",
          [](Spheroid<T>* self, const T& a, const T& b) {
            new (self) Spheroid<T>(a, b);
          },
          nanobind::arg("a"), nanobind::arg("b"))
      .def_prop_rw(
          "a",
          [](const Spheroid<T>& self) { return self.template get_radius<0>(); },
          [](Spheroid<T>& self, const T& a) { self.template set_radius<0>(a); },
          "The semi-major axis of the spheroid.")
      .def_prop_rw(
          "b",
          [](const Spheroid<T>& self) { return self.template get_radius<1>(); },
          [](Spheroid<T>& self, const T& b) { self.template set_radius<1>(b); },
          "The semi-minor axis of the spheroid.");
}

template <template <typename> typename Spheroid>
auto instantiate_spheroid(nanobind::module_& m) -> void {
  bind_spheroid<double, Spheroid>(m, "Spheroid");
}

}  // namespace pybg::pybind
