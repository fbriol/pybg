#include <nanobind/nanobind.h>

namespace pybg {

auto instantiate_wkt(nanobind::module_& cartesian,
                     nanobind::module_& geographic,
                     nanobind::module_& spherical) -> void;

}