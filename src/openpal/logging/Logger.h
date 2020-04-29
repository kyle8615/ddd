#ifndef PYDNP3_OPENPAL_LOGGING_LOGGER_H
#define PYDNP3_OPENPAL_LOGGING_LOGGER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/logging/Logger.h>

#ifdef PYDNP3_OPENPAL

namespace py
    = pybind11;

void bind_Logger(py::module& m)
{
  // ----- struct: openpal::Logger::Settings -----
  py::class_<openpal::Logger::Settings, std::shared_ptr<openpal::Logger::Settings>>(m, "LoggerSettings")

      .def(
          py::init<const std::string&, openpal::LogFilters>(),
          py::arg("id"), py::arg("levels"))

      .def_readwrite(
          "id",
          &openpal::Logger::Settings::id)

      .def_readwrite(
          "levels",
          &openpal::Logger::Settings::levels);

  // ----- class: openpal::Logger -----
  py::class_<openpal::Logger, std::shared_ptr<openpal::Logger>>(m, "Logger",
      "A copyable facade over a LogRoot class")

      .def(
          py::init(&openpal::Logger::Empty),
          "Empty constructor: Logger(nullptr, "
          ", 0)")

      .def(
          py::init<const std::shared_ptr<openpal::ILogHandler>, const std::string&, openpal::LogFilters>(),
          py::arg("backend"), py::arg("id"), py::arg("levels"))

      .def_static(
          "Empty",
          &openpal::Logger::Empty)

      .def(
          "Log",
          &openpal::Logger::Log,
          py::arg("filters"), py::arg("location"), py::arg("message"),
          py::return_value_policy::reference)

      .def(
          "Detach",
          (openpal::Logger(openpal::Logger::*)(const std::string&) const)
              & openpal::Logger::Detach,
          py::arg("id"))

      .def(
          "Detach",
          (openpal::Logger(openpal::Logger::*)(const std::string&, openpal::LogFilters) const)
              & openpal::Logger::Detach,
          py::arg("id"), py::arg("levels"))

      .def(
          "Detach",
          (openpal::Logger(openpal::Logger::*)(openpal::LogFilters) const)
              & openpal::Logger::Detach,
          py::arg("levels"))

      .def(
          "IsEnabled",
          &openpal::Logger::IsEnabled,
          py::arg("filters"))

      .def(
          "GetFilters",
          &openpal::Logger::GetFilters)

      .def(
          "SetFilters",
          &openpal::Logger::SetFilters,
          py::arg("filters"))

      .def(
          "Rename",
          &openpal::Logger::Rename,
          py::arg("id"));
}

#endif // PYDNP3_OPENPAL
#endif
