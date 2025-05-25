#pragma once

#include <boost/geometry.hpp>

#include "pybg/cs/geographic.hpp"

namespace pybg::algorithm {

namespace {

using Andoyer = boost::geometry::strategies::azimuth::geographic<
    boost::geometry::strategy::andoyer>;

using Thomas = boost::geometry::strategies::azimuth::geographic<
    boost::geometry::strategy::thomas>;

using Vincenty = boost::geometry::strategies::azimuth::geographic<
    boost::geometry::strategy::vincenty>;

using Karney = boost::geometry::strategies::azimuth::geographic<
    boost::geometry::strategy::karney>;

}  // namespace

template <typename Point1, typename Point2>
auto azimuth(const Point1& point1, const Point2& point2) -> double {
  return boost::geometry::azimuth(point1, point2);
}

template <typename Point1, typename Point2>
auto azimuth(const Point1& point1, const Point2& point2,
             const cs::geographic::Strategy strategy,
             const cs::geographic::Spheroid<double>& spheroid) {
  using namespace cs::geographic;
  switch (strategy) {
    case Strategy::Andoyer:
      return boost::geometry::azimuth(point1, point2, Andoyer(spheroid));
    case Strategy::Thomas:
      return boost::geometry::azimuth(point1, point2, Thomas(spheroid));
    case Strategy::Vincenty:
      return boost::geometry::azimuth(point1, point2, Vincenty(spheroid));
    case Strategy::Karney:
      return boost::geometry::azimuth(point1, point2, Karney(spheroid));
    default:
      throw std::invalid_argument("Invalid geographic azimuth strategy: " +
                                  std::string(strategy_name(strategy)));
  }
}

}  // namespace pybg::algorithm
