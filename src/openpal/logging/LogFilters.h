#ifndef PYDNP3_OPENPAL_LOGGING_LOGFILTERS_H
#define PYDNP3_OPENPAL_LOGGING_LOGFILTERS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/logging/LogFilters.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_LogFilters(py::module& m)
{
  // ----- class: openpal::LogFilters -----
  py::class_<openpal::LogFilters, std::shared_ptr<openpal::LogFilters>>(m, "LogFilters",
      "Strongly typed wrapper for flags bitfield.")

      .def(py::init<>())

      .def(
          py::init<int32_t>(),
          py::arg("filters"))

      .def(
          "IsSet",
          &openpal::LogFilters::IsSet,
          py::arg("levels"))

      .def(
          "GetBitfield",
          &openpal::LogFilters::GetBitfield);
}

#endif // PYDNP3_OPENPAL
#endif
