#ifndef PYDNP3_OPENPAL_SERIALIZATION_DOUBLEFLOAT_H
#define PYDNP3_OPENPAL_SERIALIZATION_DOUBLEFLOAT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/serialization/DoubleFloat.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_DoubleFloat(py::module& m)
{
  // ----- class: openpal::DoubleFloat -----
  py::class_<openpal::DoubleFloat>(m, "DoubleFloat")

      .def_static(
          "ReadBuffer",
          &openpal::DoubleFloat::ReadBuffer,
          py::arg("buffer"))

      .def_static(
          "WriteBuffer",
          &openpal::DoubleFloat::WriteBuffer,
          ":type value: double",
          py::arg("buffer"), py::arg("value"))

      .def_static(
          "Read",
          &openpal::DoubleFloat::Read,
          ":type data: unsigned char",
          py::arg("data"))

      .def_static(
          "Write",
          &openpal::DoubleFloat::Write,
          ":type data: unsigned char \n"
          ":type value: double",
          py::arg("data"), py::arg("value"))

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::DoubleFloat::SIZE; })

      .def_property_readonly_static(
          "Max",
          [](py::object) { return openpal::DoubleFloat::Max; })

      .def_property_readonly_static(
          "Min",
          [](py::object) { return openpal::DoubleFloat::Min; });
}

#endif // PYDNP3_OPENPAL
#endif
