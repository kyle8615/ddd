#ifndef PYDNP3_OPENPAL_SERIALIZATION_SINGLEFLOAT_H
#define PYDNP3_OPENPAL_SERIALIZATION_SINGLEFLOAT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/serialization/SingleFloat.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_SingleFloat(py::module& m)
{
  // ----- class: openpal::SingleFloat -----
  py::class_<openpal::SingleFloat>(m, "SingleFloat")

      .def_static(
          "ReadBuffer",
          &openpal::SingleFloat::ReadBuffer,
          py::arg("buffer"))

      .def_static(
          "WriteBuffer",
          &openpal::SingleFloat::WriteBuffer,
          py::arg("buffer"), py::arg("value"))

      .def_static(
          "Read",
          &openpal::SingleFloat::Read,
          ":type data: unsigned char",
          py::arg("data"))

      .def_static(
          "Write",
          &openpal::SingleFloat::Write,
          ":type data: unsigned char",
          py::arg("data"), py::arg("value"))

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::SingleFloat::SIZE; })

      .def_property_readonly_static(
          "Max",
          [](py::object) { return openpal::SingleFloat::Max; })

      .def_property_readonly_static(
          "Min",
          [](py::object) { return openpal::SingleFloat::Min; });
}

#endif // PYDNP3_OPENPAL
#endif
