#ifndef PYDNP3_OPENDNP3_APP_IINFIELD_H
#define PYDNP3_OPENDNP3_APP_IINFIELD_H

#include <opendnp3/app/IINField.h>
#include <pybind11/operators.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_IINField(py::module& m)
{
  // ----- enum class: opendnp3::IINBit-----
  py::enum_<opendnp3::IINBit>(m, "IINBit")
      .value("ALL_STATIONS", opendnp3::IINBit::ALL_STATIONS)
      .value("CLASS1_EVENTS", opendnp3::IINBit::CLASS1_EVENTS)
      .value("CLASS2_EVENTS", opendnp3::IINBit::CLASS2_EVENTS)
      .value("CLASS3_EVENTS", opendnp3::IINBit::CLASS3_EVENTS)
      .value("NEED_TIME", opendnp3::IINBit::NEED_TIME)
      .value("LOCAL_CONTROL", opendnp3::IINBit::LOCAL_CONTROL)
      .value("DEVICE_TROUBLE", opendnp3::IINBit::DEVICE_TROUBLE)
      .value("DEVICE_RESTART", opendnp3::IINBit::DEVICE_RESTART)
      .value("FUNC_NOT_SUPPORTED", opendnp3::IINBit::FUNC_NOT_SUPPORTED)
      .value("OBJECT_UNKNOWN", opendnp3::IINBit::OBJECT_UNKNOWN)
      .value("PARAM_ERROR", opendnp3::IINBit::PARAM_ERROR)
      .value("EVENT_BUFFER_OVERFLOW", opendnp3::IINBit::EVENT_BUFFER_OVERFLOW)
      .value("ALREADY_EXECUTING", opendnp3::IINBit::ALREADY_EXECUTING)
      .value("CONFIG_CORRUPT", opendnp3::IINBit::CONFIG_CORRUPT)
      .value("RESERVED1", opendnp3::IINBit::RESERVED1)
      .value("RESERVED2", opendnp3::IINBit::RESERVED2);

  // ----- class: opendnp3::IINField-----
  py::class_<opendnp3::IINField>(m, "IINField",
      "DNP3 two-byte IIN field.")

      .def(
          py::init<opendnp3::IINBit>(),
          py::arg("bit"))

      .def(
          py::init<uint8_t, uint8_t>(),
          py::arg("aLSB") = 0, py::arg("aMSB") = 0)

      .def_static(
          "Empty",
          &opendnp3::IINField::Empty)

      .def(
          "IsSet",
          &opendnp3::IINField::IsSet,
          py::arg("bit"))

      .def(
          "IsClear",
          &opendnp3::IINField::IsClear,
          py::arg("bit"))

      .def(
          "SetBit",
          &opendnp3::IINField::SetBit,
          py::arg("bit"))

      .def(
          "ClearBit",
          &opendnp3::IINField::ClearBit,
          py::arg("bit"))

      .def(
          "SetBitToValue",
          &opendnp3::IINField::SetBitToValue,
          py::arg("bit"), py::arg("value"))

      .def(
          "Any",
          &opendnp3::IINField::Any)

      .def(
          "Clear",
          (void (opendnp3::IINField::*)()) & opendnp3::IINField::Clear)

      .def(
          "HasRequestError",
          &opendnp3::IINField::HasRequestError)

      .def(
          "__eq__",
          &opendnp3::IINField::operator==)

      .def(
          "__or__",
          &opendnp3::IINField::operator|)

      .def(
          "__ior__",
          &opendnp3::IINField::operator|=)

      .def(
          "__and__",
          &opendnp3::IINField::operator&)

      .def(
          "__iand__",
          &opendnp3::IINField::operator&=)

      .def(
          "__invert__",
          &opendnp3::IINField::operator~)

      .def_readwrite(
          "MSB",
          &opendnp3::IINField::MSB,
          ":type MSB: unsigned char")

      .def_readwrite(
          "LSB",
          &opendnp3::IINField::LSB,
          ":type LSB: unsigned char");
}

#endif // PYDNP3_OPENDNP3
#endif
