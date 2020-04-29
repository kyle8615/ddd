#ifndef PYDNP3_OPENPAL_CONTAINER_ARRAY_H
#define PYDNP3_OPENPAL_CONTAINER_ARRAY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/container/Array.h>
#include <pybind11/operators.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

namespace opendnp3 {
class BinaryConfig;
class DoubleBitBinaryConfig;
class AnalogConfig;
class CounterConfig;
class FrozenCounterConfig;
class BOStatusConfig;
class AOStatusConfig;
class OctetStringConfig;
class TimeAndIntervalConfig;
}

template <class T, class W>
void declareArray(py::module& m, std::string const& t, std::string const& w)
{
  // ----- class: openpal::Array<T, W> -----
  py::class_<openpal::Array<T, W>, openpal::HasSize<W>>(m, ("Array" + t).c_str(),
      "Template type for a dynamically allocated array.")

      .def(py::init<>())

      .def(
          py::init<W>(),
          (":type size: " + w).c_str(),
          py::arg("size"))

      .def(
          py::init<const openpal::Array<T, W>&>(),
          py::arg("copy"))

      .def(
          "ToView",
          &openpal::Array<T, W>::ToView)

      .def(
          "Contains",
          &openpal::Array<T, W>::Contains,
          (":type index: " + w).c_str(),
          py::arg("index"))

      .def(
          "__getitem__",
          (T & (openpal::Array<T, W>::*)(W))
              & openpal::Array<T, W>::operator[],
          (":type index: " + w).c_str(),
          py::arg("index"))

      .def(
          "__getitem__",
          (const T& (openpal::Array<T, W>::*)(W) const)
              & openpal::Array<T, W>::operator[],
          (":type index: " + w).c_str(),
          py::arg("index"));
}

void bind_Array(py::module& m)
{
  declareArray<opendnp3::BinaryConfig, uint16_t>(m, "BinaryConfig", "unsigned short");
  declareArray<opendnp3::DoubleBitBinaryConfig, uint16_t>(m, "DoubleBitBinaryConfig", "unsigned short");
  declareArray<opendnp3::AnalogConfig, uint16_t>(m, "AnalogConfig", "unsigned short");
  declareArray<opendnp3::CounterConfig, uint16_t>(m, "CounterConfig", "unsigned short");
  declareArray<opendnp3::FrozenCounterConfig, uint16_t>(m, "FrozenCounterConfig", "unsigned short");
  declareArray<opendnp3::BOStatusConfig, uint16_t>(m, "BOStatusConfig", "unsigned short");
  declareArray<opendnp3::AOStatusConfig, uint16_t>(m, "AOStatusConfig", "unsigned short");
  declareArray<opendnp3::OctetStringConfig, uint16_t>(m, "OctetStringConfig", "unsigned short");
  declareArray<opendnp3::TimeAndIntervalConfig, uint16_t>(m, "TimeAndIntervalConfig", "unsigned short");
  declareArray<uint8_t, uint32_t>(m, "Buffer", "unsigned int");
}

#endif // PYDNP3_OPENPAL
#endif
