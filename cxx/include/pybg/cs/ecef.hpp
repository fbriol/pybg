#pragma once
#include <boost/geometry.hpp>

#include "pybg/concepts.hpp"

namespace pybg::cs::ecef {

template <typename T>
using Point = ModelPoint<T, 3, boost::geometry::cs::cartesian>;

template <typename T>
using Linestring = ModelLinestring<T, 3, boost::geometry::cs::cartesian>;

template <typename T>
using Polygon = ModelPolygon<T, 3, boost::geometry::cs::cartesian>;

template <typename T>
using Box = ModelBox<T, 3, boost::geometry::cs::cartesian>;

template <typename T>
using Ring = ModelRing<T, 3, boost::geometry::cs::cartesian>;

template <typename T>
using MultiPoint = ModelMultiPoint<T, 3, boost::geometry::cs::cartesian>;

template <typename T>
using MultiLinestring =
    ModelMultiLinestring<T, 3, boost::geometry::cs::cartesian>;

template <typename T>
using MultiPolygon = ModelMultiPolygon<T, 3, boost::geometry::cs::cartesian>;

template <typename T>
using Segment = ModelSegment<T, 3, boost::geometry::cs::cartesian>;

}  // namespace pybg::cs::ecef
