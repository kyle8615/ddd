#ifndef PYDNP3_OPENDNP3_GEN_TIMESYNCMODE_H
#define PYDNP3_OPENDNP3_GEN_TIMESYNCMODE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/TimeSyncMode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_TimeSyncMode(py::module& m)
{
  // ----- enum class: opendnp3::TimeSyncMode -----
  py::enum_<opendnp3::TimeSyncMode>(m, "TimeSyncMode",
      "Indicates the validity of timestamp values for an entire object header.")

      .value(
          "NonLAN",
          opendnp3::TimeSyncMode::NonLAN,
          "Synchronize the outstation's time using the non-LAN time sync procedure.")

      .value(
          "LAN",
          opendnp3::TimeSyncMode::LAN,
          "Synchronize the outstation's time using the LAN time sync procedure.")

      .value(
          "None",
          opendnp3::TimeSyncMode::None,
          "Don't perform a time-sync.");
}

#endif // PYDNP3_OPENDNP3
#endif
