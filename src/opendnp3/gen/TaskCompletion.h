#ifndef PYDNP3_OPENDNP3_GEN_TASKCOMPLETION_H
#define PYDNP3_OPENDNP3_GEN_TASKCOMPLETION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/TaskCompletion.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_TaskCompletion(py::module& m)
{
  // ----- enum class: opendnp3::TaskCompletion -----
  py::enum_<opendnp3::TaskCompletion>(m, "TaskCompletion",
      "Enum that describes if a master task succeeded or failed.")

      .value(
          "SUCCESS",
          opendnp3::TaskCompletion::SUCCESS,
          "A valid response was received from the outstation.")

      .value(
          "FAILURE_BAD_RESPONSE",
          opendnp3::TaskCompletion::FAILURE_BAD_RESPONSE,
          "A response was received from the outstation, but it was not valid.")

      .value(
          "FAILURE_RESPONSE_TIMEOUT",
          opendnp3::TaskCompletion::FAILURE_RESPONSE_TIMEOUT,
          "The task request did not receive a response within the timeout.")

      .value(
          "FAILURE_START_TIMEOUT",
          opendnp3::TaskCompletion::FAILURE_START_TIMEOUT,
          "The start timeout expired before the task could begin running.")

      .value(
          "FAILURE_MESSAGE_FORMAT_ERROR",
          opendnp3::TaskCompletion::FAILURE_MESSAGE_FORMAT_ERROR,
          "The task failed because the master was unable to format the request.")

      .value(
          "FAILURE_NO_COMMS",
          opendnp3::TaskCompletion::FAILURE_NO_COMMS,
          "There is no communication with the outstation, so the task was not attempted.");

  // ----- function: opendnp3::TaskCompletionToString -----
  m.def(
      "TaskCompletionToString",
      &opendnp3::TaskCompletionToString);
}

#endif // PYDNP3_OPENDNP3
#endif
