#ifndef PYDNP3_ASIOPAL_CHANNELRETRY_H
#define PYDNP3_ASIOPAL_CHANNELRETRY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/ChannelRetry.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_ChannelRetry(py::module& m)
{
  // ----- class: asiopal::ChannelRetry -----
  py::class_<asiopal::ChannelRetry>(m, "ChannelRetry",
      "Class used to configure how channel failures are retried")
      .def(
          py::init<openpal::TimeDuration, openpal::TimeDuration>(),
          "   Construct a channel retry config class. \n"
          ":param minOpenRetry: minimum connection retry interval on failure \n"
          ":param maxOpenRetry: maximum connection retry interval on failure \n"
          ":param strategy: strategy to use",
          py::arg("minOpenRetry"), py::arg("maxOpenRetry"))

      .def(
          py::init<openpal::TimeDuration, openpal::TimeDuration, asiopal::IOpenDelayStrategy&>(),
          "   Construct a channel retry config class. \n"
          ":param minOpenRetry: minimum connection retry interval on failure \n"
          ":param maxOpenRetry: maximum connection retry interval on failure \n"
          ":param strategy: strategy to use",
          py::arg("minOpenRetry"), py::arg("maxOpenRetry"), py::arg("strategy"))

      .def(
          py::init(&asiopal::ChannelRetry::Default),
          "Default configuration of exponential backoff from 1 sec to 1 minute.")

      // @todo Return value policy experimental
      .def_static(
          "Default",
          &asiopal::ChannelRetry::Default,
          "Return the default configuration of exponential backoff from 1 sec to 1 minute.",
          py::return_value_policy::reference)

      .def_readwrite(
          "minOpenRetry",
          &asiopal::ChannelRetry::minOpenRetry,
          "Minimum connection retry interval on failure.")

      .def_readwrite(
          "maxOpenRetry",
          &asiopal::ChannelRetry::maxOpenRetry,
          "Maximum connection retry interval on failure.")

      .def(
          "NextDelay",
          &asiopal::ChannelRetry::NextDelay);
}

#endif // PYDNP3_ASIOPAL
#endif
