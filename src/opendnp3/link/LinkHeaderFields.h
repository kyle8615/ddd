#ifndef PYDNP3_OPENDNP3_LINK_LINKHEADERFIELDS_H
#define PYDNP3_OPENDNP3_LINK_LINKHEADERFIELDS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/link/LinkHeaderFields.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_LinkHeaderFields(py::module& m)
{
  // ----- struct: opendnp3::LinkHeaderFields -----
  py::class_<opendnp3::LinkHeaderFields>(m, "LinkHeaderFields")

      .def(py::init<>())

      .def(
          py::init<opendnp3::LinkFunction, bool, bool, bool, uint16_t, uint16_t>(),
          ":type dest: unsigned short \n"
          ":type src: unsigned short",
          py::arg("func"), py::arg("isMaster"), py::arg("fcb"), py::arg("fcvdfc"), py::arg("dest"), py::arg("src"))

      .def(
          "ToAddresses",
          &opendnp3::LinkHeaderFields::ToAddresses,
          "Dnp3 address pair.")

      .def_readwrite(
          "func",
          &opendnp3::LinkHeaderFields::func)

      .def_readwrite(
          "isFromMaster",
          &opendnp3::LinkHeaderFields::isFromMaster)

      .def_readwrite(
          "fcb",
          &opendnp3::LinkHeaderFields::fcb)

      .def_readwrite(
          "fcvdfc",
          &opendnp3::LinkHeaderFields::fcvdfc)

      .def_readwrite(
          "dest",
          &opendnp3::LinkHeaderFields::dest,
          ":type dest: unsigned short")

      .def_readwrite(
          "src",
          &opendnp3::LinkHeaderFields::src,
          ":type src: unsigned short");
}

#endif // PYDNP3_OPENDNP3
#endif
