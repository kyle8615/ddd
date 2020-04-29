#ifndef PYDNP3_OPENDNP3_MASTER_TASKCONFIG_H
#define PYDNP3_OPENDNP3_MASTER_TASKCONFIG_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/TaskConfig.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_TaskConfig(py::module& m)
{
  // ----- class: opendnp3::TaskConfig -----
  py::class_<opendnp3::TaskConfig>(m, "TaskConfig",
      "Object containing multiple fields for configuring tasks.")

      .def(
          py::init<opendnp3::TaskId, opendnp3::ITaskCallback*>(),
          py::arg("taskId"), py::arg("pCallback"))

      .def(
          py::init(&opendnp3::TaskConfig::Default),
          "Default constructor.")

      .def_static(
          "Default",
          &opendnp3::TaskConfig::Default)

      .def_static(
          "With",
          &opendnp3::TaskConfig::With,
          "Syntax sugar for building configs.")

      .def_readwrite(
          "taskId",
          &opendnp3::TaskConfig::taskId)

      .def_readwrite(
          "pCallback",
          &opendnp3::TaskConfig::pCallback);
}

#endif // PYDNP3_OPENDNP3
#endif
