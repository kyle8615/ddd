#ifndef PYDNP3_OPENDNP3_GEN_RESTARTTYPE_H
#define PYDNP3_OPENDNP3_GEN_RESTARTTYPE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/RestartType.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_RestartType(py::module& m)
{
  // ----- enum class: opendnp3::RestartType -----
  py::enum_<opendnp3::RestartType>(m, "RestartType",
      "Enumeration describing restart operation to perform on an outstation.")

      .value(
          "COLD",
          opendnp3::RestartType::COLD,
          "Full reboot.")

      .value(
          "WARM",
          opendnp3::RestartType::WARM,
          "Warm reboot of process only.");
}

#endif // PYDNP3_OPENDNP3
#endif
