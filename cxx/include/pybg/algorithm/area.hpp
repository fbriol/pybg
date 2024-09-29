#pragma once

#include <boost/geometry.hpp>
#include <boost/geometry/strategy/geographic/area.hpp>

#include "pybg/geographic/concepts.hpp"

namespace pybg::algorithm {

enum class Strategy { Andoyer, Thomas, Vincenty, Karney };

namespace area {
namespace geographic {

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

}  // namespace geographic
}  // namespace area

template <typename Geometry>
auto area(const Geometry& geometry) {
  return boost::geometry::area(geometry);
}

template <typename Geometry>
auto area(const Geometry& geometry, const Strategy strategy,
          const geographic::Spheroid<double>& spheroid) {
  switch (strategy) {
    case area::geographic::Strategy::Andoyer:
      return boost::geometry::area(geometry,
                                   area::geographic::Andoyer(spheroid));
    case area::geographic::Strategy::Thomas:
      return boost::geometry::area(geometry,
                                   area::geographic::Thomas(spheroid));
    case area::geographic::Strategy::Vincenty:
      return boost::geometry::area(geometry,
                                   area::geographic::Vincenty(spheroid));
    case area::geographic::Strategy::Karney:
      return boost::geometry::area(geometry,
                                   area::geographic::Karney(spheroid));
    default:
      throw std::invalid_argument("Invalid geographic area strategy");
  }
}

}  // namespace pybg::algorithm
