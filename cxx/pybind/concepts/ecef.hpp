#pragma once

#include <nanobind/nanobind.h>

namespace pybg {

auto instantiate_ecef(nanobind::module_& m) -> void;

}