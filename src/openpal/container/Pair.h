#ifndef PYDNP3_OPENPAL_CONTAINER_PAIR_H
#define PYDNP3_OPENPAL_CONTAINER_PAIR_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/container/Pair.h>

#ifdef PYDNP3_OPENPAL

template <class A, class B>
void declarePair(py::module& m, std::string const& type)
{
  // ----- class: openpal::Pair<A, B> -----
  py::class_<openpal::Pair<A, B>>(m, ("Pair" + type).c_str())

      .def(
          py::init<A&, B&>(),
          py::arg("first"), py::arg("second"))

      .def_readwrite(
          "first",
          &openpal::Pair<A, B>::first)

      .def_readwrite(
          "second",
          &openpal::Pair<A, B>::second);
}

void bind_Pair(py::module& m)
{
  // Example
  declarePair<int, int>(m, "Int");
  declarePair<std::string, std::string>(m, "String");
}

#endif // PYDNP3_OPENPAL
#endif
