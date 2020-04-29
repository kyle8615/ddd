#ifndef PYDNP3_OPENDNP3_GEN_KEYSTATUS_H
#define PYDNP3_OPENDNP3_GEN_KEYSTATUS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/KeyStatus.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_KeyStatus(py::module& m)
{
  // ----- enum class: opendnp3::KeyStatus -----
  py::enum_<opendnp3::KeyStatus>(m, "KeyStatus",
      "Describes the status of the two session keys as known by the outstation.")

      .value(
          "OK",
          opendnp3::KeyStatus::OK,
          "Session keys are valid.")

      .value(
          "NOT_INIT",
          opendnp3::KeyStatus::NOT_INIT,
          "Sessions keys are not valid due to no init or interval expiration.")

      .value(
          "COMM_FAIL",
          opendnp3::KeyStatus::COMM_FAIL,
          "Session keys are not valid due to communications failure.")

      .value(
          "AUTH_FAIL",
          opendnp3::KeyStatus::AUTH_FAIL,
          "Session keys are not valid due to an authentication failure")

      .value(
          "UNDEFINED",
          opendnp3::KeyStatus::UNDEFINED);

  // ----- function: opendnp3::KeyStatusToType -----
  m.def(
      "KeyStatusToType",
      &opendnp3::KeyStatusToType,
      py::arg("status"));

  // ----- function: opendnp3::KeyStatusFromType -----
  m.def(
      "KeyStatusFromType",
      &opendnp3::KeyStatusFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::KeyStatusToString -----
  m.def(
      "KeyStatusToString",
      &opendnp3::KeyStatusToString,
      py::arg("status"));
}

#endif // PYDNP3_OPENDNP3
#endif
