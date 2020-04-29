#ifndef PYDNP3_ASIODNP3_OUTSTATIONSTACKCONFIG_H
#define PYDNP3_ASIODNP3_OUTSTATIONSTACKCONFIG_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/OutstationStackConfig.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_OutstationStackConfig(py::module& m)
{
  // ----- class: asiodnp3::OutstationStackConfig -----
  py::class_<asiodnp3::OutstationStackConfig>(m, "OutstationStackConfig",
      "A composite configuration struct that contains all the config information for a dnp3 outstation stack.")

      .def(
          py::init<const opendnp3::DatabaseSizes&>(),
          py::arg("dbSizes"))

      .def_property_readonly(
          "dbConfig",
          [](const asiodnp3::OutstationStackConfig& self) { return &self.dbConfig; },
          "Configuration of the database.",
          py::return_value_policy::reference)

      .def_readwrite(
          "outstation",
          &asiodnp3::OutstationStackConfig::outstation,
          "Outstation config.")

      .def_readwrite(
          "link",
          &asiodnp3::OutstationStackConfig::link,
          "Link layer config.");
}

#endif // PYDNP3_ASIODNP3
#endif
