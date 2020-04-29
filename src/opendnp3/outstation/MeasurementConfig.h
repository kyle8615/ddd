#ifndef PYDNP3_OPENDNP3_OUTSTATION_MEASUREMENTCONFIG_H
#define PYDNP3_OPENDNP3_OUTSTATION_MEASUREMENTCONFIG_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/MeasurementConfig.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

template <class Info>
void declareStaticConfig(py::module& m, string const& type)
{
  // ----- struct: opendnp3::StaticConfig<Info> -----
  py::class_<opendnp3::StaticConfig<Info>, opendnp3::IndexConfig>(m, ("StaticConfig" + type).c_str(),
      "All entries have this information.")

      .def(py::init<>())

      .def_readwrite(
          "svariation",
          &opendnp3::StaticConfig<Info>::svariation);

  // ----- func: opendnp3::StaticConfig -----
  m.def(
      "StaticConfig",
      []() { return opendnp3::StaticConfig<Info>(); },
      "Return instance of class StaticConfig<Info>");
}

template <class Info>
void declareEventConfig(py::module& m, string const& type)
{
  declareStaticConfig<Info>(m, type);

  // ----- struct: opendnp3::EventConfig<Info> -----
  py::class_<opendnp3::EventConfig<Info>, opendnp3::StaticConfig<Info>>(m, ("EventConfig" + type).c_str())

      .def(py::init<>())

      .def_readwrite(
          "clazz",
          &opendnp3::EventConfig<Info>::clazz)

      .def_readwrite(
          "evariation",
          &opendnp3::EventConfig<Info>::evariation);

  // ----- func: opendnp3::EventConfig -----
  m.def(
      "EventConfig",
      []() { return opendnp3::EventConfig<Info>(); },
      "Return instance of class EventConfig<Info>");
}

template <class Info>
void declareDeadbandConfig(py::module& m, string const& type)
{
  declareEventConfig<Info>(m, type);

  // ----- struct: opendnp3::DeadbandConfig<Info> -----
  py::class_<opendnp3::DeadbandConfig<Info>, opendnp3::EventConfig<Info>>(m, ("DeadbandConfig" + type).c_str())

      .def(py::init<>())

      .def_readwrite(
          "deadband",
          &opendnp3::DeadbandConfig<Info>::deadband);

  // ----- func: opendnp3::DeadbandConfig -----
  m.def(
      "DeadbandConfig",
      []() { return opendnp3::DeadbandConfig<Info>(); },
      "Return instance of class DeadbandConfig<Info>");
}

void bind_MeasurementConfig(py::module& m)
{
  // ----- struct: opendnp3::IndexConfig -----
  py::class_<opendnp3::IndexConfig>(m, "IndexConfig",
      "All entries have this information.")

      .def(
          py::init<uint16_t>(),
          py::arg("vIndex") = 0)

      .def_readwrite(
          "vIndex",
          &opendnp3::IndexConfig::vIndex,
          "Virtual index for discontiguous data, as opposed to the raw array index.");

  // ----- class: BinaryConfig -----
  declareEventConfig<opendnp3::BinaryInfo>(m, "BinaryInfo");

  py::class_<opendnp3::BinaryConfig, opendnp3::EventConfig<opendnp3::BinaryInfo>>(m, "BinaryConfig")

      .def(py::init<>());

  // ----- class: DoubleBitBinaryConfig -----
  declareEventConfig<opendnp3::DoubleBitBinaryInfo>(m, "DoubleBitBinaryInfo");

  py::class_<opendnp3::DoubleBitBinaryConfig,
      opendnp3::EventConfig<opendnp3::DoubleBitBinaryInfo>>(m, "DoubleBitBinaryConfig")

      .def(py::init<>());

  // ----- class: AnalogConfig -----
  declareDeadbandConfig<opendnp3::AnalogInfo>(m, "AnalogInfo");

  py::class_<opendnp3::AnalogConfig,
      opendnp3::DeadbandConfig<opendnp3::AnalogInfo>>(m, "AnalogConfig")

      .def(py::init<>());

  // ----- class: CounterConfig -----
  declareDeadbandConfig<opendnp3::CounterInfo>(m, "CounterInfo");

  py::class_<opendnp3::CounterConfig,
      opendnp3::DeadbandConfig<opendnp3::CounterInfo>>(m, "CounterConfig")

      .def(py::init<>());

  // ----- class: FrozenCounterConfig -----
  declareDeadbandConfig<opendnp3::FrozenCounterInfo>(m, "FrozenCounterInfo");

  py::class_<opendnp3::FrozenCounterConfig,
      opendnp3::DeadbandConfig<opendnp3::FrozenCounterInfo>>(m, "FrozenCounterConfig")

      .def(py::init<>());

  // ----- class: BOStatusConfig -----
  declareEventConfig<opendnp3::BinaryOutputStatusInfo>(m, "BinaryOutputStatusInfo");

  py::class_<opendnp3::BOStatusConfig,
      opendnp3::EventConfig<opendnp3::BinaryOutputStatusInfo>>(m, "BOStatusConfig")

      .def(py::init<>());

  // ----- class: AOStatusConfig -----
  declareDeadbandConfig<opendnp3::AnalogOutputStatusInfo>(m, "AnalogOutputStatusInfo");

  py::class_<opendnp3::AOStatusConfig,
      opendnp3::DeadbandConfig<opendnp3::AnalogOutputStatusInfo>>(m, "AOStatusConfig")

      .def(py::init<>());

  // ----- class: OctetStringConfig -----
  declareStaticConfig<opendnp3::OctetStringInfo>(m, "OctetStringInfo");

  py::class_<opendnp3::OctetStringConfig,
      opendnp3::EventConfig<opendnp3::OctetStringInfo>>(m, "OctetStringConfig")

      .def(py::init<>());

  // ----- class: TimeAndIntervalConfig -----
  declareStaticConfig<opendnp3::TimeAndIntervalInfo>(m, "TimeAndIntervalInfo");

  py::class_<opendnp3::TimeAndIntervalConfig,
      opendnp3::StaticConfig<opendnp3::TimeAndIntervalInfo>>(m, "TimeAndIntervalConfig")

      .def(py::init<>());

  // ----- class: SecurityStatConfig -----
  py::class_<opendnp3::SecurityStatConfig, opendnp3::IndexConfig>(m, "SecurityStatConfig")

      .def(py::init<>());
}

#endif // PYDNP3_OPENDNP3
#endif
