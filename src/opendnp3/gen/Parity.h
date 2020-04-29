#ifndef PYDNP3_OPENDNP3_GEN_PARITY_H
#define PYDNP3_OPENDNP3_GEN_PARITY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/Parity.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_Parity(py::module& m)
{
  // ----- enum class: opendnp3::Parity -----
  py::enum_<opendnp3::Parity>(m, "Parity",
      "Enumeration for setting serial port parity.")

      .value("Even", opendnp3::Parity::Even)
      .value("Odd", opendnp3::Parity::Odd)
      .value("None", opendnp3::Parity::None);

  // ----- func: opendnp3::ParityToType -----
  m.def(
      "ParityToType",
      &opendnp3::ParityToType,
      py::arg("parity"));

  // ----- func: opendnp3::ParityFromType -----
  m.def(
      "ParityFromType",
      &opendnp3::ParityFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- func: opendnp3::ParityToString -----
  m.def(
      "ParityToString",
      &opendnp3::ParityToString,
      py::arg("parity"));
}

#endif // PYDNP3_OPENDNP3
#endif
