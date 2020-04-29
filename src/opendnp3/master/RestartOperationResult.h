#ifndef PYDNP3_OPENDNP3_MASTER_RESTARTOPERATIONRESULT_H
#define PYDNP3_OPENDNP3_MASTER_RESTARTOPERATIONRESULT_H

#include <Python.h>
#include <iostream>
#include <pybind11/pybind11.h>

#include <opendnp3/master/RestartOperationResult.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_RestartOperationResult(py::module& m)
{
  // ----- class: opendnp3::RestartOperationResult -----
  py::class_<opendnp3::RestartOperationResult>(m, "RestartOperationResult")

      .def(py::init<>())

      .def(
          py::init<opendnp3::TaskCompletion, openpal::TimeDuration>(),
          py::arg("summary"), py::arg("restartTime"))

      .def_readwrite(
          "summary",
          &opendnp3::RestartOperationResult::summary,
          "The result of the task as a whole.")

      .def_readwrite(
          "restartTime",
          &opendnp3::RestartOperationResult::restartTime,
          "Time delay until restart.");

  // ----- class: opendnp3::RestartOperationCallbackT -----
  py::class_<opendnp3::RestartOperationCallbackT>(m, "RestartOperationCallbackT");
}

#endif // PYDNP3_OPENDNP3
#endif
