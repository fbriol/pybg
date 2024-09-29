#pragma once
#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>

#include <utility>

namespace pybg {

// Helper struct to generate nanobind::shape<-1, -1, ..., -1> with N times -1
template <std::size_t N, typename = std::make_index_sequence<N>>
struct RepeatNegOne;

// Partial specialization that generates the shape
template <std::size_t N, std::size_t... Is>
struct RepeatNegOne<N, std::index_sequence<Is...>> {
  // Each (static_cast<void>(Is), -1) evaluates to -1, repeated N times
  using type = nanobind::shape<((static_cast<void>(Is), -1))...>;
};

// Alias to extract the 'type' member from RepeatNegOne
template <std::size_t N>
using TensorShape = typename RepeatNegOne<N>::type;

// Tensor alias that represents a const nanobind::ndarray with specified shape
template <typename T, std::size_t N>
using Tensor = const nanobind::ndarray<T, nanobind::c_contig, TensorShape<N>>;

}  // namespace pybg
