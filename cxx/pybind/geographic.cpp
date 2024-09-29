#include <nanobind/nanobind.h>

#include "pybg/cs/geographic.hpp"
#include "pybg/pybind/box.hpp"
#include "pybg/pybind/linestring.hpp"
#include "pybg/pybind/multilinestring.hpp"
#include "pybg/pybind/multipoint.hpp"
#include "pybg/pybind/multipolygon.hpp"
#include "pybg/pybind/point_2d.hpp"
#include "pybg/pybind/polygon.hpp"
#include "pybg/pybind/ring.hpp"
#include "pybg/pybind/segment.hpp"
#include "pybg/pybind/spheroid.hpp"

NB_MODULE(_geographic, m) {
  using namespace pybg::cs::geographic;

  nanobind::enum_<Strategy>(m, "Strategy")
      .value("Andoyer", Strategy::Andoyer)
      .value("Thomas", Strategy::Thomas)
      .value("Vincenty", Strategy::Vincenty)
      .value("Karney", Strategy::Karney);

  pybg::pybind::instantiate_box<Box, Point>(m);
  pybg::pybind::instantiate_linestring<Linestring, Point>(m);
  pybg::pybind::instantiate_multilinestring<MultiLinestring, Linestring>(m);
  pybg::pybind::instantiate_multipoint<MultiPoint, Point>(m);
  pybg::pybind::instantiate_multipolygon<MultiPolygon, Polygon>(m);
  pybg::pybind::instantiate_point_2d<Point>(m);
  pybg::pybind::instantiate_polygon<Polygon, Ring, Point>(m);
  pybg::pybind::instantiate_ring<Ring, Point>(m);
  pybg::pybind::instantiate_segment<Segment, Point>(m);
  pybg::pybind::instantiate_spheroid<Spheroid>(m);
}
