#include <nanobind/nanobind.h>

namespace pybg {

auto instantiate_area(nanobind::module_& cartesian,
                      nanobind::module_& geographic,
                      nanobind::module_& spherical) -> void;

}