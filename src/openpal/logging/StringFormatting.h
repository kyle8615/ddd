#ifndef PYDNP3_OPENPAL_LOGGING_STRINGFORMATTING_H
#define PYDNP3_OPENPAL_LOGGING_STRINGFORMATTING_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/logging/StringFormatting.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_StringFormatting(py::module& m)
{
  // ----- const: openpal::MAX_LOG_ENTRY_SIZE -----
  m.attr("MAX_LOG_ENTRY_SIZE") = &openpal::MAX_LOG_ENTRY_SIZE;

  // ----- const: openpal::MAX_HEX_PER_LINE -----
  m.attr("MAX_HEX_PER_LINE") = &openpal::MAX_HEX_PER_LINE;

  // ----- func: openpal::LogHex -----
  m.def(
      "LogHex",
      &openpal::LogHex,
      ":type firstRowSize: unsigned int \n"
      ":type otherRowSize: unsigned int",
      py::arg("logger"), py::arg("filters"), py::arg("source"), py::arg("firstRowSize"), py::arg("otherRowSize"));

  // ----- func: openpal::AllocateCopy -----
  m.def(
      "AllocateCopy",
      &openpal::AllocateCopy,
      "Portable allocation of a copy of a cstring.",
      py::arg("alias"));
}

#endif // PYDNP3_OPENPAL
#endif
