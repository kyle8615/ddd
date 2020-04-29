#ifndef PYDNP3_OPENDNP3_GEN_STATICTYPEBITMASK_H
#define PYDNP3_OPENDNP3_GEN_STATICTYPEBITMASK_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticTypeBitmask.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticTypeBitmask(py::module& m)
{
  // ----- enum class: opendnp3::StaticTypeBitmask
  py::enum_<opendnp3::StaticTypeBitmask>(m, "StaticTypeBitmask")
      .value("BinaryInput", opendnp3::StaticTypeBitmask::BinaryInput)
      .value("DoubleBinaryInput", opendnp3::StaticTypeBitmask::DoubleBinaryInput)
      .value("Counter", opendnp3::StaticTypeBitmask::Counter)
      .value("FrozenCounter", opendnp3::StaticTypeBitmask::FrozenCounter)
      .value("AnalogInput", opendnp3::StaticTypeBitmask::AnalogInput)
      .value("BinaryOutputStatus", opendnp3::StaticTypeBitmask::BinaryOutputStatus)
      .value("AnalogOutputStatus", opendnp3::StaticTypeBitmask::AnalogOutputStatus)
      .value("TimeAndInterval", opendnp3::StaticTypeBitmask::TimeAndInterval)
      .value("OctetString", opendnp3::StaticTypeBitmask::OctetString);
}

#endif // PYDNP3_OPENDNP3
#endif
