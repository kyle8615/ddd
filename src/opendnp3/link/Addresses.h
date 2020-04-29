#ifndef PYDNP3_OPENDNP3_LINK_ADDRESSES_H
#define PYDNP3_OPENDNP3_LINK_ADDRESSES_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/link/Addresses.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_Addresses(py::module& m)
{
  // ----- class: opendnp3::Addresses -----
  py::class_<opendnp3::Addresses>(m, "Addresses",
      "DNP3 address wrapping.")

      .def(
          py::init<uint16_t, uint16_t>(),
          ":constructor.",
          py::arg("source") = 0xFF, py::arg("destination") = 0xFF)

      .def(
          "__eq__",
          (bool (opendnp3::Addresses::*)(const opendnp3::Addresses&))
              & opendnp3::Addresses::operator==)

      .def(
          "__ne__",
          (bool (opendnp3::Addresses::*)(const opendnp3::Addresses&))
              & opendnp3::Addresses::operator!=)

      .def_readwrite(
          "source",
          &opendnp3::Addresses::source,
          "DNP3 address source")

      .def_readwrite(
          "destination",
          &opendnp3::Addresses::destination,
          "DNP3 address destination.");
}

#endif // PYDNP3_OPENDNP3
#endif
