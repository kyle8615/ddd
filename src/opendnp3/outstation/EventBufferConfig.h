#ifndef PYDNP3_OPENDNP3_OUTSTATION_EVENTBUFFERCONFIG_H
#define PYDNP3_OPENDNP3_OUTSTATION_EVENTBUFFERCONFIG_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/EventBufferConfig.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventBufferConfig(py::module& m)
{
  // ----- class: opendnp3::EventBufferConfig -----
  py::class_<opendnp3::EventBufferConfig>(m, "EventBufferConfig",
      "Configuration of maximum event counts per event type. \n"
      "The underlying implementation uses a *preallocated* heap buffer to store events until they are transmitted "
      "to the master. \n"
      "The size of this buffer is proportional to the TotalEvents() method, i.e. the sum of the maximum events "
      "for each type. \n"
      "Implementations should configure the buffers to store a reasonable number events given the polling frequency "
      "and memory restrictions of the target platform.")

      .def(
          py::init<uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t>(),
          "   Construct the class specifying the maximum number of events for each type individually. \n"
          ":type maxBinaryEvents: unsigned short \n"
          ":type maxDoubleBinaryEvents: unsigned short \n"
          ":type maxAnalogEvents: unsigned short \n"
          ":type maxCounterEvents: unsigned short \n"
          ":type maxFrozenCounterEvents: unsigned short \n"
          ":type maxBinaryOutputStatusEvents: unsigned short \n"
          ":type maxAnalogOutputStatusEvents: unsigned short \n"
          ":type maxSecurityStatisticEvents: unsigned short",
          py::arg("maxBinaryEvents") = 0,
          py::arg("maxDoubleBinaryEvents") = 0,
          py::arg("maxAnalogEvents") = 0,
          py::arg("maxCounterEvents") = 0,
          py::arg("maxFrozenCounterEvents") = 0,
          py::arg("maxBinaryOutputStatusEvents") = 0,
          py::arg("maxAnalogOutputStatusEvents") = 0,
          py::arg("maxOctetStringEvents") = 0)

      .def_readwrite(
          "maxBinaryEvents",
          &opendnp3::EventBufferConfig::maxBinaryEvents,
          "   The number of binary events the outstation will buffer before overflowing. \n"
          ":type maxBinaryEvents: unsigned short")

      .def_readwrite(
          "maxDoubleBinaryEvents",
          &opendnp3::EventBufferConfig::maxDoubleBinaryEvents,
          "   The number of double bit binary events the outstation will buffer before overflowing. \n"
          ":type maxDoubleBinaryEvents: unsigned short")

      .def_readwrite(
          "maxAnalogEvents",
          &opendnp3::EventBufferConfig::maxAnalogEvents,
          "   The number of analog events the outstation will buffer before overflowing. \n"
          ":type : unsigned short")

      .def_readwrite(
          "maxCounterEvents",
          &opendnp3::EventBufferConfig::maxCounterEvents,
          "   The number of counter events the outstation will buffer before overflowing. \n"
          ":type maxAnalogEvents: unsigned short")

      .def_readwrite(
          "maxFrozenCounterEvents",
          &opendnp3::EventBufferConfig::maxFrozenCounterEvents,
          "   The number of frozen counter events the outstation will buffer before overflowing. \n"
          ":type maxFrozenCounterEvents: unsigned short")

      .def_readwrite(
          "maxBinaryOutputStatusEvents",
          &opendnp3::EventBufferConfig::maxBinaryOutputStatusEvents,
          "   The number of binary output status events the outstation will buffer before overflowing. \n"
          ":type maxBinaryOutputStatusEvents: unsigned short")

      .def_readwrite(
          "maxAnalogOutputStatusEvents",
          &opendnp3::EventBufferConfig::maxAnalogOutputStatusEvents,
          "   The number of analog output status events the outstation will buffer before overflowing. \n"
          ":type maxAnalogOutputStatusEvents: unsigned short")

      .def_readwrite(
          "maxOctetStringEvents",
          &opendnp3::EventBufferConfig::maxOctetStringEvents,
          "   The number of analog output status events the outstation will buffer before overflowing. \n"
          ":type maxOctetStringEvents: unsigned short")

      .def_static(
          "AllTypes",
          &opendnp3::EventBufferConfig::AllTypes,
          "   Construct the class using the same maximum for all types. This is mainly used for demo purposes. \n"
          "   You probably don't want to use this method unless your implementation actually reports every type. \n"
          ":type sizes: unsigned short",
          py::arg("sizes"))

      .def(
          "TotalEvents",
          &opendnp3::EventBufferConfig::TotalEvents,
          ":return: the sum of all event count maximums (number of elements in preallocated buffer)");
}

#endif // PYDNP3_OPENDNP3
#endif
