#include "cartesian.hpp"

#include "pybg/cs/cartesian.hpp"
#include "pybg/pybind/box.hpp"
#include "pybg/pybind/linestring.hpp"
#include "pybg/pybind/multilinestring.hpp"
#include "pybg/pybind/multipoint.hpp"
#include "pybg/pybind/multipolygon.hpp"
#include "pybg/pybind/point_2d.hpp"
#include "pybg/pybind/point_3d.hpp"
#include "pybg/pybind/polygon.hpp"
#include "pybg/pybind/ring.hpp"
#include "pybg/pybind/segment.hpp"

namespace pybg {

auto instantiate_cartesian(nanobind::module_ &m) -> void {
  using namespace pybg::cs::cartesian;
  pybg::pybind::instantiate_box<Box, Point>(m);
  pybg::pybind::instantiate_linestring<Linestring, Point>(m);
  pybg::pybind::instantiate_multilinestring<MultiLinestring, Linestring>(m);
  pybg::pybind::instantiate_multipoint<MultiPoint, Point>(m);
  pybg::pybind::instantiate_multipolygon<MultiPolygon, Polygon>(m);
  pybg::pybind::instantiate_point_2d<Point>(m);
  pybg::pybind::instantiate_polygon<Polygon, Ring, Point>(m);
  pybg::pybind::instantiate_ring<Ring, Point>(m);
  pybg::pybind::instantiate_segment<Segment, Point>(m);
}

}
