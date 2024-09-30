#include "geographic.hpp"

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

namespace pybg {

auto instantiate_geographic(nanobind::module_& m) -> void {
  using namespace pybg::cs::geographic;
  nanobind::enum_<Strategy>(m, "Strategy")
      .value("Andoyer", Strategy::Andoyer)
      .value("Thomas", Strategy::Thomas)
      .value("Vincenty", Strategy::Vincenty)
      .value("Karney", Strategy::Karney);

  pybind::instantiate_box<Box, Point>(m);
  pybind::instantiate_linestring<Linestring, Point>(m);
  pybind::instantiate_multilinestring<MultiLinestring, Linestring>(m);
  pybind::instantiate_multipoint<MultiPoint, Point>(m);
  pybind::instantiate_multipolygon<MultiPolygon, Polygon>(m);
  pybind::instantiate_point_2d<Point>(m);
  pybind::instantiate_polygon<Polygon, Ring, Point>(m);
  pybind::instantiate_ring<Ring, Point>(m);
  pybind::instantiate_segment<Segment, Point>(m);
  pybind::instantiate_spheroid<Spheroid>(m);
}

}  // namespace pybg
