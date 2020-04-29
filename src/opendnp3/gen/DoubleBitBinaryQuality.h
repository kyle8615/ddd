#ifndef PYDNP3_OPENDNP3_GEN_DOUBLEBITBINARYQUALITY_H
#define PYDNP3_OPENDNP3_GEN_DOUBLEBITBINARYQUALITY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/DoubleBitBinaryQuality.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_DoubleBitBinaryQuality(py::module& m)
{
  // ----- enum class: opendnp3::DoubleBitBinaryQuality -----
  py::enum_<opendnp3::DoubleBitBinaryQuality>(m, "DoubleBitBinaryQuality",
      "Quality field bitmask for double bit binary values.")

      .value(
          "ONLINE",
          opendnp3::DoubleBitBinaryQuality::ONLINE,
          "Set when the data is good, meaning that rest of the system can trust the value.")

      .value(
          "RESTART",
          opendnp3::DoubleBitBinaryQuality::RESTART,
          "The quality all points get before we have established communication (or populated) the point.")

      .value(
          "COMM_LOST",
          opendnp3::DoubleBitBinaryQuality::COMM_LOST,
          "Set if communication has been lost with the source of the data (after establishing contact).")

      .value(
          "REMOTE_FORCED",
          opendnp3::DoubleBitBinaryQuality::REMOTE_FORCED,
          "Set if the value is being forced to a fake value somewhere in the system.")

      .value(
          "LOCAL_FORCED",
          opendnp3::DoubleBitBinaryQuality::LOCAL_FORCED,
          "Set if the value is being forced to a fake value on the original device.")

      .value(
          "CHATTER_FILTER",
          opendnp3::DoubleBitBinaryQuality::CHATTER_FILTER,
          "Set if the value is oscillating very quickly and some events are being suppressed.")

      .value(
          "STATE1",
          opendnp3::DoubleBitBinaryQuality::STATE1,
          "State bit 1.")

      .value(
          "STATE2",
          opendnp3::DoubleBitBinaryQuality::STATE2,
          "State bit 2.");
}

#endif // PYDNP3_OPENDNP3
#endif
