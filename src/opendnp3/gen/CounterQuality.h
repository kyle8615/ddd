#ifndef PYDNP3_OPENDNP3_GEN_COUNTERQUALITY_H
#define PYDNP3_OPENDNP3_GEN_COUNTERQUALITY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/CounterQuality.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CounterQuality(py::module& m)
{
  // ----- enum class: opendnp3::CounterQuality -----
  py::enum_<opendnp3::CounterQuality>(m, "CounterQuality",
      "Quality field bitmask for counter values.")

      .value(
          "ONLINE",
          opendnp3::CounterQuality::ONLINE,
          "Set when the data is good, meaning that rest of the system can trust the value.")

      .value(
          "RESTART",
          opendnp3::CounterQuality::RESTART,
          "The quality all points get before we have established communication (or populated) the point.")

      .value(
          "COMM_LOST",
          opendnp3::CounterQuality::COMM_LOST,
          "Set if communication has been lost with the source of the data (after establishing contact).")

      .value(
          "REMOTE_FORCED",
          opendnp3::CounterQuality::REMOTE_FORCED,
          "Set if the value is being forced to a fake value somewhere in the system.")

      .value(
          "LOCAL_FORCED",
          opendnp3::CounterQuality::LOCAL_FORCED,
          "Set if the value is being forced to a fake value on the original device.")

      .value(
          "ROLLOVER",
          opendnp3::CounterQuality::ROLLOVER,
          "Deprecated flag that indicates value has rolled over.")

      .value(
          "DISCONTINUITY",
          opendnp3::CounterQuality::DISCONTINUITY,
          "Indicates an unusual change in value.")

      .value(
          "RESERVED",
          opendnp3::CounterQuality::RESERVED,
          "Reserved bit.");
}

#endif // PYDNP3_OPENDNP3
#endif
