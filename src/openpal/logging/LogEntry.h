#ifndef PYDNP3_OPENPAL_LOGGING_LOGENTRY_H
#define PYDNP3_OPENPAL_LOGGING_LOGENTRY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/logging/LogEntry.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_LogEntry(py::module& m)
{
  // ----- class: openpal::LogEntry -----
  py::class_<openpal::LogEntry, std::shared_ptr<openpal::LogEntry>>(m, "LogEntry",
      "An event recorded by the logging framework.")

      .def(
          py::init<const char*, const openpal::LogFilters&, const char*, const char*>(),
          py::arg("loggerid"), py::arg("filters"), py::arg("location"), py::arg("message"),
          py::return_value_policy::reference)

      .def_readwrite(
          "loggerid",
          &openpal::LogEntry::loggerid)

      .def_readwrite(
          "filters",
          &openpal::LogEntry::filters)

      .def_readwrite(
          "location",
          &openpal::LogEntry::location)

      .def_readwrite(
          "message",
          &openpal::LogEntry::message);
}

#endif // PYDNP3_OPENPAL
#endif
