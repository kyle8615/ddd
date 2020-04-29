#ifndef PYDNP3_OPENDNP3_APP_MEASUREMENTINFO_H
#define PYDNP3_OPENDNP3_APP_MEASUREMENTINFO_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/MeasurementInfo.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_MeasurementInfo(py::module& m)
{
  // ----- class: opendnp3::BinaryInfo -----
  py::class_<opendnp3::BinaryInfo>(m, "BinaryInfo")

      .def_property_readonly_static(
          "EventTypeEnum",
          [](py::object) { return opendnp3::BinaryInfo::EventTypeEnum; })

      .def_property_readonly_static(
          "StaticTypeEnum",
          [](py::object) { return opendnp3::BinaryInfo::StaticTypeEnum; })

      .def_property_readonly_static(
          "DefaultEventVariation",
          [](py::object) { return opendnp3::BinaryInfo::DefaultEventVariation; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::BinaryInfo::DefaultStaticVariation; });

  // ----- class: opendnp3::DoubleBitBinaryInfo -----
  py::class_<opendnp3::DoubleBitBinaryInfo>(m, "DoubleBitBinaryInfo")

      .def_property_readonly_static(
          "EventTypeEnum",
          [](py::object) { return opendnp3::DoubleBitBinaryInfo::EventTypeEnum; })

      .def_property_readonly_static(
          "StaticTypeEnum",
          [](py::object) { return opendnp3::DoubleBitBinaryInfo::StaticTypeEnum; })

      .def_property_readonly_static(
          "DefaultEventVariation",
          [](py::object) { return opendnp3::DoubleBitBinaryInfo::DefaultEventVariation; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::DoubleBitBinaryInfo::DefaultStaticVariation; });

  // ----- class: opendnp3::BinaryOutputStatusInfo -----
  py::class_<opendnp3::BinaryOutputStatusInfo>(m, "BinaryOutputStatusInfo")

      .def_property_readonly_static(
          "EventTypeEnum",
          [](py::object) { return opendnp3::BinaryOutputStatusInfo::EventTypeEnum; })

      .def_property_readonly_static(
          "StaticTypeEnum",
          [](py::object) { return opendnp3::BinaryOutputStatusInfo::StaticTypeEnum; })

      .def_property_readonly_static(
          "DefaultEventVariation",
          [](py::object) { return opendnp3::BinaryOutputStatusInfo::DefaultEventVariation; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::BinaryOutputStatusInfo::DefaultStaticVariation; });

  // ----- class: opendnp3::AnalogInfo -----
  py::class_<opendnp3::AnalogInfo>(m, "AnalogInfo")

      .def_property_readonly_static(
          "EventTypeEnum",
          [](py::object) { return opendnp3::AnalogInfo::EventTypeEnum; })

      .def_property_readonly_static(
          "StaticTypeEnum",
          [](py::object) { return opendnp3::AnalogInfo::StaticTypeEnum; })

      .def_property_readonly_static(
          "DefaultEventVariation",
          [](py::object) { return opendnp3::AnalogInfo::DefaultEventVariation; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::AnalogInfo::DefaultStaticVariation; });

  // ----- class: opendnp3::CounterInfo -----
  py::class_<opendnp3::CounterInfo>(m, "CounterInfo")

      .def_property_readonly_static(
          "EventTypeEnum",
          [](py::object) { return opendnp3::CounterInfo::EventTypeEnum; })

      .def_property_readonly_static(
          "StaticTypeEnum",
          [](py::object) { return opendnp3::CounterInfo::StaticTypeEnum; })

      .def_property_readonly_static(
          "DefaultEventVariation",
          [](py::object) { return opendnp3::CounterInfo::DefaultEventVariation; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::CounterInfo::DefaultStaticVariation; });

  // ----- class: opendnp3::FrozenCounterInfo -----
  py::class_<opendnp3::FrozenCounterInfo>(m, "FrozenCounterInfo")

      .def_property_readonly_static(
          "EventTypeEnum",
          [](py::object) { return opendnp3::FrozenCounterInfo::EventTypeEnum; })

      .def_property_readonly_static(
          "StaticTypeEnum",
          [](py::object) { return opendnp3::FrozenCounterInfo::StaticTypeEnum; })

      .def_property_readonly_static(
          "DefaultEventVariation",
          [](py::object) { return opendnp3::FrozenCounterInfo::DefaultEventVariation; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::FrozenCounterInfo::DefaultStaticVariation; });

  // ----- class: opendnp3::AnalogOutputStatusInfo -----
  py::class_<opendnp3::AnalogOutputStatusInfo>(m, "AnalogOutputStatusInfo")

      .def_property_readonly_static(
          "EventTypeEnum",
          [](py::object) { return opendnp3::AnalogOutputStatusInfo::EventTypeEnum; })

      .def_property_readonly_static(
          "StaticTypeEnum",
          [](py::object) { return opendnp3::AnalogOutputStatusInfo::StaticTypeEnum; })

      .def_property_readonly_static(
          "DefaultEventVariation",
          [](py::object) { return opendnp3::AnalogOutputStatusInfo::DefaultEventVariation; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::AnalogOutputStatusInfo::DefaultStaticVariation; });

  // ----- class: opendnp3::OctetStringInfo -----
  py::class_<opendnp3::OctetStringInfo>(m, "OctetStringInfo")

      .def_property_readonly_static(
          "EventTypeEnum",
          [](py::object) { return opendnp3::OctetStringInfo::EventTypeEnum; })

      .def_property_readonly_static(
          "StaticTypeEnum",
          [](py::object) { return opendnp3::OctetStringInfo::StaticTypeEnum; })

      .def_property_readonly_static(
          "DefaultEventVariation",
          [](py::object) { return opendnp3::OctetStringInfo::DefaultEventVariation; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::OctetStringInfo::DefaultStaticVariation; });

  // ----- class: opendnp3::TimeAndIntervalInfo -----
  py::class_<opendnp3::TimeAndIntervalInfo>(m, "TimeAndIntervalInfo")

      .def_property_readonly_static(
          "StaticTypeEnum",
          [](py::object) { return opendnp3::TimeAndIntervalInfo::StaticTypeEnum; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::TimeAndIntervalInfo::DefaultStaticVariation; });

  // ----- class: opendnp3::SecurityStatInfo -----
  py::class_<opendnp3::SecurityStatInfo>(m, "SecurityStatInfo")

      .def_property_readonly_static(
          "DefaultEventVariation",
          [](py::object) { return opendnp3::SecurityStatInfo::DefaultEventVariation; })

      .def_property_readonly_static(
          "DefaultStaticVariation",
          [](py::object) { return opendnp3::SecurityStatInfo::DefaultStaticVariation; });
}

#endif // PYDNP3_OPENDNP3
#endif
