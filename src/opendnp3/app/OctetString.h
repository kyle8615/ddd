#ifndef PYDNP3_OPENDNP3_APP_OCTETSTRING_H
#define PYDNP3_OPENDNP3_APP_OCTETSTRING_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/OctetString.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_OctetString(py::module& m)
{
  // ----- class: opendnp3::OctetString -----
  py::class_<opendnp3::OctetString, opendnp3::OctetData, std::shared_ptr<opendnp3::OctetString>>(m, "OctetString",
      "Respresents group 110/111 objects.")

      .def(py::init<>())

      .def(
          py::init<const opendnp3::OctetString&>(),
          py::arg("data"))

      .def(
          py::init<const char*>(),
          py::arg("input"))

      .def(
          py::init<const openpal::RSlice&>(),
          py::arg("buffer"));
}

#endif // PYDNP3_OPENDNP3
#endif
