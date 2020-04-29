#ifndef PYDNP3_OPENDNP3_GEN_ANALOGQUALITY_H
#define PYDNP3_OPENDNP3_GEN_ANALOGQUALITY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/AnalogQuality.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_AnalogQuality(py::module& m)
{
  // ----- enum class: opendnp3::AnalogQuality -----
  py::enum_<opendnp3::AnalogQuality>(m, "AnalogQuality",
      "Quality field bitmask for analog values.")

      .value(
          "ONLINE",
          opendnp3::AnalogQuality::ONLINE,
          "Set when the data is good, meaning that rest of the system can trust the value.")

      .value(
          "RESTART",
          opendnp3::AnalogQuality::RESTART,
          "The quality all points get before we have established communication (or populated) the point.")

      .value(
          "COMM_LOST",
          opendnp3::AnalogQuality::COMM_LOST,
          "Set if communication has been lost with the source of the data (after establishing contact).")

      .value(
          "REMOTE_FORCED",
          opendnp3::AnalogQuality::REMOTE_FORCED,
          "Set if the value is being forced to a fake value somewhere in the system.")

      .value(
          "LOCAL_FORCED",
          opendnp3::AnalogQuality::LOCAL_FORCED,
          "Sett if the value is being forced to a fake value on the original device.")

      .value(
          "OVERRANGE",
          opendnp3::AnalogQuality::OVERRANGE,
          "Set if a hardware input etc. is out of range and we are using a place holder value.")

      .value(
          "REFERENCE_ERR",
          opendnp3::AnalogQuality::REFERENCE_ERR,
          "Set if calibration or reference voltage has been lost meaning readings are questionable.")

      .value(
          "RESERVED",
          opendnp3::AnalogQuality::RESERVED,
          "Reserved bit.");
}

#endif // PYDNP3_OPENDNP3
#endif
