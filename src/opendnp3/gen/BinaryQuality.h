#ifndef PYDNP3_OPENDNP3_GEN_BINARYQUALITY_H
#define PYDNP3_OPENDNP3_GEN_BINARYQUALITY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/BinaryQuality.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_BinaryQuality(py::module& m)
{
  // ----- enum class: opendnp3::BinaryQuality -----
  py::enum_<opendnp3::BinaryQuality>(m, "BinaryQuality",
      "Quality field bitmask for binary values.")

      .value(
          "ONLINE",
          opendnp3::BinaryQuality::ONLINE,
          "Set when the data is good, meaning that rest of the system can trust the value.")

      .value(
          "RESTART",
          opendnp3::BinaryQuality::RESTART,
          "The quality all points get before we have established communication (or populated) the point.")

      .value(
          "COMM_LOST",
          opendnp3::BinaryQuality::COMM_LOST,
          "Set if communication has been lost with the source of the data (after establishing contact)")

      .value(
          "REMOTE_FORCED",
          opendnp3::BinaryQuality::REMOTE_FORCED,
          "Set if the value is being forced to a fake value somewhere in the system.")

      .value(
          "LOCAL_FORCED",
          opendnp3::BinaryQuality::LOCAL_FORCED,
          "Set if the value is being forced to a fake value on the original device.")

      .value(
          "CHATTER_FILTER",
          opendnp3::BinaryQuality::CHATTER_FILTER,
          "Set if the value is oscillating very quickly and some events are being suppressed.")

      .value(
          "RESERVED",
          opendnp3::BinaryQuality::RESERVED,
          "Reserved bit.")

      .value(
          "STATE",
          opendnp3::BinaryQuality::STATE,
          "State bit.");
}

#endif // PYDNP3_OPENDNP3
#endif
