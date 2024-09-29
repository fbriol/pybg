#pragma once
#include <boost/geometry.hpp>

namespace pybg {
template <typename T, std::size_t Dimension, typename CoordinateSystem>
using ModelPoint =
    boost::geometry::model::point<T, Dimension, CoordinateSystem>;

template <typename T, std::size_t Dimension, typename CoordinateSystem>
using ModelLinestring = boost::geometry::model::linestring<
    ModelPoint<T, Dimension, CoordinateSystem>>;

template <typename T, std::size_t Dimension, typename CoordinateSystem>
using ModelPolygon =
    boost::geometry::model::polygon<ModelPoint<T, Dimension, CoordinateSystem>>;

template <typename T, std::size_t Dimension, typename CoordinateSystem>
using ModelBox =
    boost::geometry::model::box<ModelPoint<T, Dimension, CoordinateSystem>>;

template <typename T, std::size_t Dimension, typename CoordinateSystem>
using ModelRing =
    boost::geometry::model::ring<ModelPoint<T, Dimension, CoordinateSystem>>;

template <typename T, std::size_t Dimension, typename CoordinateSystem>
using ModelMultiPoint = boost::geometry::model::multi_point<
    ModelPoint<T, Dimension, CoordinateSystem>>;

template <typename T, std::size_t Dimension, typename CoordinateSystem>
using ModelMultiLinestring = boost::geometry::model::multi_linestring<
    ModelLinestring<T, Dimension, CoordinateSystem>>;

template <typename T, std::size_t Dimension, typename CoordinateSystem>
using ModelMultiPolygon = boost::geometry::model::multi_polygon<
    ModelPolygon<T, Dimension, CoordinateSystem>>;

template <typename T, std::size_t Dimension, typename CoordinateSystem>
using ModelSegment =
    boost::geometry::model::segment<ModelPoint<T, Dimension, CoordinateSystem>>;

}  // namespace pybg
