#ifndef PYDNP3_OPENPAL_UTIL_SEQUENCENUM_H
#define PYDNP3_OPENPAL_UTIL_SEQUENCENUM_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/util/SequenceNum.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <class T, T Modulus>
void declareSequenceNum(py::module& m, string const& type)
{
  // ----- class: openpal::SequenceNum<T, Modulus> -----
  py::class_<openpal::SequenceNum<T, Modulus>>(m, ("SequenceNum" + type).c_str(),
      "Represents a sequence number.")

      .def(py::init<>())

      .def(
          py::init<T>(),
          py::arg("sequence"))

      .def(
          "Get",
          &openpal::SequenceNum<T, Modulus>::Get)

      .def(
          "Equals",
          &openpal::SequenceNum<T, Modulus>::Equals,
          py::arg("other"))

      .def(
          "Increment",
          &openpal::SequenceNum<T, Modulus>::Increment)

      .def(
          "Reset",
          &openpal::SequenceNum<T, Modulus>::Reset)

      .def(
          "Next",
          (openpal::SequenceNum<T, Modulus>(openpal::SequenceNum<T, Modulus>::*)() const)
              & openpal::SequenceNum<T, Modulus>::Next);
}

void bind_SequenceNum(py::module& m)
{
  declareSequenceNum<uint8_t, 2>(m, "Uint8");
}

#endif // PYDNP3_OPENPAL
#endif
