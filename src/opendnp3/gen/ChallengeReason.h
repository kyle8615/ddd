#ifndef PYDNP3_OPENDNP3_GEN_CHALLENGEREASON_H
#define PYDNP3_OPENDNP3_GEN_CHALLENGEREASON_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/ChallengeReason.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_ChallengeReason(py::module& m)
{
  // ----- enum class: opendnp3::ChallengeReason -----
  py::enum_<opendnp3::ChallengeReason>(m, "ChallengeReason",
      "Enumerates reasons for a sec-auth challenge")

      .value(
          "CRITICAL",
          opendnp3::ChallengeReason::CRITICAL,
          "Challenging a critical function.")

      .value(
          "UNKNOWN",
          opendnp3::ChallengeReason::UNKNOWN,
          "Unknown reason");

  // ----- func: opendnp3::ChallengeReasonToType -----
  m.def(
      "ChallengeReasonToType",
      &opendnp3::ChallengeReasonToType,
      py::arg("reason"));

  // ----- func: opendnp3::ChallengeReasonFromType -----
  m.def(
      "ChallengeReasonFromType",
      &opendnp3::ChallengeReasonFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- func: opendnp3::ChallengeReasonToString -----
  m.def(
      "ChallengeReasonToString",
      &opendnp3::ChallengeReasonToString,
      py::arg("reason"));
}

#endif // PYDNP3_OPENDNP3
#endif
