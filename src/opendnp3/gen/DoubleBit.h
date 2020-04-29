#ifndef PYDNP3_OPENDNP3_GEN_DOUBLEBIT_H
#define PYDNP3_OPENDNP3_GEN_DOUBLEBIT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/DoubleBit.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_DoubleBit(py::module& m)
{
  // ----- enum class: opendnp3::DoubleBit -----
  py::enum_<opendnp3::DoubleBit>(m, "DoubleBit",
      "Enumeration for possible states of a double bit value.")

      .value(
          "INTERMEDIATE",
          opendnp3::DoubleBit::INTERMEDIATE,
          "Transitioning between end conditions.")

      .value(
          "DETERMINED_OFF",
          opendnp3::DoubleBit::DETERMINED_OFF,
          "End condition, determined to be OFF.")

      .value(
          "DETERMINED_ON",
          opendnp3::DoubleBit::DETERMINED_ON,
          "End condition, determined to be ON.")

      .value(
          "INDETERMINATE",
          opendnp3::DoubleBit::INDETERMINATE,
          "Abnormal or custom condition");

  // ----- function: opendnp3::DoubleBitToType -----
  m.def(
      "DoubleBitToType",
      &opendnp3::DoubleBitToType,
      py::arg("db"));

  // ----- function: opendnp3::DoubleBitFromType -----
  m.def(
      "DoubleBitFromType",
      &opendnp3::DoubleBitFromType,
      "type rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::DoubleBitToString -----
  m.def(
      "DoubleBitToString",
      &opendnp3::DoubleBitToString,
      py::arg("db"));
}

#endif // PYDNP3_OPENDNP3
#endif
