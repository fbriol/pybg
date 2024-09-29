#pragma once

#include <boost/geometry.hpp>

#include "pybg/concepts.hpp"

namespace pybg::geographic {
template <typename T>
using Point = ModelPoint<T, 2, boost::geometry::cs::geographic<T>>;

template <typename T>
using Linestring = ModelLinestring<T, 2, boost::geometry::cs::geographic<T>>;

template <typename T>
using Polygon = ModelPolygon<T, 2, boost::geometry::cs::geographic<T>>;

template <typename T>
using Box = ModelBox<T, 2, boost::geometry::cs::geographic<T>>;

template <typename T>
using Ring = ModelRing<T, 2, boost::geometry::cs::geographic<T>>;

template <typename T>
using MultiPoint = ModelMultiPoint<T, 2, boost::geometry::cs::geographic<T>>;

template <typename T>
using MultiLinestring =
    ModelMultiLinestring<T, 2, boost::geometry::cs::geographic<T>>;

template <typename T>
using MultiPolygon =
    ModelMultiPolygon<T, 2, boost::geometry::cs::geographic<T>>;

template <typename T>
using Segment = ModelSegment<T, 2, boost::geometry::cs::geographic<T>>;

template <typename T>
using Spheroid = boost::geometry::srs::spheroid<T>;

}  // namespace pybg::geographic
