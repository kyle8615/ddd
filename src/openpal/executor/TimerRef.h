#ifndef PYDNP3_OPENPAL_EXECUTOR_TIMERREF_H
#define PYDNP3_OPENPAL_EXECUTOR_TIMERREF_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/executor/TimerRef.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_TimerRef(py::module& m)
{
  // ----- class: openpal::TimerRef -----
  py::class_<openpal::TimerRef>(m, "TimerRef",
      "A management class to make dealing with timer pointers safer a little safer. \n"
      "Holds an optional pointer to an active ITimer pointer. \n"
      "Acts as a safe proxy for dealing with a recurring timer instance.")

      .def(
          py::init<openpal::IExecutor&>(),
          py::arg("executor"),
          py::return_value_policy::reference)

      .def(
          "IsActive",
          &openpal::TimerRef::IsActive,
          "Called to see if the timer is currently active.")

      .def(
          "ExpiresAt",
          &openpal::TimerRef::ExpiresAt,
          ":return: the expiration time, MonotonticTimestamp::Max() if not active")

      .def(
          "Cancel",
          &openpal::TimerRef::Cancel,
          "   Cancels any existing timer. \n"
          ":return: true if the timer was active, false otherwise");
}

#endif // PYDNP3_OPENPAL
#endif
