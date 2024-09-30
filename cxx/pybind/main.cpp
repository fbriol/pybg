#include <nanobind/nanobind.h>

#include "algorithm.hpp"
#include "concepts/cartesian.hpp"
#include "concepts/ecef.hpp"
#include "concepts/geographic.hpp"
#include "concepts/spherical.hpp"
#include "io/wkt.hpp"

NB_MODULE(_core, m) {
  auto cartesian = m.def_submodule("cartesian", "Cartesian concepts");
  auto ecef = m.def_submodule("ecef", "ECEF concepts");
  auto geographic = m.def_submodule("geographic", "Geographic concepts");
  auto spherical = m.def_submodule("spherical", "Spherical concepts");

  pybg::instantiate_cartesian(cartesian);
  pybg::instantiate_ecef(ecef);
  pybg::instantiate_geographic(geographic);
  pybg::instantiate_shperical(spherical);

  pybg::instantiate_wkt(cartesian, geographic, spherical);

  pybg::instantiate_area(cartesian, geographic, spherical);
}