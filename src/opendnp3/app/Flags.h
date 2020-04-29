#ifndef PYDNP3_OPENDNP3_APP_FLAGS_H
#define PYDNP3_OPENDNP3_APP_FLAGS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/Flags.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_Flags(py::module& m)
{
  // ----- class: opendnp3::Flags -----
  py::class_<opendnp3::Flags>(m, "Flags",
      "Measurement Flags.")

      .def(
          py::init<uint8_t>(),
          ":param value: defaults to 0 \n"
          ":type value: unsigned char",
          py::arg("value") = 0)

      .def_readwrite(
          "value",
          &opendnp3::Flags::value,
          ":type value: unsigned char")

      .def(
          "IsSet",
          (bool (opendnp3::Flags::*)(opendnp3::BinaryQuality) const)
              & opendnp3::Flags::IsSet,
          py::arg("flag"))

      .def(
          "IsSet",
          (bool (opendnp3::Flags::*)(opendnp3::AnalogQuality) const)
              & opendnp3::Flags::IsSet,
          py::arg("flag"))

      .def(
          "IsSet",
          (bool (opendnp3::Flags::*)(opendnp3::CounterQuality) const)
              & opendnp3::Flags::IsSet,
          py::arg("flag"))

      .def(
          "IsSet",
          (bool (opendnp3::Flags::*)(opendnp3::FrozenCounterQuality) const)
              & opendnp3::Flags::IsSet,
          py::arg("flag"))

      .def(
          "IsSet",
          (bool (opendnp3::Flags::*)(opendnp3::BinaryOutputStatusQuality) const)
              & opendnp3::Flags::IsSet,
          py::arg("flag"))

      .def(
          "IsSet",
          (bool (opendnp3::Flags::*)(opendnp3::AnalogOutputStatusQuality) const)
              & opendnp3::Flags::IsSet,
          py::arg("flag"))

      .def(
          "Set",
          (void (opendnp3::Flags::*)(opendnp3::BinaryQuality))
              & opendnp3::Flags::Set,
          py::arg("flag"))

      .def(
          "Set",
          (void (opendnp3::Flags::*)(opendnp3::AnalogQuality))
              & opendnp3::Flags::Set,
          py::arg("flag"))

      .def(
          "Set",
          (void (opendnp3::Flags::*)(opendnp3::CounterQuality))
              & opendnp3::Flags::Set,
          py::arg("flag"))

      .def(
          "Set",
          (void (opendnp3::Flags::*)(opendnp3::FrozenCounterQuality))
              & opendnp3::Flags::Set,
          py::arg("flag"))

      .def(
          "Set",
          (void (opendnp3::Flags::*)(opendnp3::BinaryOutputStatusQuality))
              & opendnp3::Flags::Set,
          py::arg("flag"))

      .def(
          "Set",
          (void (opendnp3::Flags::*)(opendnp3::AnalogOutputStatusQuality))
              & opendnp3::Flags::Set,
          py::arg("flag"));
}

#endif // PYDNP3_OPENDNP3
#endif
