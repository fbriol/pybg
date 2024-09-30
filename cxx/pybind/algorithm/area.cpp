#include "area.hpp"

#include <nanobind/nanobind.h>

#include "pybg/algorithm/area.hpp"
#include "pybg/cs/cartesian.hpp"
#include "pybg/cs/geographic.hpp"
#include "pybg/cs/spherical.hpp"

namespace pybg {

template <template <typename> typename Geometry>
auto instantiate_area(nanobind::module_& m) {
  m.def(
      "area",
      [](const Geometry<double>& geometry) {
        return pybg::algorithm::area(geometry);
      },
      nanobind::arg("geometry"));
}

template <template <typename> typename Geometry>
auto instantiate_area_with_strategy(nanobind::module_& m) {
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

#define AREA(CS, m)                         \
  instantiate_area<CS::Box>(m);             \
  instantiate_area<CS::Linestring>(m);      \
  instantiate_area<CS::MultiLinestring>(m); \
  instantiate_area<CS::MultiPoint>(m);      \
  instantiate_area<CS::MultiPolygon>(m);    \
  instantiate_area<CS::Point>(m);           \
  instantiate_area<CS::Polygon>(m);         \
  instantiate_area<CS::Ring>(m);            \
  instantiate_area<CS::Segment>(m)

#define AREA_WITH_STRATEGY(CS, m)                         \
  instantiate_area_with_strategy<CS::Box>(m);             \
  instantiate_area_with_strategy<CS::Linestring>(m);      \
  instantiate_area_with_strategy<CS::MultiLinestring>(m); \
  instantiate_area_with_strategy<CS::MultiPoint>(m);      \
  instantiate_area_with_strategy<CS::MultiPolygon>(m);    \
  instantiate_area_with_strategy<CS::Point>(m);           \
  instantiate_area_with_strategy<CS::Polygon>(m);         \
  instantiate_area_with_strategy<CS::Ring>(m);            \
  instantiate_area_with_strategy<CS::Segment>(m)

auto instantiate_area(nanobind::module_& cartesian,
                      nanobind::module_& geographic,
                      nanobind::module_& spherical) -> void {
  AREA(cs::cartesian, cartesian);
  AREA(cs::geographic, geographic);
  AREA(cs::spherical, spherical);

  AREA_WITH_STRATEGY(cs::geographic, geographic);
}

}  // namespace pybg