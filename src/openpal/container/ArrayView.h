#ifndef PYDNP3_OPENPAL_CONTAINER_ARRAYVIEW_H
#define PYDNP3_OPENPAL_CONTAINER_ARRAYVIEW_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/MeasurementConfig.h>
#include <openpal/container/ArrayView.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <class T, class W>
void declareArrayView(py::module& m, std::string const& valueType, std::string const& indexType)
{
  // ----- class: openpal::ArrayView<T, W> -----
  py::class_<openpal::ArrayView<T, W>,
      openpal::HasSize<W>>(m, ("ArrayView" + valueType).c_str(),
      "Acts as a safe facade around an underlying array.")

      .def(
          py::init(&openpal::ArrayView<T, W>::Empty),
          "Constructor: ArrayView(nullptr, 0)")

      .def(
          py::init<T*, W>(),
          (":type aSize: " + indexType).c_str(),
          py::arg("start"), py::arg("aSize"))

      .def_static(
          "Empty",
          &openpal::ArrayView<T, W>::Empty)

      .def(
          "Contains",
          (bool (openpal::ArrayView<T, W>::*)(W) const)
              & openpal::ArrayView<T, W>::Contains,
          (":type index: " + indexType).c_str(),
          py::arg("index"))

      .def(
          "Contains",
          (bool (openpal::ArrayView<T, W>::*)(W, W) const)
              & openpal::ArrayView<T, W>::Contains,
          (":type start: " + indexType + "\n:type stop: " + indexType).c_str(),
          py::arg("start"), py::arg("stop"))

      .def(
          "__getitem__",
          (T & (openpal::ArrayView<T, W>::*)(W))
              & openpal::ArrayView<T, W>::operator[],
          (":type index: " + indexType).c_str(),
          py::arg("index"))

      .def(
          "__getitem__",
          (const T& (openpal::ArrayView<T, W>::*)(W) const)
              & openpal::ArrayView<T, W>::operator[],
          (":type index: " + indexType).c_str(),
          py::arg("index"));

  // ----- func: openpal::ArrayView -----
  m.def(
      "ArrayView",
      [](T* start, W aSize) { return openpal::ArrayView<T, W>(start, aSize); },
      "Return instance of class ArrayView<T, W>");
}

void bind_ArrayView(py::module& m)
{
  declareArrayView<opendnp3::BinaryConfig, uint16_t>(m, "BinaryConfig", "unsigned short");
  declareArrayView<opendnp3::DoubleBitBinaryConfig, uint16_t>(m, "DoubleBitBinaryConfig", "unsigned short");
  declareArrayView<opendnp3::AnalogConfig, uint16_t>(m, "AnalogConfig", "unsigned short");
  declareArrayView<opendnp3::CounterConfig, uint16_t>(m, "CounterConfig", "unsigned short");
  declareArrayView<opendnp3::FrozenCounterConfig, uint16_t>(m, "FrozenCounterConfig", "unsigned short");
  declareArrayView<opendnp3::BOStatusConfig, uint16_t>(m, "BOStatusConfig", "unsigned short");
  declareArrayView<opendnp3::AOStatusConfig, uint16_t>(m, "AOStatusConfig", "unsigned short");
  declareArrayView<opendnp3::OctetStringConfig, uint16_t>(m, "OctetStringConfig", "unsigned short");
  declareArrayView<opendnp3::TimeAndIntervalConfig, uint16_t>(m, "TimeAndIntervalConfig", "unsigned short");
  declareArrayView<uint8_t, uint32_t>(m, "Buffer", "unsigned int");
}

#endif // PYDNP3_OPENPAL
#endif
