#ifndef PYDNP3_OPENDNP3_GEN_STOPBITS_H
#define PYDNP3_OPENDNP3_GEN_STOPBITS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StopBits.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StopBits(py::module& m)
{
  // ----- enum class: opendnp3::StopBits
  py::enum_<opendnp3::StopBits>(m, "StopBits",
      "Enumeration for setting serial port stop bits.")

      .value("One", opendnp3::StopBits::One)
      .value("OnePointFive", opendnp3::StopBits::OnePointFive)
      .value("Two", opendnp3::StopBits::Two)
      .value("None", opendnp3::StopBits::None);

  // ----- func: opendnp3::StopBitsToType -----
  m.def(
      "StopBitsToType",
      &opendnp3::StopBitsToType,
      py::arg("stopBits"));

  // ----- func: opendnp3::StopBitsFromType -----
  m.def(
      "StopBitsFromType",
      &opendnp3::StopBitsFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- func: opendnp3::StopBitsToString -----
  m.def(
      "StopBitsToString",
      &opendnp3::StopBitsToString,
      py::arg("stopBits"));
}

#endif // PYDNP3_OPENDNP3
#endif
