#ifndef PYDNP3_OPENDNP3_APP_EVENTTYPE_H
#define PYDNP3_OPENDNP3_APP_EVENTTYPE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/EventType.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventType(py::module& m)
{
  // ----- enum class: opendnp3::EventType -----
  py::enum_<opendnp3::EventType>(m, "EventType")
      .value("Binary", opendnp3::EventType::Binary)
      .value("Analog", opendnp3::EventType::Analog)
      .value("Counter", opendnp3::EventType::Counter)
      .value("FrozenCounter", opendnp3::EventType::FrozenCounter)
      .value("DoubleBitBinary", opendnp3::EventType::DoubleBitBinary)
      .value("BinaryOutputStatus", opendnp3::EventType::BinaryOutputStatus)
      .value("AnalogOutputStatus", opendnp3::EventType::AnalogOutputStatus)
      .value("OctetString", opendnp3::EventType::OctetString);

  // ----- enum class: opendnp3::EventClass -----
  py::enum_<opendnp3::EventClass>(m, "EventClass")
      .value("EC1", opendnp3::EventClass::EC1)
      .value("EC2", opendnp3::EventClass::EC2)
      .value("EC3", opendnp3::EventClass::EC3);
}

#endif // PYDNP3_OPENDNP3
#endif
