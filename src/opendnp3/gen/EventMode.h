#ifndef PYDNP3_OPENDNP3_GEN_EVENTMODE_H
#define PYDNP3_OPENDNP3_GEN_EVENTMODE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventMode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventMode(py::module& m)
{
  // ----- enum class: opendnp3::EventMode
  py::enum_<opendnp3::EventMode>(m, "EventMode",
      "Describes how a transaction behaves with respect to event generation.")

      .value(
          "Detect",
          opendnp3::EventMode::Detect,
          "Detect events using the specific mechanism for that type.")

      .value(
          "Force",
          opendnp3::EventMode::Force,
          "Force the creation of an event bypassing detection mechanism.")

      .value(
          "Suppress",
          opendnp3::EventMode::Suppress,
          "Never produce an event regardless of changes.")

      .value(
          "EventOnly",
          opendnp3::EventMode::EventOnly,
          "Send an event directly to the event buffer, bypassing the static value completely.");
}

#endif // PYDNP3_OPENDNP3
#endif
