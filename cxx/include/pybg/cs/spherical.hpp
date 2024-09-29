#pragma once
#include <boost/geometry.hpp>

#include "pybg/concepts.hpp"

namespace pybg::cs::spherical {

using Spherical = boost::geometry::cs::spherical<boost::geometry::degree>;

template <typename T>
using Point = ModelPoint<T, 2, Spherical>;

template <typename T>
using Linestring = ModelLinestring<T, 2, Spherical>;

template <typename T>
using Polygon = ModelPolygon<T, 2, Spherical>;

template <typename T>
using Box = ModelBox<T, 2, Spherical>;

template <typename T>
using Ring = ModelRing<T, 2, Spherical>;

template <typename T>
using MultiPoint = ModelMultiPoint<T, 2, Spherical>;

template <typename T>
using MultiLinestring = ModelMultiLinestring<T, 2, Spherical>;

template <typename T>
using MultiPolygon = ModelMultiPolygon<T, 2, Spherical>;

template <typename T>
using Segment = ModelSegment<T, 2, Spherical>;

}  // namespace pybg::cs::spherical
