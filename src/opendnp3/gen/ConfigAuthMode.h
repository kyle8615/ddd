#ifndef PYDNP3_OPENDNP3_GEN_CONFIGAUTHMODE_H
#define PYDNP3_OPENDNP3_GEN_CONFIGAUTHMODE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/ConfigAuthMode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_ConfigAuthMode(py::module& m)
{
  // ----- enum class: opendnp3::ConfigAuthMode -----
  py::enum_<opendnp3::ConfigAuthMode>(m, "ConfigAuthMode",
      "Configuration enum for the authentication mode.")

      .value(
          "NONE",
          opendnp3::ConfigAuthMode::NONE,
          "No authentication.")

      .value(
          "SAV5",
          opendnp3::ConfigAuthMode::SAV5,
          "Secure authentication version 5.");
}

#endif // PYDNP3_OPENDNP3
#endif
