#ifndef PYDNP3_ASIODNP3_DATABASECONFIG_H
#define PYDNP3_ASIODNP3_DATABASECONFIG_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/DatabaseConfig.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_DatabaseConfig(py::module& m)
{
  // ----- class: asiodnp3::DatabaseConfig -----
  py::class_<asiodnp3::DatabaseConfig, std::shared_ptr<asiodnp3::DatabaseConfig>>(m, "DatabaseConfig")

      .def(
          py::init<const opendnp3::DatabaseSizes&>(),
          py::arg("sizes"))

      .def_readonly(
          "sizes",
          &asiodnp3::DatabaseConfig::sizes)

      .def_property_readonly(
          "binary",
          [](const asiodnp3::DatabaseConfig& self) { return &self.binary; },
          py::return_value_policy::reference)

      .def_property_readonly(
          "doubleBinary",
          [](const asiodnp3::DatabaseConfig& self) { return &self.doubleBinary; },
          py::return_value_policy::reference)

      .def_property_readonly(
          "analog",
          [](const asiodnp3::DatabaseConfig& self) { return &self.analog; },
          py::return_value_policy::reference)

      .def_property_readonly(
          "counter",
          [](const asiodnp3::DatabaseConfig& self) { return &self.counter; },
          py::return_value_policy::reference)

      .def_property_readonly(
          "frozenCounter",
          [](const asiodnp3::DatabaseConfig& self) { return &self.frozenCounter; },
          py::return_value_policy::reference)

      .def_property_readonly(
          "boStatus",
          [](const asiodnp3::DatabaseConfig& self) { return &self.boStatus; },
          py::return_value_policy::reference)

      .def_property_readonly(
          "aoStatus",
          [](const asiodnp3::DatabaseConfig& self) { return &self.aoStatus; },
          py::return_value_policy::reference)

      .def_property_readonly(
          "timeAndInterval",
          [](const asiodnp3::DatabaseConfig& self) { return &self.timeAndInterval; },
          py::return_value_policy::reference)

      .def_property_readonly(
          "octetString",
          [](const asiodnp3::DatabaseConfig& self) { return &self.octetString; },
          py::return_value_policy::reference);
}

#endif // PYDNP3_ASIODNP3
#endif
