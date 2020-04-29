#ifndef PYDNP3_OPENDNP3_APP_ANALOGCOMMANDEVENT_H
#define PYDNP3_OPENDNP3_APP_ANALOGCOMMANDEVENT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/AnalogCommandEvent.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_AnalogCommandEvent(py::module& m)
{
  // ----- class: opendnp3::AnalogCommandEvent -----
  py::class_<opendnp3::AnalogCommandEvent, std::shared_ptr<opendnp3::AnalogCommandEvent>>(m, "AnalogCommandEvent",
      "Occurs when an outstation receives and analog command. Maps to Group43.")

      .def(py::init<>())

      .def(
          py::init<double, opendnp3::CommandStatus>(),
          ":type value: double",
          py::arg("value"), py::arg("status"))

      .def(
          py::init<double, opendnp3::CommandStatus, opendnp3::DNPTime>(),
          ":type value: double",
          py::arg("value"), py::arg("status"), py::arg("time"))

      .def_readwrite(
          "value",
          &opendnp3::AnalogCommandEvent::value,
          ":type value: double")

      .def_readwrite(
          "status",
          &opendnp3::AnalogCommandEvent::status)

      .def_readwrite(
          "time",
          &opendnp3::AnalogCommandEvent::time)

      .def(
          "__eq__",
          &opendnp3::AnalogCommandEvent::operator==,
          "Equality comparision.");
}

#endif // PYDNP3_OPENDNP3
#endif
