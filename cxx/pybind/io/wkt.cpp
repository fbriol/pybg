#include "wkt.hpp"

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "pybg/cs/cartesian.hpp"
#include "pybg/cs/geographic.hpp"
#include "pybg/cs/spherical.hpp"
#include "pybg/io/wkt.hpp"

namespace pybg {

template <template <typename> typename Geometry>
auto instantiate_wkt(nanobind::module_& m) {
  m.def("to_wkt", &pybg::to_wkt<Geometry<double>>);
  m.def("from_wkt", &pybg::from_wkt<Geometry<double>>);
}

#define WKT(CS, m)                         \
  instantiate_wkt<CS::Box>(m);             \
  instantiate_wkt<CS::Linestring>(m);      \
  instantiate_wkt<CS::MultiLinestring>(m); \
  instantiate_wkt<CS::MultiPoint>(m);      \
  instantiate_wkt<CS::MultiPolygon>(m);    \
  instantiate_wkt<CS::Point>(m);           \
  instantiate_wkt<CS::Polygon>(m);         \
  instantiate_wkt<CS::Ring>(m);            \
  instantiate_wkt<CS::Segment>(m)

auto instantiate_wkt(nanobind::module_& cartesian,
                     nanobind::module_& geographic,
                     nanobind::module_& spherical) -> void {
  WKT(cs::cartesian, cartesian);
  WKT(cs::geographic, geographic);
  WKT(cs::spherical, spherical);
}

}  // namespace pybg