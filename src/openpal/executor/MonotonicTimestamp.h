#ifndef PYDNP3_OPENPAL_EXECUTOR_MONOTONICTIMESTAMP_H
#define PYDNP3_OPENPAL_EXECUTOR_MONOTONICTIMESTAMP_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/executor/MonotonicTimestamp.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_MonotonicTimestamp(py::module& m)
{
  // ----- class: openpal::MonotonicTimestamp -----
  py::class_<openpal::MonotonicTimestamp>(m, "MonotonicTimestamp",
      "Strong typing for millisecond-based monotonic timestamps")

      .def(py::init<>())

      .def(
          py::init<int64_t>(),
          ":type milliseconds: long",
          py::arg("milliseconds"))

      .def_static(
          "Max",
          &openpal::MonotonicTimestamp::Max)

      .def_static(
          "Min",
          &openpal::MonotonicTimestamp::Min)

      .def(
          "IsMax",
          &openpal::MonotonicTimestamp::IsMax)

      .def(
          "IsMin",
          &openpal::MonotonicTimestamp::IsMin)

      .def(
          "Add",
          &openpal::MonotonicTimestamp::Add,
          py::arg("duration"))

      .def_readwrite(
          "milliseconds",
          &openpal::MonotonicTimestamp::milliseconds,
          ":type milliseconds: long");

  // ----- openpal::operator -----
  m.def(
      "__eq__",
      (bool (*)(const openpal::MonotonicTimestamp&, const openpal::MonotonicTimestamp&))
          & openpal::operator==,
      "MonotonicTimestamp equality comparision.");

  m.def(
      "__gt__",
      (bool (*)(const openpal::MonotonicTimestamp&, const openpal::MonotonicTimestamp&))
          & openpal::operator>,
      "MonotonicTimestamp greater than comparision.");

  m.def(
      "__lt__",
      (bool (*)(const openpal::MonotonicTimestamp&, const openpal::MonotonicTimestamp&))
          & openpal::operator<,
      "MonotonicTimestamp less than comparision.");
}

#endif // PYDNP3_OPENPAL
#endif
