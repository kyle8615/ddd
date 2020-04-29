#ifndef PYDNP3_OPENPAL_EXECUTOR_TIMEDURATION_H
#define PYDNP3_OPENPAL_EXECUTOR_TIMEDURATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/executor/TimeDuration.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_TimeDuration(py::module& m)
{
  // ----- class: openpal::TimeDurationBase<int64_t> -----
  py::class_<openpal::TimeDurationBase<int64_t>>(m, "TimeDurationBase")

      .def(py::init<>())

      .def(
          "GetMilliseconds",
          &openpal::TimeDurationBase<int64_t>::GetMilliseconds)

      .def(
          "IsNegative",
          &openpal::TimeDurationBase<int64_t>::IsNegative)

      .def_readwrite(
          "milliseconds",
          &openpal::TimeDurationBase<int64_t>::milliseconds,
          ":type milliseconds: long");

  // ----- class: openpal::TimeDuration -----
  py::class_<openpal::TimeDuration, openpal::TimeDurationBase<int64_t>>(m, "TimeDuration",
      "Strong typing for millisecond based time durations.")

      .def(py::init<>())

      .def(
          "MultiplyBy",
          &openpal::TimeDuration::MultiplyBy,
          py::arg("factor"))

      .def_static(
          "Min",
          &openpal::TimeDuration::Min)

      .def_static(
          "Max",
          &openpal::TimeDuration::Max)

      .def_static(
          "Zero",
          &openpal::TimeDuration::Zero)

      .def_static(
          "Milliseconds",
          &openpal::TimeDuration::Milliseconds,
          ":type milliseconds: long",
          py::arg("milliseconds"))

      .def_static(
          "Seconds",
          &openpal::TimeDuration::Seconds,
          ":type seconds: long",
          py::arg("seconds"))

      .def_static(
          "Minutes",
          &openpal::TimeDuration::Minutes,
          ":type minutes: long",
          py::arg("minutes"))

      .def_static(
          "Hours",
          &openpal::TimeDuration::Hours,
          ":type hours: long",
          py::arg("hours"))

      .def_static(
          "Days",
          &openpal::TimeDuration::Days,
          ":type days: long",
          py::arg("days"));

  // ----- openpal::operator -----
  m.def(
      "__eq__",
      (bool (*)(const openpal::TimeDuration&, const openpal::TimeDuration&))
          & openpal::operator==,
      "TimeDuration equality comparision.");
}

#endif // PYDNP3_OPENPAL
#endif
