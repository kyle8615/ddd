#ifndef PYDNP3_OPENPAL_SERIALIZATION_PARSE_H
#define PYDNP3_OPENPAL_SERIALIZATION_PARSE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/serialization/Parse.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Parse(py::module& m)
{
  // ----- class: openpal::Parse -----
  py::class_<openpal::Parse>(m, "Parse")

      .def_static(
          "Read",
          (bool (*)(openpal::RSlice&, uint8_t&))
              & openpal::Parse::Read,
          ":type output: unsigned char",
          py::arg("input"), py::arg("output"))

      .def_static(
          "Read",
          (bool (*)(openpal::RSlice&, uint16_t&))
              & openpal::Parse::Read,
          ":type output: unsigned short",
          py::arg("input"), py::arg("output"))

      .def_static(
          "Read",
          (bool (*)(openpal::RSlice&, uint32_t&))
              & openpal::Parse::Read,
          ":type output: unsigned int",
          py::arg("input"), py::arg("output"))

      .def_static(
          "Read",
          (bool (*)(openpal::RSlice&, openpal::UInt48Type&))
              & openpal::Parse::Read,
          ":type output: opendnp3.DNPTime",
          py::arg("input"), py::arg("output"))

      .def_static(
          "Read",
          (bool (*)(openpal::RSlice&, int16_t&))
              & openpal::Parse::Read,
          ":type output: short",
          py::arg("input"), py::arg("output"))

      .def_static(
          "Read",
          (bool (*)(openpal::RSlice&, int32_t&))
              & openpal::Parse::Read,
          ":type output: int",
          py::arg("input"), py::arg("output"))

      .def_static(
          "Read",
          (bool (*)(openpal::RSlice&, double&))
              & openpal::Parse::Read,
          ":type output: double",
          py::arg("input"), py::arg("output"))

      .def_static(
          "Read",
          (bool (*)(openpal::RSlice&, float&))
              & openpal::Parse::Read,
          py::arg("input"), py::arg("output"))

      .def_static(
          "Many",
          &openpal::Parse::Many<int>)

      .def_static(
          "Many",
          &openpal::Parse::Many<opendnp3::DNPTime>)

      .def_static(
          "Many",
          &openpal::Parse::Many<int, int>)

      .def_static(
          "Many",
          &openpal::Parse::Many<int, float>)

      .def_static(
          "Many",
          &openpal::Parse::Many<int, double>)

      .def_static(
          "Many",
          &openpal::Parse::Many<int, opendnp3::DNPTime>)

      .def_static(
          "Many",
          &openpal::Parse::Many<int, int, int>)

      .def_static(
          "Many",
          &openpal::Parse::Many<int, int, opendnp3::DNPTime>)

      .def_static(
          "Many",
          &openpal::Parse::Many<int, float, opendnp3::DNPTime>)

      .def_static(
          "Many",
          &openpal::Parse::Many<int, double, opendnp3::DNPTime>)

      .def_static(
          "Many",
          &openpal::Parse::Many<opendnp3::DNPTime, int, int>);
}

#endif // PYDNP3_OPENPAL
#endif
