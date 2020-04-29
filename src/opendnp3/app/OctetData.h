#ifndef PYDNP3_OPENDNP3_APP_OCTETDATA_H
#define PYDNP3_OPENDNP3_APP_OCTETDATA_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/OctetData.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_OctetData(py::module& m)
{
  // ----- class: opendnp3::OctetData -----
  py::class_<opendnp3::OctetData, std::shared_ptr<opendnp3::OctetData>>(m, "OctetData",
      "A base-class for bitstrings containing up to 255 bytes")

      .def(py::init<>())

      .def(
          py::init<const openpal::RSlice&>(),
          py::arg("input"))

      .def(
          py::init<const char*>(),
          py::arg("input"))

      .def(
          "Set",
          (bool (opendnp3::OctetData::*)(const openpal::RSlice&))
              & opendnp3::OctetData::Set,
          py::arg("input"))

      .def(
          "Set",
          (bool (opendnp3::OctetData::*)(const char*))
              & opendnp3::OctetData::Set,
          py::arg("input"))

      .def(
          "ToRSlice",
          &opendnp3::OctetData::ToRSlice)

      .def_property_readonly_static(
          "MAX_SIZE",
          [](py::object) { return opendnp3::OctetData::MAX_SIZE; });
}

#endif // PYDNP3_OPENDNP3
#endif
