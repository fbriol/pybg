#pragma once

#include <nanobind/nanobind.h>

namespace pybg {

auto instantiate_cartesian(nanobind::module_& m) -> void;

}