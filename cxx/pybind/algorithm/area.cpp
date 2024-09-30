#include "pybg/algorithm/area.hpp"

#include "area.hpp"
#include "pybg_utils.h"
#include "pybg/cs/cartesian.hpp"
#include "pybg/cs/geographic.hpp"
#include "pybg/cs/spherical.hpp"

namespace pybg {

template <template <typename> typename Geometry>
auto bind_area(nanobind::module_& m) {
  m.def(
      "area",
      [](const Geometry<double>& geometry) {
        return pybg::algorithm::area(geometry);
      },
      nanobind::arg("geometry"));
}

template <template <typename> typename Geometry>
auto bind_area_with_strategy(nanobind::module_& m) {
  m.def(
      "area_with_strategy",
      [](const Geometry<double>& geometry,
         const pybg::cs::geographic::Strategy strategy,
         const pybg::cs::geographic::Spheroid<double>& spheroid) {
        return pybg::algorithm::area_with_strategy(geometry, strategy,
                                                   spheroid);
      },
      nanobind::arg("geometry"), nanobind::arg("strategy"),
      nanobind::arg("spheroid"));
}

auto instantiate_area(nanobind::module_& cartesian,
                      nanobind::module_& geographic,
                      nanobind::module_& spherical) -> void {
  INSTANTIATE_UNARY_ALGORITHM(bind_area, cs::cartesian, cartesian);
  INSTANTIATE_UNARY_ALGORITHM(bind_area, cs::geographic, geographic);
  INSTANTIATE_UNARY_ALGORITHM(bind_area, cs::spherical, spherical);

  INSTANTIATE_UNARY_ALGORITHM(bind_area_with_strategy, cs::geographic,
                              geographic);
}

}  // namespace pybg