#ifndef PYDNP3_OPENDNP3_GEN_FROZENCOUNTERQUALITY_H
#define PYDNP3_OPENDNP3_GEN_FROZENCOUNTERQUALITY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/FrozenCounterQuality.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_FrozenCounterQuality(py::module& m)
{
  // ----- enum class: opendnp3::FrozenCounterQuality -----
  py::enum_<opendnp3::FrozenCounterQuality>(m, "FrozenCounterQuality",
      "Quality field bitmask for frozen counter values.")

      .value(
          "ONLINE",
          opendnp3::FrozenCounterQuality::ONLINE,
          "Set when the data is good, meaning that rest of the system can trust the value.")

      .value(
          "RESTART",
          opendnp3::FrozenCounterQuality::RESTART,
          "The quality all points get before we have established communication (or populated) the point.")

      .value(
          "COMM_LOST",
          opendnp3::FrozenCounterQuality::COMM_LOST,
          "Set if communication has been lost with the source of the data (after establishing contact).")

      .value(
          "REMOTE_FORCED",
          opendnp3::FrozenCounterQuality::REMOTE_FORCED,
          "Set if the value is being forced to a fake value somewhere in the system.")

      .value(
          "LOCAL_FORCED",
          opendnp3::FrozenCounterQuality::LOCAL_FORCED,
          "Set if the value is being forced to a fake value on the original device.")

      .value(
          "ROLLOVER",
          opendnp3::FrozenCounterQuality::ROLLOVER,
          "Deprecated flag that indicates value has rolled over.")

      .value(
          "DISCONTINUITY",
          opendnp3::FrozenCounterQuality::DISCONTINUITY,
          "Indicates an unusual change in value.")

      .value(
          "RESERVED",
          opendnp3::FrozenCounterQuality::RESERVED,
          "Reserved bit.");
}

#endif // PYDNP3_OPENDNP3
#endif
