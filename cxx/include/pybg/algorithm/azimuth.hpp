#pragma once

#include <boost/geometry.hpp>

namespace pybg::algorithm {

template <typename Point1, typename Point2>
auto azimuth(const Point1& point1, const Point2& point2) -> double {
  return boost::geometry::azimuth(point1, point2);
}

}  // namespace pybg::algorithm
