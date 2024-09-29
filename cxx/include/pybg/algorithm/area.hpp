#pragma once

#include <boost/geometry.hpp>
#include <boost/geometry/strategy/geographic/area.hpp>

#include "pybg/geographic/concepts.hpp"

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
                        const geographic::Strategy strategy,
                        const geographic::Spheroid<double>& spheroid) {
  switch (strategy) {
    case geographic::Strategy::Andoyer:
      return boost::geometry::area(geometry, Andoyer(spheroid));
    case geographic::Strategy::Thomas:
      return boost::geometry::area(geometry, Thomas(spheroid));
    case geographic::Strategy::Vincenty:
      return boost::geometry::area(geometry, Vincenty(spheroid));
    case geographic::Strategy::Karney:
      return boost::geometry::area(geometry, Karney(spheroid));
    default:
      throw std::invalid_argument(
          "Invalid geographic area strategy: " +
          std::string(geographic::strategy_name(strategy)));
  }
}

}  // namespace pybg::algorithm
