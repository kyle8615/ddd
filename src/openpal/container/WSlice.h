#ifndef PYDNP3_OPENPAL_CONTAINER_WSLICE_H
#define PYDNP3_OPENPAL_CONTAINER_WSLICE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/container/WSlice.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_WSlice(py::module& m)
{
  // ----- class: openpal::WSlice -----
  py::class_<openpal::WSlice, openpal::HasSize<uint32_t>>(m, "WSlice",
      "Represents a write-able slice of a buffer located elsewhere. \n"
      "Mediates writing to the buffer to prevent overruns and other errors.")

      .def(py::init<>())

      .def(
          py::init<uint8_t*, uint32_t>(),
          ":type pBuffer: unsigned char \n"
          ":type size: unsigned int",
          py::arg("pBuffer"), py::arg("size"))

      .def_static(
          "Empty",
          &openpal::WSlice::Empty)

      .def(
          "SetAllTo",
          &openpal::WSlice::SetAllTo,
          ":type value: unsgined char",
          py::arg("value"))

      .def(
          "Clear",
          &openpal::WSlice::Clear)

      .def(
          "Advance",
          &openpal::WSlice::Advance,
          ":type count: unsigned int",
          py::arg("count"))

      .def(
          "Skip",
          &openpal::WSlice::Skip,
          ":type count: unsigned int",
          py::arg("count"))

      .def(
          "ToRSlice",
          &openpal::WSlice::ToRSlice);
}

#endif // PYDNP3_OPENPALs
#endif
