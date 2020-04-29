#ifndef PYDNP3_OPENDNP3_GEN_LINKSTATUS_H
#define PYDNP3_OPENDNP3_GEN_LINKSTATUS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/LinkStatus.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

void bind_LinkStatus(py::module& m)
{
  // ----- enum class: opendnp3::LinkStatus -----
  py::enum_<opendnp3::LinkStatus>(m, "LinkStatus",
      "Enumeration for reset/unreset states of a link layer")

      .value(
          "UNRESET",
          opendnp3::LinkStatus::UNRESET,
          "DOWN.")

      .value(
          "RESET",
          opendnp3::LinkStatus::RESET,
          "UP.");

  // ----- func: opendnp3::LinkStatusToString -----
  m.def(
      "LinkStatusToString",
      &opendnp3::LinkStatusToString,
      py::arg("linkStatus"));
}

#endif // PYDNP3_OPENDNP3
#endif
