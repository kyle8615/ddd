#ifndef PYDNP3_OPENPAL_CONTAINER_SETTABLE_H
#define PYDNP3_OPENPAL_CONTAINER_SETTABLE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/container/Settable.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <class T>
void declareSettable(py::module& m, std::string const& type)
{
  // ----- class: openpal::Settable<T> -----
  py::class_<openpal::Settable<T>>(m, ("Settable" + type).c_str(),
      "Utility class for representing a value that may or may not be set.")

      .def(py::init<>())

      .def(
          "IsSet",
          &openpal::Settable<T>::IsSet)

      .def(
          "IsEmpty",
          &openpal::Settable<T>::IsEmpty)

      .def(
          "Get",
          &openpal::Settable<T>::Get)

      .def(
          "Pop",
          &openpal::Settable<T>::Pop,
          py::arg("output"))

      .def(
          "Clear",
          &openpal::Settable<T>::Clear)

      .def(
          "Set",
          &openpal::Settable<T>::Set,
          py::arg("value"));
}

void bind_Settable(py::module& m)
{
  declareSettable<openpal::RSlice>(m, "RSlice");
  declareSettable<openpal::WSlice>(m, "WSlice");
}

#endif // PYDNP3_OPENPAL
#endif
