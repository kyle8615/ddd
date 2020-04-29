#ifndef PYDNP3_OPENDNP3_GEN_BINARYOUTPUTSTATUSQUALITY_H
#define PYDNP3_OPENDNP3_GEN_BINARYOUTPUTSTATUSQUALITY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/BinaryOutputStatusQuality.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_BinaryOutputStatusQuality(py::module& m)
{
  // ----- enum class: opendnp3::BinaryOutputStatusQuality -----
  py::enum_<opendnp3::BinaryOutputStatusQuality>(m, "BinaryOutputStatusQuality",
      "Quality field bitmask for binary output status values.")

      .value(
          "ONLINE",
          opendnp3::BinaryOutputStatusQuality::ONLINE,
          "Set when the data is good, meaning that rest of the system can trust the value.")

      .value(
          "RESTART",
          opendnp3::BinaryOutputStatusQuality::RESTART,
          "The quality all points get before we have established communication (or populated) the point.")

      .value(
          "COMM_LOST",
          opendnp3::BinaryOutputStatusQuality::COMM_LOST,
          "Set if communication has been lost with the source of the data (after establishing contact).")

      .value(
          "REMOTE_FORCED",
          opendnp3::BinaryOutputStatusQuality::REMOTE_FORCED,
          "Set if the value is being forced to a fake value somewhere in the system.")

      .value(
          "LOCAL_FORCED",
          opendnp3::BinaryOutputStatusQuality::LOCAL_FORCED,
          "Set if the value is being forced to a fake value on the original device.")

      .value(
          "RESERVED1",
          opendnp3::BinaryOutputStatusQuality::RESERVED1,
          "Reserved bit 1.")

      .value(
          "RESERVED2",
          opendnp3::BinaryOutputStatusQuality::RESERVED2,
          "Reserved bit 2.")

      .value(
          "STATE",
          opendnp3::BinaryOutputStatusQuality::STATE,
          "State bit.");
}

#endif // PYDNP3_OPENDNP3
#endif
