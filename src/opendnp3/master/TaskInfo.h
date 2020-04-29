#ifndef PYDNP3_OPENDNP3_MASTER_TASKINFO_H
#define PYDNP3_OPENDNP3_MASTER_TASKINFO_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/TaskInfo.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

void bind_TaskInfo(py::module& m)
{
  // ----- class: opendnp3::TaskInfo -----
  py::class_<opendnp3::TaskInfo, std::shared_ptr<opendnp3::TaskInfo>>(m, "TaskInfo",
      "Struct that provides information about a completed or failed task.")

      .def(
          py::init<opendnp3::MasterTaskType, opendnp3::TaskCompletion, opendnp3::TaskId>(),
          py::arg("type"), py::arg("result"), py::arg("id"))

      .def_readwrite(
          "type",
          &opendnp3::TaskInfo::type)

      .def_readwrite(
          "result",
          &opendnp3::TaskInfo::result)

      .def_readwrite(
          "id",
          &opendnp3::TaskInfo::id);
}

#endif // PYDNP3_OPENDNP3
#endif
