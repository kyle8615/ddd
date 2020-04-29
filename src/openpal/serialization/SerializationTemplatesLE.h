#ifndef PYDNP3_OPENPAL_SERIALIZATION_SERIALIZATIONTEMPLATESLE_H
#define PYDNP3_OPENPAL_SERIALIZATION_SERIALIZATIONTEMPLATESLE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/serialization/SerializationTemplatesLE.h>

#ifdef PYDNP3_OPENPAL

template <class T>
void declareBit16LE(py::module& m, string const& type)
{
  // ----- class: openpal::Bit16LE<T> -----
  py::class_<openpal::Bit16LE<T>>(m, ("Bit16LE" + type).c_str())

      .def_static(
          "Read",
          &openpal::Bit16LE<T>::Read,
          ":type data: unsigned char",
          py::arg("data"))

      .def_static(
          "Write",
          &openpal::Bit16LE<T>::Write,
          ":type data: unsigned char",
          py::arg("data"), py::arg("value"))

      .def_static(
          "WriteBuffer",
          &openpal::Bit16LE<T>::WriteBuffer,
          py::arg("buffer"), py::arg("aValue"))

      .def_static(
          "ReadBuffer",
          &openpal::Bit16LE<T>::ReadBuffer,
          py::arg("arBuffer"))

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::Bit16LE<T>::SIZE; })

      .def_property_readonly_static(
          "Max",
          [](py::object) { return openpal::Bit16LE<T>::Max; })

      .def_property_readonly_static(
          "Min",
          [](py::object) { return openpal::Bit16LE<T>::Min; });
}

template <class T>
void declareBit32LE(py::module& m, string const& type)
{
  // ----- class: openpal::Bit32LE<T> -----
  py::class_<openpal::Bit32LE<T>>(m, ("Bit32LE" + type).c_str())

      .def_static(
          "Read",
          &openpal::Bit32LE<T>::Read,
          ":type data: unsigned char",
          py::arg("data"))

      .def_static(
          "Write",
          &openpal::Bit32LE<T>::Write,
          ":type data: unsigned char",
          py::arg("data"), py::arg("value"))

      .def_static(
          "WriteBuffer",
          &openpal::Bit32LE<T>::WriteBuffer,
          py::arg("buffer"), py::arg("aValue"))

      .def_static(
          "ReadBuffer",
          &openpal::Bit32LE<T>::ReadBuffer,
          py::arg("buffer"))

      .def_property_readonly_static(
          "SIZE",
          [](py::object) { return openpal::Bit32LE<T>::SIZE; })

      .def_property_readonly_static(
          "Max",
          [](py::object) { return openpal::Bit32LE<T>::Max; })

      .def_property_readonly_static(
          "Min",
          [](py::object) { return openpal::Bit32LE<T>::Min; });
}

void bind_SerializationTemplatesLE(py::module& m)
{
}

#endif // PYDNP3_OPENPAL
#endif
