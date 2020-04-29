#ifndef PYDNP3_OPENDNP3_GEN_COMMANDPOINTSTATE_H
#define PYDNP3_OPENDNP3_GEN_COMMANDPOINTSTATE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/CommandPointState.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CommandPointState(py::module& m)
{
  // ----- enum class: opendnp3::CommandPointState -----
  py::enum_<opendnp3::CommandPointState>(m, "CommandPointState",
      "List the various states that an individual command object can be in after an SBO or direct operate request.")

      .value(
          "INIT",
          opendnp3::CommandPointState::INIT,
          "No corresponding response was ever received for this command point.")

      .value(
          "SELECT_SUCCESS",
          opendnp3::CommandPointState::SELECT_SUCCESS,
          "A response to a select request was received and matched, but the operate did not complete.")

      .value(
          "SELECT_MISMATCH",
          opendnp3::CommandPointState::SELECT_MISMATCH,
          "A response to a select operation did not contain the same value that was sent.")

      .value(
          "SELECT_FAIL",
          opendnp3::CommandPointState::SELECT_FAIL,
          "A response to a select operation contained a command status other than success.")

      .value(
          "OPERATE_FAIL",
          opendnp3::CommandPointState::OPERATE_FAIL,
          "A response to an operate or direct operate did not match the request.")

      .value(
          "SUCCESS",
          opendnp3::CommandPointState::SUCCESS,
          "A matching response was received to the operate.");

  // ----- func: opendnp3::CommandPointStateToString -----
  m.def(
      "CommandPointStateToString",
      &opendnp3::CommandPointStateToString,
      py::arg("state"));
}

#endif // PYDNP3_OPENDNP3
#endif
