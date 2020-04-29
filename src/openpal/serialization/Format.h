#ifndef PYDNP3_OPENPAL_SERIALIZATION_FORMAT_H
#define PYDNP3_OPENPAL_SERIALIZATION_FORMAT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/serialization/Format.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Format(py::module& m)
{
  // ----- class: openpal::Format -----
  py::class_<openpal::Format>(m, "Format")

      .def_static(
          "Write",
          (bool (*)(openpal::WSlice&, const uint8_t&))
              & openpal::Format::Write,
          ":type value: unsigned char",
          py::arg("dest"), py::arg("value"))

      .def_static(
          "Write",
          (bool (*)(openpal::WSlice&, const uint16_t&))
              & openpal::Format::Write,
          ":type value: unsigned short",
          py::arg("dest"), py::arg("value"))

      .def_static(
          "Write",
          (bool (*)(openpal::WSlice&, const uint32_t&))
              & openpal::Format::Write,
          ":type value: unsigned int",
          py::arg("dest"), py::arg("value"))

      .def_static(
          "Write",
          (bool (*)(openpal::WSlice&, const openpal::UInt48Type&))
              & openpal::Format::Write,
          ":type value: opendnp3.DNPTime",
          py::arg("dest"), py::arg("value"))

      .def_static(
          "Write",
          (bool (*)(openpal::WSlice&, const int16_t&))
              & openpal::Format::Write,
          ":type value: short",
          py::arg("dest"), py::arg("value"))

      .def_static(
          "Write",
          (bool (*)(openpal::WSlice&, const int32_t&))
              & openpal::Format::Write,
          ":type value: int",
          py::arg("dest"), py::arg("value"))

      .def_static(
          "Write",
          (bool (*)(openpal::WSlice&, const double&))
              & openpal::Format::Write,
          ":type value: double",
          py::arg("dest"), py::arg("value"))

      .def_static(
          "Write",
          (bool (*)(openpal::WSlice&, const float&))
              & openpal::Format::Write,
          py::arg("dest"), py::arg("value"))

      .def_static(
          "Many",
          &openpal::Format::Many<int>)

      .def_static(
          "Many",
          &openpal::Format::Many<int, int>)

      .def_static(
          "Many",
          &openpal::Format::Many<int, float>)

      .def_static(
          "Many",
          &openpal::Format::Many<int, double>)

      .def_static(
          "Many",
          &openpal::Format::Many<int, opendnp3::DNPTime>)

      .def_static(
          "Many",
          &openpal::Format::Many<int, int, int>)

      .def_static(
          "Many",
          &openpal::Format::Many<int, int, opendnp3::DNPTime>)

      .def_static(
          "Many",
          &openpal::Format::Many<int, float, opendnp3::DNPTime>)

      .def_static(
          "Many",
          &openpal::Format::Many<int, double, opendnp3::DNPTime>)

      .def_static(
          "Many",
          &openpal::Format::Many<int, int, int, opendnp3::DNPTime>);
}

#endif // PYDNP3_OPENPAL
#endif
