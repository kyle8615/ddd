#ifndef PYDNP3_OPENPAL_CONTAINER_BUFFER_H
#define PYDNP3_OPENPAL_CONTAINER_BUFFER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/container/Buffer.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Buffer(py::module& m)
{
  // ----- class: openpal::Buffer -----
  py::class_<openpal::Buffer, openpal::Array<uint8_t, uint32_t>>(m, "Buffer")

      .def(py::init<>())

      .def(
          py::init<uint32_t>(),
          ":type size: unsigned int",
          py::arg("size"))

      .def(
          py::init<const openpal::RSlice&>(),
          "Initialize with the exact size and contents of the view.")

      .def(
          "ToRSlice",
          &openpal::Buffer::ToRSlice)

      .def(
          "GetWSlice",
          (openpal::WSlice(openpal::Buffer::*)())
              & openpal::Buffer::GetWSlice)

      .def(
          "GetWSlice",
          (openpal::WSlice(openpal::Buffer::*)(uint32_t))
              & openpal::Buffer::GetWSlice,
          ":type maxSize: unsigned int",
          py::arg("maxSize"))

      .def(
          "__call__",
          (const uint8_t* (openpal::Buffer::*)() const)
              & openpal::Buffer::operator(),
          py::return_value_policy::automatic)

      .def(
          "__call__",
          (uint8_t * (openpal::Buffer::*)())
              & openpal::Buffer::operator(),
          py::return_value_policy::automatic);
}

#endif // PYDNP3_OPENPAL
#endif
