#pragma once
#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>

#include <utility>

namespace pybg {

template <typename T, std::size_t N>
using Matrix =
    const nanobind::ndarray<T, nanobind::c_contig, nanobind::shape<-1, N>>;

}  // namespace pybg
