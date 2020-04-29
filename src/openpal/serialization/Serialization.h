#ifndef PYDNP3_OPENPAL_SERIALIZATION_SERIALIZATION_H
#define PYDNP3_OPENPAL_SERIALIZATION_SERIALIZATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/serialization/Serialization.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Serialization(py::module& m)
{
  // ----- class: openpal::Int16 -----
  py::class_<openpal::Int16>(m, "Int16")

      .def_static(
          "Read",
          &openpal::Int16::Read,
          ":type data: unsigned char",
          py::arg("data"))

      .def_static(
          "Write",
          &openpal::Int16::Write,
          ":type data: unsigned char \n"
          ":type value: short",
          py::arg("data"), py::arg("value"))

      .def_static(
          "WriteBuffer",
          &openpal::Int16::WriteBuffer,
          ":type aValue: short",
          py::arg("buffer"), py::arg("aValue"))

      .def_static(
          "ReadBuffer",
          &openpal::Int16::ReadBuffer,
          py::arg("arBuffer"))

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::Int16::SIZE; })

      .def_property_readonly_static(
          "Max",
          [](py::object) { return openpal::Int16::Max; })

      .def_property_readonly_static(
          "Min",
          [](py::object) { return openpal::Int16::Min; });

  // ----- class: openpal::UInt16 -----
  py::class_<openpal::UInt16>(m, "UInt16")

      .def_static(
          "Read",
          &openpal::UInt16::Read,
          ":type data: unsigned char",
          py::arg("data"))

      .def_static(
          "Write",
          &openpal::UInt16::Write,
          ":type data: unsigned char \n"
          ":type value: unsigned short",
          py::arg("data"), py::arg("value"))

      .def_static(
          "WriteBuffer",
          &openpal::UInt16::WriteBuffer,
          ":type aValue: unsigned short",
          py::arg("buffer"), py::arg("aValue"))

      .def_static(
          "ReadBuffer",
          &openpal::UInt16::ReadBuffer,
          py::arg("arBuffer"))

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::UInt16::SIZE; })

      .def_property_readonly_static(
          "Max",
          [](py::object) { return openpal::UInt16::Max; })

      .def_property_readonly_static(
          "Min",
          [](py::object) { return openpal::UInt16::Min; });

  // ----- class: openpal::Int32 -----
  py::class_<openpal::Int32>(m, "Int32")

      .def_static(
          "Read",
          &openpal::Int32::Read,
          ":type data: unsigned char",
          py::arg("data"))

      .def_static(
          "Write",
          &openpal::Int32::Write,
          ":type data: unsigned char \n"
          ":type value: short",
          py::arg("data"), py::arg("value"))

      .def_static(
          "WriteBuffer",
          &openpal::Int32::WriteBuffer,
          ":type aValue: short",
          py::arg("buffer"), py::arg("aValue"))

      .def_static(
          "ReadBuffer",
          &openpal::Int32::ReadBuffer,
          py::arg("buffer"))

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::Int32::SIZE; })

      .def_property_readonly_static(
          "Max",
          [](py::object) { return openpal::Int32::Max; })

      .def_property_readonly_static(
          "Min",
          [](py::object) { return openpal::Int32::Min; });

  // ----- class: openpal::UInt32 -----
  py::class_<openpal::UInt32>(m, "UInt32")

      .def_static(
          "Read",
          &openpal::UInt32::Read,
          ":type data: unsigned char",
          py::arg("data"))

      .def_static(
          "Write",
          &openpal::UInt32::Write,
          ":type data: unsigned char \n"
          ":type value: unsigned short",
          py::arg("data"), py::arg("value"))

      .def_static(
          "WriteBuffer",
          &openpal::UInt32::WriteBuffer,
          ":type aValue: unsigned short",
          py::arg("buffer"), py::arg("aValue"))

      .def_static(
          "ReadBuffer",
          &openpal::UInt32::ReadBuffer,
          py::arg("buffer"))

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::UInt32::SIZE; })

      .def_property_readonly_static(
          "Max",
          [](py::object) { return openpal::UInt32::Max; })

      .def_property_readonly_static(
          "Min",
          [](py::object) { return openpal::UInt32::Min; });

  // ----- class: openpal::UInt48 -----
  py::class_<openpal::UInt48>(m, "UInt48")

      .def_static(
          "Read",
          &openpal::UInt48::Read,
          ":type data: unsigned char",
          py::arg("data"))

      .def_static(
          "Write",
          &openpal::UInt48::Write,
          ":type data: unsigned char \n"
          ":type value: opendnp3.DNPTime",
          py::arg("data"), py::arg("value"))

      .def_static(
          "ReadBuffer",
          &openpal::UInt48::ReadBuffer,
          py::arg("buffer"))

      .def_static(
          "WriteBuffer",
          &openpal::UInt48::WriteBuffer,
          ":type value: opendnp3.DNPTime",
          py::arg("buffer"), py::arg("value"))

      .def_property_readonly_static(
          "MAX",
          [](py::object) { return openpal::UInt48::MAX; })

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::UInt48::SIZE; });

  // ----- class: openpal::UInt8 -----
  py::class_<openpal::UInt8>(m, "UInt8")

      .def(py::init<>())

      .def_static(
          "Read",
          &openpal::UInt8::Read,
          ":type pStart: unsigned char",
          py::arg("pStart"))

      .def_static(
          "ReadBuffer",
          &openpal::UInt8::ReadBuffer,
          py::arg("buffer"))

      .def_static(
          "WriteBuffer",
          &openpal::UInt8::WriteBuffer,
          ":type value: unsigned short",
          py::arg("buffer"), py::arg("value"))

      .def_static(
          "Write",
          &openpal::UInt8::Write,
          ":type pStart: unsigned char \n"
          ":type value: unsigned char",
          py::arg("pStart"), py::arg("value"))

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::UInt8::SIZE; })

      .def_property_readonly_static(
          "Max",
          [](py::object) { return openpal::UInt8::Max; })

      .def_property_readonly_static(
          "Min",
          [](py::object) { return openpal::UInt8::Min; });
}

#endif // PYDNP3_OPENPAL
#endif
