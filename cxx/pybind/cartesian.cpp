#include <nanobind/nanobind.h>

#include "pybg/cartesian/concepts.hpp"
#include "pybg/pybind/box.hpp"
#include "pybg/pybind/linestring.hpp"
#include "pybg/pybind/multilinestring.hpp"
#include "pybg/pybind/multipolygon.hpp"
#include "pybg/pybind/point_2d.hpp"
#include "pybg/pybind/point_3d.hpp"
#include "pybg/pybind/polygon.hpp"
#include "pybg/pybind/ring.hpp"
#include "pybg/pybind/segment.hpp"

auto instantiate_cartesian_xy(nanobind::module_ &m) -> void {
  using namespace pybg::cartesian::xy;
  pybg::pybind::instantiate_point_2d<Point>(m);
  pybg::pybind::instantiate_box<Box, Point>(m);
  pybg::pybind::instantiate_segment<Segment, Point>(m);
  pybg::pybind::instantiate_ring<Ring, Point>(m);
  pybg::pybind::instantiate_linestring<Linestring, Point>(m);
  pybg::pybind::instantiate_polygon<Polygon, Ring, Point>(m);
  pybg::pybind::instantiate_multipolygon<MultiPolygon, Polygon>(m);
  pybg::pybind::instantiate_multilinestring<MultiLinestring, Linestring>(m);
}

auto instantiate_cartesian_xyz(nanobind::module_ &m) -> void {
  using namespace pybg::cartesian::xyz;
  pybg::pybind::instantiate_point_3d<Point>(m);
  pybg::pybind::instantiate_box<Box, Point>(m);
  pybg::pybind::instantiate_segment<Segment, Point>(m);
  pybg::pybind::instantiate_ring<Ring, Point>(m);
  pybg::pybind::instantiate_linestring<Linestring, Point>(m);
  pybg::pybind::instantiate_polygon<Polygon, Ring, Point>(m);
  pybg::pybind::instantiate_multipolygon<MultiPolygon, Polygon>(m);
  pybg::pybind::instantiate_multilinestring<MultiLinestring, Linestring>(m);
}

NB_MODULE(_cartesian, m) {
  auto xy = m.def_submodule("xy");
  instantiate_cartesian_xy(xy);
  auto xyz = m.def_submodule("xyz");
  instantiate_cartesian_xyz(xyz);
}
