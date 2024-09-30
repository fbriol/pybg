#pragma once

#include <nanobind/nanobind.h>

namespace pybg {

auto instantiate_azimuth(nanobind::module_& cartesian,
                         nanobind::module_& geographic) -> void;

}  // namespace pybg