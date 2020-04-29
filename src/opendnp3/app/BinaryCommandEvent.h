#ifndef PYDNP3_OPENDNP3_APP_BINARYCOMMANDEVENT_H
#define PYDNP3_OPENDNP3_APP_BINARYCOMMANDEVENT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/BinaryCommandEvent.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_BinaryCommandEvent(py::module& m)
{
  // ----- class: opendnp3::BinaryCommandEvent -----
  py::class_<opendnp3::BinaryCommandEvent, std::shared_ptr<opendnp3::BinaryCommandEvent>>(m, "BinaryCommandEvent",
      "Maps to Group13Var1/2.")

      .def(py::init<>())

      .def(
          py::init<opendnp3::Flags>(),
          py::arg("flags"))

      .def(
          py::init<opendnp3::Flags, opendnp3::DNPTime>(),
          py::arg("flags"), py::arg("time"))

      .def(
          py::init<bool, opendnp3::CommandStatus>(),
          py::arg("value"), py::arg("status"))

      .def(
          py::init<bool, opendnp3::CommandStatus, opendnp3::DNPTime>(),
          py::arg("value"), py::arg("status"), py::arg("time"))

      .def_readwrite(
          "value",
          &opendnp3::BinaryCommandEvent::value)

      .def_readwrite(
          "status",
          &opendnp3::BinaryCommandEvent::status)

      .def_readwrite(
          "time",
          &opendnp3::BinaryCommandEvent::time)

      .def(
          "GetFlags",
          &opendnp3::BinaryCommandEvent::GetFlags)

      .def(
          "__eq__",
          &opendnp3::BinaryCommandEvent::operator==,
          "Equality comparision.");
}

#endif // PYDNP3_OPENDNP3
#endif
