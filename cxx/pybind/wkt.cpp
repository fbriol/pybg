#include "pybg/io/wkt.hpp"

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "pybg/cs/cartesian.hpp"
#include "pybg/cs/geographic.hpp"

template <template <typename> typename Geometry>
auto instantiate_wkt(nanobind::module_& m) {
  m.def("to_wkt", &pybg::to_wkt<Geometry<double>>);
  m.def("from_wkt", &pybg::from_wkt<Geometry<double>>);
}

#define WKT(CS)                            \
  instantiate_wkt<CS::Linestring>(m);      \
  instantiate_wkt<CS::MultiLinestring>(m); \
  instantiate_wkt<CS::MultiPoint>(m);      \
  instantiate_wkt<CS::MultiPolygon>(m);    \
  instantiate_wkt<CS::Point>(m);           \
  instantiate_wkt<CS::Polygon>(m);         \
  instantiate_wkt<CS::Ring>(m);            \
  instantiate_wkt<CS::Segment>(m)

NB_MODULE(_wkt, m) {
  m.import_("_cartesian");
  m.import_("_geographic");

  WKT(pybg::cs::cartesian::xy);
  WKT(pybg::cs::cartesian::xyz);
  WKT(pybg::cs::geographic);

  instantiate_wkt<pybg::cs::cartesian::xy::Box>(m);
  instantiate_wkt<pybg::cs::geographic::Box>(m);
}
