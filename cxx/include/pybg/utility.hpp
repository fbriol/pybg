#pragma once

#include <boost/geometry.hpp>
#include <string>
#include <utility>

namespace pybg::utility {

// Helper function to convert point coordinates to a comma-separated string
template <typename T, size_t N, typename CoordinateSystem, size_t... Is>
auto point_to_string_impl(
    const boost::geometry::model::point<T, N, CoordinateSystem>& point,
    std::index_sequence<Is...>) -> std::string {
  std::string result;
  // The lambda ensures proper comma placement
  ((result +=
    (Is == 0 ? "" : ", ") + std::to_string(boost::geometry::get<Is>(point))),
   ...);
  return result;
}

// Helper function to convert point coordinates to a comma-separated string
template <typename T, std::size_t N, typename CoordinateSystem>
std::string point_coordinates_to_string(
    const boost::geometry::model::point<T, N, CoordinateSystem>& point) {
  return point_to_string_impl(point, std::make_index_sequence<N>{});
}

}  // namespace pybg::utility
