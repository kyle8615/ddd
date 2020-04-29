#ifndef PYDNP3_OPENPAL_LOGGING_LOGLEVELS_H
#define PYDNP3_OPENPAL_LOGGING_LOGLEVELS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/logging/LogLevels.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_OpenpalLogLevels(py::module& m)
{
  // ----- constants openpal::logflags -----
  m.def_submodule("logflags").attr("EVENT") = &openpal::logflags::EVENT;
  m.def_submodule("logflags").attr("ERR") = &openpal::logflags::ERR;
  m.def_submodule("logflags").attr("WARN") = &openpal::logflags::WARN;
  m.def_submodule("logflags").attr("INFO") = &openpal::logflags::INFO;
  m.def_submodule("logflags").attr("DBG") = &openpal::logflags::DBG;
}

#endif // PYDNP3_OPENPAL
#endif
