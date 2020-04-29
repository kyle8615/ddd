#ifndef PYDNP3_OPENDNP3_GEN_CHANNELSTATE_H
#define PYDNP3_OPENDNP3_GEN_CHANNELSTATE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/ChannelState.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_ChannelState(py::module& m)
{
  // ----- enum class: opendnp3::ChannelState -----
  py::enum_<opendnp3::ChannelState>(m, "ChannelState",
      "Enumeration for possible states of a channel.")

      .value(
          "CLOSED",
          opendnp3::ChannelState::CLOSED,
          "Offline and idle.")

      .value(
          "OPENING",
          opendnp3::ChannelState::OPENING,
          "Trying to open.")

      .value(
          "OPEN",
          opendnp3::ChannelState::OPEN,
          "Open.")

      .value(
          "SHUTDOWN",
          opendnp3::ChannelState::SHUTDOWN,
          "Stopped and will never do anything again.");

  // ----- function: opendnp3::ChannelStateToString -----
  m.def(
      "ChannelStateToString",
      &opendnp3::ChannelStateToString,
      py::arg("state"));
}

#endif // PYDNP3_OPENDNP3
#endif
