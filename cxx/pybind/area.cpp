#include "pybg/algorithm/area.hpp"

#include <nanobind/nanobind.h>

#include "pybg/cartesian/concepts.hpp"
#include "pybg/geographic/concepts.hpp"

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
         const pybg::geographic::Strategy strategy,
         const pybg::geographic::Spheroid<double>& spheroid) {
        return pybg::algorithm::area_with_strategy(geometry, strategy,
                                                   spheroid);
      },
      nanobind::arg("geometry"), nanobind::arg("strategy"),
      nanobind::arg("spheroid"));
}

#define AREA(CS)                            \
  instantiate_area<CS::Box>(m);             \
  instantiate_area<CS::Linestring>(m);      \
  instantiate_area<CS::MultiLinestring>(m); \
  instantiate_area<CS::MultiPoint>(m);      \
  instantiate_area<CS::MultiPolygon>(m);    \
  instantiate_area<CS::Point>(m);           \
  instantiate_area<CS::Polygon>(m);         \
  instantiate_area<CS::Ring>(m);            \
  instantiate_area<CS::Segment>(m)

#define AREA_WITH_STRATEGY(CS)                            \
  instantiate_area_with_strategy<CS::Box>(m);             \
  instantiate_area_with_strategy<CS::Linestring>(m);      \
  instantiate_area_with_strategy<CS::MultiLinestring>(m); \
  instantiate_area_with_strategy<CS::MultiPoint>(m);      \
  instantiate_area_with_strategy<CS::MultiPolygon>(m);    \
  instantiate_area_with_strategy<CS::Point>(m);           \
  instantiate_area_with_strategy<CS::Polygon>(m);         \
  instantiate_area_with_strategy<CS::Ring>(m);            \
  instantiate_area_with_strategy<CS::Segment>(m)

NB_MODULE(_area, m) {
  m.import_("_cartesian");
  m.import_("_geographic");

  AREA(pybg::cartesian::xy);
  AREA(pybg::geographic);
  AREA_WITH_STRATEGY(pybg::geographic);

  instantiate_area<pybg::cartesian::xyz::Linestring>(m);
  instantiate_area<pybg::cartesian::xyz::Point>(m);
  instantiate_area<pybg::cartesian::xyz::Segment>(m);
}
