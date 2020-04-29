#ifndef PYDNP3_ASIODNP3_DEFAULTMASTERAPPLICATION_H
#define PYDNP3_ASIODNP3_DEFAULTMASTERAPPLICATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/DefaultMasterApplication.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_DefaultMasterApplication(py::module& m)
{
  // ----- class: asiodnp3::DefaultMasterApplication -----
  py::class_<asiodnp3::DefaultMasterApplication,
      opendnp3::IMasterApplication,
      std::shared_ptr<asiodnp3::DefaultMasterApplication>>(m, "DefaultMasterApplication")

      .def(py::init<>())

      .def_static(
          "Create",
          &asiodnp3::DefaultMasterApplication::Create,
          ":return: shared_ptr to opendnp3.IMasterApplication")

      .def(
          "OnReceiveIIN",
          &asiodnp3::DefaultMasterApplication::OnReceiveIIN,
          "Called when a response or unsolicited response is receive from the outstation.",
          py::arg("iin"))

      .def(
          "OnTaskStart",
          &asiodnp3::DefaultMasterApplication::OnTaskStart,
          "Task start notification.",
          py::arg("type"), py::arg("id"))

      .def(
          "OnTaskComplete",
          &asiodnp3::DefaultMasterApplication::OnTaskComplete,
          "Task completion notification.",
          py::arg("info"))

      .def(
          "AssignClassDuringStartup",
          &asiodnp3::DefaultMasterApplication::AssignClassDuringStartup)

      .def(
          "ConfigureAssignClassRequest",
          &asiodnp3::DefaultMasterApplication::ConfigureAssignClassRequest,
          "Configure the request headers for assign class. \n"
          "Only called if AssignClassDuringStartup returns true. \n"
          "The user only needs to call the function for each header type to be written.",
          py::arg("fun"))

      .def(
          "Now",
          &asiodnp3::DefaultMasterApplication::Now,
          ":return: a UTCTimestamp of the current time")

      .def(
          "OnStateChange",
          &asiodnp3::DefaultMasterApplication::OnStateChange,
          "Called when a the reset/unreset status of the link layer changes.",
          py::arg("value"));
}

#endif // PYDNP3_ASIODNP3
#endif
