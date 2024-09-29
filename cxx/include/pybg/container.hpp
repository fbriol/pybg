#pragma once

#include <nanobind/make_iterator.h>
#include <nanobind/nanobind.h>

#include "pybg/wkt.hpp"

namespace pybg {
auto wrap(Py_ssize_t idx, size_t n) -> size_t {
  if (idx < 0) {
    idx += static_cast<Py_ssize_t>(n);
  }

  if (idx < 0 || (size_t)idx >= n) {
    throw nanobind::index_error("index out of range");
  }

  return idx;
}

template <typename Container>
auto bind_container(nanobind::class_<Container> &cl) -> void {
  constexpr auto policy = nanobind::rv_policy::automatic_reference;

  using ValueRef = typename nanobind::detail::iterator_access<
      typename Container::iterator>::result_type;
  using Value = std::decay_t<ValueRef>;

  cl.def("__len__", [](const Container &self) { return self.size(); })

      .def(
          "__bool__", [](const Container &self) { return !self.empty(); },
          "Return True if the vector is not empty")

      .def(
          "__iter__",
          [](Container &self) {
            return nanobind::make_iterator<policy>(nanobind::type<Container>(),
                                                   "Iterator", self.begin(),
                                                   self.end());
          },
          nanobind::keep_alive<0, 1>())

      .def(
          "__getitem__",
          [](Container &self, Py_ssize_t key) -> ValueRef {
            return self[wrap(key, self.size())];
          },
          policy)

      .def("__setitem__",
           [](Container &self, Py_ssize_t key, const Value &value) {
             self[wrap(key, self.size())] = value;
           })

      .def("__delitem__",
           [](Container &self, Py_ssize_t key) {
             self.erase(self.begin() + wrap(key, self.size()));
           })

      .def("__getitem__",
           [](const Container &self,
              const nanobind::slice &slice) -> Container * {
             auto [start, stop, step, length] = slice.compute(self.size());
             auto *seq = new Container();
             seq->reserve(length);

             for (size_t ix = 0; ix < length; ++ix) {
               seq->push_back(self[start]);
               start += step;
             }

             return seq;
           })

      .def("__setitem__",
           [](Container &self, const nanobind::slice &slice,
              const Container &value) {
             auto [start, stop, step, length] = slice.compute(self.size());

             if (length != value.size()) {
               throw nanobind::index_error(
                   "Slice assignment error: the number of elements in the "
                   "assigned slice does not match the number of elements in "
                   "the value vector.");
             }

             for (size_t ix = 0; ix < length; ++ix) {
               self[start] = value[ix];
               start += step;
             }
           })

      .def("__delitem__",
           [](Container &self, const nanobind::slice &slice) {
             auto [start, stop, step, length] = slice.compute(self.size());
             if (length == 0) {
               return;
             }

             stop = start + (length - 1) * step;
             if (start > stop) {
               std::swap(start, stop);
               step = -step;
             }

             if (step == 1) {
               self.erase(self.begin() + start, self.begin() + stop + 1);
             } else {
               for (size_t ix = 0; ix < length; ++ix) {
                 self.erase(self.begin() + stop);
                 stop -= step;
               }
             }
           })

      .def("clear", &Container::clear, "Remove all elements from the container")

      .def(
          "pop",
          [](Container &self, Py_ssize_t key) -> Value {
            auto idx = wrap(key, self.size());
            Value value = std::move(self[idx]);
            self.erase(self.begin() + idx);
            return value;
          },
          nanobind::arg("key") = -1,
          "Remove and return the element at the given position")

      .def(
          "append",
          [](Container &self, const Value &value) { self.push_back(value); },
          nanobind::arg("value"),
          "Append an element to the end of the container")

      .def(
          "insert",
          [](Container &self, Py_ssize_t key, const Value &value) {
            auto idx = wrap(key, self.size());
            self.insert(self.begin() + idx, value);
          },
          nanobind::arg("key"), nanobind::arg("value"),
          "Insert an element at the given position")

      .def(
          "extend",
          [](Container &self, const Container &src) {
            self.insert(self.end(), src.begin(), src.end());
          },
          nanobind::arg("src"),
          "Extend the container by appending elements from the iterable");
}
}  // namespace pybg
