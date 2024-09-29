#pragma once

#include <boost/geometry.hpp>
#include <boost/geometry/strategy/geographic/area.hpp>

#include "pybg/cs/geographic.hpp"

namespace pybg::algorithm {

namespace {

using Andoyer = boost::geometry::strategy::area::geographic<
    boost::geometry::strategy::andoyer,
    boost::geometry::strategy::default_order<
        boost::geometry::strategy::andoyer>::value,
    boost::geometry::srs::spheroid<double>>;

using Thomas = boost::geometry::strategy::area::geographic<
    boost::geometry::strategy::thomas,
    boost::geometry::strategy::default_order<
        boost::geometry::strategy::thomas>::value,
    boost::geometry::srs::spheroid<double>>;

using Vincenty = boost::geometry::strategy::area::geographic<
    boost::geometry::strategy::vincenty,
    boost::geometry::strategy::default_order<
        boost::geometry::strategy::vincenty>::value,
    boost::geometry::srs::spheroid<double>>;

using Karney = boost::geometry::strategy::area::geographic<
    boost::geometry::strategy::karney,
    boost::geometry::strategy::default_order<
        boost::geometry::strategy::karney>::value,
    boost::geometry::srs::spheroid<double>>;

}  // namespace

template <typename Geometry>
auto area(const Geometry& geometry) {
  return boost::geometry::area(geometry);
}

template <typename Geometry>
auto area_with_strategy(const Geometry& geometry,
                        const cs::geographic::Strategy strategy,
                        const cs::geographic::Spheroid<double>& spheroid) {
  using namespace cs::geographic;
  switch (strategy) {
    case Strategy::Andoyer:
      return boost::geometry::area(geometry, Andoyer(spheroid));
    case Strategy::Thomas:
      return boost::geometry::area(geometry, Thomas(spheroid));
    case Strategy::Vincenty:
      return boost::geometry::area(geometry, Vincenty(spheroid));
    case Strategy::Karney:
      return boost::geometry::area(geometry, Karney(spheroid));
    default:
      throw std::invalid_argument(
          "Invalid geographic area strategy: " +
          std::string(strategy_name(strategy)));
  }
}

}  // namespace pybg::algorithm
