#include "pybg/io/wkt.hpp"

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "pybg/cartesian/concepts.hpp"
#include "pybg/geographic/concepts.hpp"

template <template <typename> typename Geometry>
auto instantiate_wkt(nanobind::module_& m) {
  m.def("to_wkt", &pybg::to_wkt<Geometry<double>>);
  m.def("from_wkt", &pybg::from_wkt<Geometry<double>>);
  m.def("to_wkt", &pybg::to_wkt<Geometry<float>>);
  m.def("from_wkt", &pybg::from_wkt<Geometry<float>>);
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

  WKT(pybg::cartesian::xy);
  WKT(pybg::cartesian::xyz);
  WKT(pybg::geographic);

  instantiate_wkt<pybg::cartesian::xy::Box>(m);
  instantiate_wkt<pybg::geographic::Box>(m);
}
