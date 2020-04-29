#ifndef PYDNP3_OPENPAL_SERIALIZATION_SERIALIZER_H
#define PYDNP3_OPENPAL_SERIALIZATION_SERIALIZER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/AnalogOutput.h>
#include <opendnp3/app/MeasurementTypes.h>
#include <openpal/serialization/Serializer.h>

#ifdef PYDNP3_OPENPAL

template <class T>
void declareSerializer(py::module& m, std::string const& type)
{
  typedef bool (*ReadFunc)(openpal::RSlice & buffer, T & output);
  typedef bool (*WriteFunc)(const T& value, openpal::WSlice& buffer);

  // ----- class: openpal::Serializer<T> -----
  py::class_<openpal::Serializer<T>>(m, ("Serializer" + type).c_str())

      .def(py::init<>())

      .def(
          py::init<uint32_t, ReadFunc, WriteFunc>(),
          py::arg("size"), py::arg("pReadFunc"), py::arg("pWriteFunc"))

      .def(
          "Size",
          &openpal::Serializer<T>::Size,
          ":return: the size (in bytes) required for every call to read/write")

      .def(
          "Read",
          &openpal::Serializer<T>::Read,
          "Read the value and advances the read buffer.",
          py::arg("buffer"), py::arg("output"))

      .def(
          "Write",
          &openpal::Serializer<T>::Write,
          "Write the value and advances the write buffer.",
          py::arg("value"), py::arg("buffer"));
}

void bind_Serializer(py::module& m)
{
  declareSerializer<opendnp3::Binary>(m, "Binary");
  declareSerializer<opendnp3::DoubleBitBinary>(m, "DoubleBitBinary");
  declareSerializer<opendnp3::BinaryOutputStatus>(m, "BinaryOutputStatus");
  declareSerializer<opendnp3::Analog>(m, "Analog");
  declareSerializer<opendnp3::Counter>(m, "Counter");
  declareSerializer<opendnp3::FrozenCounter>(m, "FrozenCounter");
  declareSerializer<opendnp3::AnalogOutputStatus>(m, "AnalogOutputStatus");
  declareSerializer<opendnp3::TimeAndInterval>(m, "TimeAndInterval");
  declareSerializer<opendnp3::AnalogOutputInt16>(m, "AnalogOutputInt16");
  declareSerializer<opendnp3::AnalogOutputInt32>(m, "AnalogOutputInt32");
  declareSerializer<opendnp3::AnalogOutputFloat32>(m, "AnalogOutputFloat32");
  declareSerializer<opendnp3::AnalogOutputDouble64>(m, "AnalogOutputDouble64");
}

#endif // PYDNP3_OPENPAL
#endif
