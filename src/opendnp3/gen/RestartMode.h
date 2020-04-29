#ifndef PYDNP3_OPENDNP3_GEN_RESTARTMODE_H
#define PYDNP3_OPENDNP3_GEN_RESTARTMODE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/RestartMode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_RestartMode(py::module& m)
{
  // ----- enum class: opendnp3::RestartMode -----
  py::enum_<opendnp3::RestartMode>(m, "RestartMode",
      "Enumeration describing restart mode support of an outstation.")

      .value(
          "UNSUPPORTED",
          opendnp3::RestartMode::UNSUPPORTED,
          "Device does not support restart.")

      .value(
          "SUPPORTED_DELAY_FINE",
          opendnp3::RestartMode::SUPPORTED_DELAY_FINE,
          "Supports restart, and time returned is a fine time delay.")

      .value(
          "SUPPORTED_DELAY_COARSE",
          opendnp3::RestartMode::SUPPORTED_DELAY_COARSE,
          "Supports restart, and time returned is a coarse time delay.");
}

#endif // PYDNP3_OPENDNP3
#endif
