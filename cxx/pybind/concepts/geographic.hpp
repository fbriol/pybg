#pragma once

#include <nanobind/nanobind.h>

namespace pybg {

auto instantiate_geographic(nanobind::module_& m) -> void;

}