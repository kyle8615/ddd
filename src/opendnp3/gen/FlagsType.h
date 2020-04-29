#ifndef PYDNP3_OPENDNP3_GEN_FLAGSTYPE_H
#define PYDNP3_OPENDNP3_GEN_FLAGSTYPE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/FlagsType.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_FlagsType(py::module& m)
{
  // ----- enum class: opendnp3::FlagsType -----
  py::enum_<opendnp3::FlagsType>(m, "FlagsType",
      "Enumerates all types that have flags.")

      .value("DoubleBinaryInput", opendnp3::FlagsType::DoubleBinaryInput)
      .value("Counter", opendnp3::FlagsType::Counter)
      .value("FrozenCounter", opendnp3::FlagsType::FrozenCounter)
      .value("AnalogInput", opendnp3::FlagsType::AnalogInput)
      .value("BinaryOutputStatus", opendnp3::FlagsType::BinaryOutputStatus)
      .value("AnalogOutputStatus", opendnp3::FlagsType::AnalogOutputStatus)
      .value("BinaryInput", opendnp3::FlagsType::BinaryInput);

  // ----- function: opendnp3::FlagsBitToType -----
  m.def(
      "FlagsTypeToType",
      &opendnp3::FlagsTypeToType,
      py::arg("flagsType"));

  // ----- function: opendnp3::FlagsBitFromType -----
  m.def(
      "FlagsTypeFromType",
      &opendnp3::FlagsTypeFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::FlagsBitToString -----
  m.def(
      "FlagsTypeToString",
      &opendnp3::FlagsTypeToString,
      py::arg("flagsType"));
}

#endif // PYDNP3_OPENDNP3
#endif
