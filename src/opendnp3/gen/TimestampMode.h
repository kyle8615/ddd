#ifndef PYDNP3_OPENDNP3_GEN_TIMESTAMPMODE_H
#define PYDNP3_OPENDNP3_GEN_TIMESTAMPMODE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/TimestampMode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_TimestampMode(py::module& m)
{
  // ----- enum class: opendnp3::TimestampMode -----
  py::enum_<opendnp3::TimestampMode>(m, "TimestampMode",
      "Determines what the master station does when it sees the NEED_TIME iin bit.")

      .value(
          "SYNCHRONIZED",
          opendnp3::TimestampMode::SYNCHRONIZED,
          "The timestamp is UTC synchronized at the remote device.")

      .value(
          "UNSYNCHRONIZED",
          opendnp3::TimestampMode::UNSYNCHRONIZED,
          "The device indicate the timestamp may be unsynchronized.")

      .value(
          "INVALID",
          opendnp3::TimestampMode::INVALID,
          "Timestamp is not valid, ignore the value and use a local timestamp.");
}

#endif // PYDNP3_OPENDNP3
#endif
