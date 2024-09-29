#pragma once

#include <boost/geometry.hpp>

#include "pybg/concepts.hpp"

namespace pybg::cs::geographic {

enum class Strategy : int8_t { Andoyer, Thomas, Vincenty, Karney };

constexpr auto strategy_name(const Strategy& strategy) -> const char* const {
  switch (strategy) {
    case Strategy::Andoyer:
      return "andoyer";
    case Strategy::Thomas:
      return "thomas";
    case Strategy::Vincenty:
      return "vincenty";
    case Strategy::Karney:
      return "karney";
    default:
      return "unknown";
  }
}

using Geographic = boost::geometry::cs::geographic<boost::geometry::degree>;

template <typename T>
using Point = ModelPoint<T, 2, Geographic>;

template <typename T>
using Linestring = ModelLinestring<T, 2, Geographic>;

template <typename T>
using Polygon = ModelPolygon<T, 2, Geographic>;

template <typename T>
using Box = ModelBox<T, 2, Geographic>;

template <typename T>
using Ring = ModelRing<T, 2, Geographic>;

template <typename T>
using MultiPoint = ModelMultiPoint<T, 2, Geographic>;

template <typename T>
using MultiLinestring = ModelMultiLinestring<T, 2, Geographic>;

template <typename T>
using MultiPolygon = ModelMultiPolygon<T, 2, Geographic>;

template <typename T>
using Segment = ModelSegment<T, 2, Geographic>;

template <typename T>
using Spheroid = boost::geometry::srs::spheroid<T>;

}  // namespace pybg::cs::geographic
