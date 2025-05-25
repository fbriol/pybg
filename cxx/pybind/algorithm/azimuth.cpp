#include "pybg/algorithm/azimuth.hpp"

#include <nanobind/stl/optional.h>

#include <optional>

#include "azimuth.hpp"
#include "pybg/cs/cartesian.hpp"
#include "pybg/cs/geographic.hpp"
#include "pybg/cs/spherical.hpp"
#include "pybg_utils.h"

namespace pybg {

template <template <typename> typename Point1,
          template <typename> typename Point2>
auto bind_azimuth(nanobind::module_& m) {
  m.def(
      "azimuth",
      [](const Point1<double>& point1, const Point2<double>& point2) {
        return pybg::algorithm::azimuth(point1, point2);
      },
      nanobind::arg("point1"), nanobind::arg("point2"));
}

template <template <typename> typename Point1,
          template <typename> typename Point2>
auto bind_azimuth_with_strategy(nanobind::module_& m) {
  m.def(
      "azimuth",
      [](const Point1<double>& point1, const Point2<double>& point2,
         const pybg::cs::geographic::Strategy& strategy,
         const std::optional<pybg::cs::geographic::Spheroid<double>>&
             spheroid) {
        return pybg::algorithm::azimuth(
            point1, point2, strategy,
            spheroid.value_or(pybg::cs::geographic::Spheroid<double>{}));
      },
      nanobind::arg("point1"), nanobind::arg("point2"),
      nanobind::arg("strategy"), nanobind::arg("spheroid") = std::nullopt);
}

auto instantiate_azimuth(nanobind::module_& cartesian,
                         nanobind::module_& geographic) -> void {
  bind_azimuth<cs::cartesian::Point, cs::cartesian::Point>(cartesian);
  bind_azimuth<cs::geographic::Point, cs::geographic::Point>(geographic);
  bind_azimuth_with_strategy<cs::geographic::Point, cs::geographic::Point>(
      geographic);
}

}  // namespace pybg
