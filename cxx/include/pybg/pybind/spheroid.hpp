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
          nanobind::arg("a"), nanobind::arg("b"));
}

template <template <typename> typename Spheroid>
auto instantiate_spheroid(nanobind::module_& m) -> void {
  bind_spheroid<double, Spheroid>(m, "Spheroid");
}

}  // namespace pybg::pybind
