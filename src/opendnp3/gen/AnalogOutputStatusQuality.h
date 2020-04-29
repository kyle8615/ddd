#ifndef PYDNP3_OPENDNP3_GEN_ANALOGOUTPUTSTATUSQUALITY_H
#define PYDNP3_OPENDNP3_GEN_ANALOGOUTPUTSTATUSQUALITY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/AnalogOutputStatusQuality.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_AnalogOutputStatusQuality(py::module& m)
{
  // ----- enum class: opendnp3::AnalogOutputStatusQuality -----
  py::enum_<opendnp3::AnalogOutputStatusQuality>(m, "AnalogOutputStatusQuality",
      "Quality field bitmask for analog output status values")

      .value(
          "ONLINE",
          opendnp3::AnalogOutputStatusQuality::ONLINE,
          "Set when the data is good, meaning that rest of the system can trust the value.")

      .value(
          "RESTART",
          opendnp3::AnalogOutputStatusQuality::RESTART,
          "The quality all points get before we have established communication (or populated) the point.")

      .value(
          "COMM_LOST",
          opendnp3::AnalogOutputStatusQuality::COMM_LOST,
          "Set if communication has been lost with the source of the data (after establishing contact).")

      .value(
          "REMOTE_FORCED",
          opendnp3::AnalogOutputStatusQuality::REMOTE_FORCED,
          "Set if the value is being forced to a fake value somewhere in the system.")

      .value(
          "LOCAL_FORCED",
          opendnp3::AnalogOutputStatusQuality::LOCAL_FORCED,
          "Set if the value is being forced to a fake value on the original device.")

      .value(
          "OVERRANGE",
          opendnp3::AnalogOutputStatusQuality::OVERRANGE,
          "Set if a hardware input etc. is out of range and we are using a place holder value.")

      .value(
          "REFERENCE_ERR",
          opendnp3::AnalogOutputStatusQuality::REFERENCE_ERR,
          "Set if calibration or reference voltage has been lost meaning readings are questionable.")

      .value(
          "RESERVED",
          opendnp3::AnalogOutputStatusQuality::RESERVED,
          "Reserved bit.");
}

#endif // PYDNP3_OPENDNP3
#endif
