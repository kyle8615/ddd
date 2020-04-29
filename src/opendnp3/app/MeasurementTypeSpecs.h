#ifndef PYDNP3_OPENDNP3_APP_MEASUREMENTTYPESPECS_H
#define PYDNP3_OPENDNP3_APP_MEASUREMENTTYPESPECS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/MeasurementTypeSpecs.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_MeasurementTypeSpecs(py::module& m)
{
  // ----- class: opendnp3::BinarySpec -----
  py::class_<opendnp3::BinarySpec, opendnp3::BinaryInfo>(m, "BinarySpec")

      .def_static(
          "IsQualityOnlineOnly",
          &opendnp3::BinarySpec::IsQualityOnlineOnly,
          py::arg("binary"))

      .def_static(
          "IsEvent",
          &opendnp3::BinarySpec::IsEvent,
          py::arg("oldValue"), py::arg("newValue"));

  // ----- class: opendnp3::DoubleBitBinarySpec -----
  py::class_<opendnp3::DoubleBitBinarySpec, opendnp3::DoubleBitBinaryInfo>(m, "DoubleBitBinarySpec")

      .def_static(
          "IsEvent",
          &opendnp3::DoubleBitBinarySpec::IsEvent,
          py::arg("oldValue"), py::arg("newValue"));

  // ----- class: opendnp3::BinaryOutputStatusSpec -----
  py::class_<opendnp3::BinaryOutputStatusSpec, opendnp3::BinaryOutputStatusInfo>(m, "BinaryOutputStatusSpec")

      .def_static(
          "IsEvent",
          &opendnp3::BinaryOutputStatusSpec::IsEvent,
          py::arg("oldValue"), py::arg("newValue"));

  // ----- class: opendnp3::AnalogSpec -----
  py::class_<opendnp3::AnalogSpec, opendnp3::AnalogInfo>(m, "AnalogSpec")

      .def_static(
          "IsEvent",
          &opendnp3::AnalogSpec::IsEvent,
          ":type deadband: double",
          py::arg("oldValue"), py::arg("newValue"), py::arg("deadband"));

  // ----- class: opendnp3::CounterSpec -----
  py::class_<opendnp3::CounterSpec, opendnp3::CounterInfo>(m, "CounterSpec")
      .def_static(
          "IsEvent",
          &opendnp3::CounterSpec::IsEvent,
          ":type deadband: unsigned int",
          py::arg("oldValue"), py::arg("newValue"), py::arg("deadband"));

  // ----- class: opendnp3::FrozenCounterSpec -----
  py::class_<opendnp3::FrozenCounterSpec, opendnp3::FrozenCounterInfo>(m, "FrozenCounterSpec")

      .def_static(
          "IsEvent",
          &opendnp3::FrozenCounterSpec::IsEvent,
          ":type deadband: unsigned int",
          py::arg("oldValue"), py::arg("newValue"), py::arg("deadband"));

  // ----- class: opendnp3::AnalogOutputStatusSpec -----
  py::class_<opendnp3::AnalogOutputStatusSpec, opendnp3::AnalogOutputStatusInfo>(m, "AnalogOutputStatusSpec")

      .def_static(
          "IsEvent",
          &opendnp3::AnalogOutputStatusSpec::IsEvent,
          ":type deadband: double",
          py::arg("oldValue"), py::arg("newValue"), py::arg("deadband"));

  // ----- class: opendnp3::OctetStringSpec -----
  py::class_<opendnp3::OctetStringSpec, opendnp3::OctetStringInfo>(m, "OctetStringSpec")

      .def_static(
          "IsEvent",
          &opendnp3::OctetStringSpec::IsEvent,
          py::arg("oldValue"), py::arg("newValue"));
  // ----- class: opendnp3::TimeAndIntervalSpec -----
  py::class_<opendnp3::TimeAndIntervalSpec, opendnp3::TimeAndIntervalInfo>(m, "TimeAndIntervalSpec");

  // ----- class: opendnp3::SecurityStatSpec -----
  py::class_<opendnp3::SecurityStatSpec, opendnp3::SecurityStatInfo>(m, "SecurityStatSpec")

      .def_static(
          "IsEvent",
          &opendnp3::SecurityStatSpec::IsEvent,
          ":type deadband: unsigned int",
          py::arg("oldValue"), py::arg("newValue"), py::arg("deadband"));
}

#endif // PYDNP3_OPENDNP3
#endif
