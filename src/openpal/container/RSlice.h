#ifndef PYDNP3_OPENPAL_CONTAINER_RSLICE_H
#define PYDNP3_OPENPAL_CONTAINER_RSLICE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/container/RSlice.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_RSlice(py::module& m)
{
  // ----- class: openpal::RSlice -----
  py::class_<openpal::RSlice, openpal::HasSize<uint32_t>>(m, "RSlice",
      "Represents a readonly slice of a buffer located elsewhere. \n"
      "Mediates reading from the buffer to prevent overreads and other errors.")

      .def(py::init<>())

      .def(
          py::init<uint8_t const*, uint32_t>(),
          ":type pBuffer: unsigned char \n"
          ":type size: unsigned int",
          py::arg("pBuffer"), py::arg("size"))

      .def_static(
          "Empty",
          &openpal::RSlice::Empty)

      .def(
          "Clear",
          &openpal::RSlice::Clear)

      .def(
          "CopyTo",
          &openpal::RSlice::CopyTo,
          py::arg("RSlice"))

      .def(
          "Take",
          &openpal::RSlice::Take,
          ":type count: unsigned int",
          py::arg("count"))

      .def(
          "Skip",
          &openpal::RSlice::Skip,
          ":type count: unsigned int",
          py::arg("count"))

      .def(
          "Equals",
          &openpal::RSlice::Equals,
          py::arg("RSlice"))

      .def(
          "Advance",
          &openpal::RSlice::Advance,
          ":type count: unsigned int",
          py::arg("count"));
}

#endif // PYDNP3_OPENPAL
#endif
