#ifndef PYDNP3_OPENDNP3_OUTSTATION_OUTSTATIONCONFIG_H
#define PYDNP3_OPENDNP3_OUTSTATION_OUTSTATIONCONFIG_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/OutstationConfig.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_OutstationConfig(py::module& m)
{
  // ----- struct: opendnp3::OutstationConfig -----
  py::class_<opendnp3::OutstationConfig>(m, "OutstationConfig",
      "Configuration information for a dnp3 outstation (outstation). \n"
      "Used as both input describing the startup configuration of the outstation, and as configuration state of "
      "mutable properties (i.e. unsolicited responses). \n"
      "Major feature areas are unsolicited responses, time synchronization requests, event buffer limits, "
      "and the DNP3 object/variations to use by default when the master requests class data or variation 0.")

      .def(py::init<>())

      .def(
          py::init<opendnp3::OutstationParams, opendnp3::EventBufferConfig>(),
          py::arg("params"), py::arg("eventBufferConfig"))

      .def_readwrite(
          "params",
          &opendnp3::OutstationConfig::params,
          "Various parameters that govern outstation behavior.")

      .def_readwrite(
          "eventBufferConfig",
          &opendnp3::OutstationConfig::eventBufferConfig,
          "Describes the sizes in the event buffer.");
}

#endif // PYDNP3_OPENDNP3
#endif
