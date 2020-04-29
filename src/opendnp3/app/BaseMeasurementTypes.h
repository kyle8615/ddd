#ifndef PYDNP3_OPENDNP3_APP_BASEMEASUREMENTTYPES_H
#define PYDNP3_OPENDNP3_APP_BASEMEASUREMENTTYPES_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/BaseMeasurementTypes.h>
#include <opendnp3/gen/DoubleBit.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

template <typename T>
void declareTypedMeasurement(py::module& m, string const& type)
{
  // ----- class: opendnp3::TypedMeasurement<T> -----
  py::class_<opendnp3::TypedMeasurement<T>, opendnp3::Measurement>(m, ("TypedMeasurement" + type).c_str(),
      "Common subclass to analogs and counters.")

      .def_readwrite(
          "value",
          &opendnp3::TypedMeasurement<T>::value);
}

void bind_BaseMeasurementTypes(py::module& m)
{
  // ----- class: opendnp3::Measurement -----
  py::class_<opendnp3::Measurement>(m, "Measurement",
      "Base class shared by all of the DataPoint types.")

      .def_readwrite(
          "flags",
          &opendnp3::Measurement::flags,
          "Bitfield that stores type specific quality information.")

      .def_readwrite(
          "time",
          &opendnp3::Measurement::time,
          "Timestamp associated with the measurement.");

  declareTypedMeasurement<bool>(m, "Bool");
  declareTypedMeasurement<opendnp3::DoubleBit>(m, "DoubleBit");
  declareTypedMeasurement<double>(m, "Double");
  declareTypedMeasurement<uint32_t>(m, "Uint32");
}

#endif // PYDNP3_OPENDNP3
#endif
