#ifndef PYDNP3_OPENDNP3_MASTER_TASKID_H
#define PYDNP3_OPENDNP3_MASTER_TASKID_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/TaskId.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

void bind_TaskId(py::module& m)
{
  // ----- class: opendnp3::TaskId -----
  py::class_<opendnp3::TaskId, std::shared_ptr<opendnp3::TaskId>>(m, "TaskId",
      "Interface that represents a running master.")

      .def_static(
          "Defined",
          &opendnp3::TaskId::Defined,
          py::arg("id"))

      .def_static(
          "Undefined",
          &opendnp3::TaskId::Undefined)

      .def(
          "GetId",
          &opendnp3::TaskId::GetId)

      .def(
          "IsDefined",
          &opendnp3::TaskId::IsDefined);
}

#endif // PYDNP3_OPENDNP3
#endif
