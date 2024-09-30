
#pragma once

#define INSTANTIATE_UNARY_ALGORITHM(unary, cs, m) \
  unary<cs::Box>(m);                              \
  unary<cs::Linestring>(m);                       \
  unary<cs::MultiLinestring>(m);                  \
  unary<cs::MultiPoint>(m);                       \
  unary<cs::MultiPolygon>(m);                     \
  unary<cs::Point>(m);                            \
  unary<cs::Polygon>(m);                          \
  unary<cs::Ring>(m);                             \
  unary<cs::Segment>(m)