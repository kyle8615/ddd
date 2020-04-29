#ifndef PYDNP3_OPENDNP3_GEN_COMMANDSTATUS_H
#define PYDNP3_OPENDNP3_GEN_COMMANDSTATUS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/CommandStatus.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CommandStatus(py::module& m)
{
  // ----- enum class: opendnp3::CommandStatus -----
  py::enum_<opendnp3::CommandStatus>(m, "CommandStatus",
      "An enumeration of result codes received from an outstation in response to command request. \n"
      "These correspond to those defined in the DNP3 standard.")

      .value(
          "SUCCESS",
          opendnp3::CommandStatus::SUCCESS,
          "Command was accepted, initiated, or queued.")

      .value(
          "TIMEOUT",
          opendnp3::CommandStatus::TIMEOUT,
          "Command timed out before completing.")

      .value(
          "NO_SELECT",
          opendnp3::CommandStatus::NO_SELECT,
          "Command requires being selected before operate, configuration issue.")

      .value(
          "FORMAT_ERROR",
          opendnp3::CommandStatus::FORMAT_ERROR,
          "Bad control code or timing values.")

      .value(
          "NOT_SUPPORTED",
          opendnp3::CommandStatus::NOT_SUPPORTED,
          "Command is not implemented.")

      .value(
          "ALREADY_ACTIVE",
          opendnp3::CommandStatus::ALREADY_ACTIVE,
          "Command is all ready in progress or its all ready in that mode.")

      .value(
          "HARDWARE_ERROR",
          opendnp3::CommandStatus::HARDWARE_ERROR,
          "Something is stopping the command, often a local/remote interlock.")

      .value(
          "LOCAL",
          opendnp3::CommandStatus::LOCAL,
          "The function governed by the control is in local only control.")

      .value(
          "TOO_MANY_OPS",
          opendnp3::CommandStatus::TOO_MANY_OPS,
          "The command has been done too often and has been throttled.")

      .value(
          "NOT_AUTHORIZED",
          opendnp3::CommandStatus::NOT_AUTHORIZED,
          "The command was rejected because the device denied it or an RTU intercepted it.")

      .value(
          "AUTOMATION_INHIBIT",
          opendnp3::CommandStatus::AUTOMATION_INHIBIT,
          "Command not accepted because it was prevented or inhibited by a local automation process, "
          "such as interlocking logic or synchrocheck.")

      .value(
          "PROCESSING_LIMITED",
          opendnp3::CommandStatus::PROCESSING_LIMITED,
          "Command not accepted because the device cannot process any more activities than are presently in progress.")

      .value(
          "OUT_OF_RANGE",
          opendnp3::CommandStatus::OUT_OF_RANGE,
          "Command not accepted because the value is outside the acceptable range permitted for this point.")

      .value(
          "DOWNSTREAM_LOCAL",
          opendnp3::CommandStatus::DOWNSTREAM_LOCAL,
          "Command not accepted because the outstation is forwarding the request to another downstream device "
          "which reported LOCAL.")

      .value(
          "ALREADY_COMPLETE",
          opendnp3::CommandStatus::ALREADY_COMPLETE,
          "Command not accepted because the outstation has already completed the requested operation.")

      .value(
          "BLOCKED",
          opendnp3::CommandStatus::BLOCKED,
          "Command not accepted because the requested function is specifically blocked at the outstation.")

      .value(
          "CANCELLED",
          opendnp3::CommandStatus::CANCELLED,
          "Command not accepted because the operation was cancelled.")

      .value(
          "BLOCKED_OTHER_MASTER",
          opendnp3::CommandStatus::BLOCKED_OTHER_MASTER,
          "Command not accepted because another master is communicating with the outstation "
          "and has exclusive rights to operate this control point")

      .value(
          "DOWNSTREAM_FAIL",
          opendnp3::CommandStatus::DOWNSTREAM_FAIL,
          "Command not accepted because the outstation is forwarding the request to another downstream device "
          "which cannot be reached or is otherwise incapable of performing the request.")

      .value(
          "NON_PARTICIPATING",
          opendnp3::CommandStatus::NON_PARTICIPATING,
          "(Deprecated) indicates the outstation shall not issue or perform the control operation.")

      .value(
          "UNDEFINED",
          opendnp3::CommandStatus::UNDEFINED,
          "10 to 126 are currently reserved.");

  // ----- function: opendnp3::CommandStatusToType -----
  m.def(
      "CommandStatusToType",
      &opendnp3::CommandStatusToType,
      py::arg("status"));

  // ----- function: opendnp3::CommandStatusFromType -----
  m.def(
      "CommandStatusFromType",
      &opendnp3::CommandStatusFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::CommandStatusToString -----
  m.def(
      "CommandStatusToString",
      &opendnp3::CommandStatusToString,
      py::arg("status"));
}

#endif // PYDNP3_OPENDNP3
#endif
