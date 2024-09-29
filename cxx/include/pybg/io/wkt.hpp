#pragma once

#include <boost/geometry.hpp>

namespace pybg {

template <typename Geometry>
auto to_wkt(const Geometry &geometry) -> std::string {
  return boost::geometry::to_wkt(geometry);
}

template <typename Geometry>
auto from_wkt(const std::string &wkt) -> Geometry {
  return boost::geometry::from_wkt<Geometry>(wkt);
}

}  // namespace pybg
