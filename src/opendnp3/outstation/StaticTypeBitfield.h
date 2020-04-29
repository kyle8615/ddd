#ifndef PYDNP3_OPENDNP3_OUTSTATION_STATICTYPEBITFIELD_H
#define PYDNP3_OPENDNP3_OUTSTATION_STATICTYPEBITFIELD_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/StaticTypeBitfield.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticTypeBitfield(py::module& m)
{
  // ----- struct: opendnp3::StaticTypeBitField -----
  py::class_<opendnp3::StaticTypeBitField>(m, "StaticTypeBitField",
      "A bitfield that describes a subset of all static types. \n"
      "E.g. {Binary, Analog} or {Analog, Counter, FrozenCounter}")

      .def(py::init<>())

      .def(
          py::init<uint16_t>(),
          "type mask: unsigned short",
          py::arg("mask"))

      .def_static(
          "AllTypes",
          &opendnp3::StaticTypeBitField::AllTypes)

      .def(
          "IsSet",
          &opendnp3::StaticTypeBitField::IsSet,
          py::arg("type"))

      .def(
          "Except",
          &opendnp3::StaticTypeBitField::Except,
          py::arg("type"));
}

#endif // PYDNP3_OPENDNP3
#endif
