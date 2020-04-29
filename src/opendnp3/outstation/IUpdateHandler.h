#ifndef PYDNP3_OPENDNP3_OUTSTATION_IUPDATEHANDLER_H
#define PYDNP3_OPENDNP3_OUTSTATION_IUPDATEHANDLER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/IUpdateHandler.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class IUpdateHandler.
*/
class PyIUpdateHandler : public IUpdateHandler {
  public:
  /* Inherit the constructors */
  using IUpdateHandler::IUpdateHandler;

  /* Trampoline for IUpdateHandler virtual functions */
  bool Update(const Binary& meas, uint16_t index, EventMode mode = EventMode::Detect) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Update,
        meas, index, mode);
  }
  bool Update(const DoubleBitBinary& meas, uint16_t index, EventMode mode = EventMode::Detect) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Update,
        meas, index, mode);
  }
  bool Update(const Analog& meas, uint16_t index, EventMode mode = EventMode::Detect) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Update,
        meas, index, mode);
  }
  bool Update(const Counter& meas, uint16_t index, EventMode mode = EventMode::Detect) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Update,
        meas, index, mode);
  }
  bool Update(const FrozenCounter& meas, uint16_t index, EventMode mode = EventMode::Detect) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Update,
        meas, index, mode);
  }
  bool Update(const BinaryOutputStatus& meas, uint16_t index, EventMode mode = EventMode::Detect) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Update,
        meas, index, mode);
  }
  bool Update(const AnalogOutputStatus& meas, uint16_t index, EventMode mode = EventMode::Detect) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Update,
        meas, index, mode);
  }
  bool Update(const OctetString& meas, uint16_t index, EventMode mode = EventMode::Detect) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Update,
        meas, index, mode);
  }
  bool Update(const TimeAndInterval& meas, uint16_t index) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Update,
        meas, index);
  }
  bool Modify(FlagsType type, uint16_t start, uint16_t stop, uint8_t flags) override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IUpdateHandler,
        Modify,
        type, start, stop, flags);
  }
};
}

void bind_IUpdateHandler(py::module& m)
{
  // ----- class: opendnp3::IUpdateHandler -----
  py::class_<opendnp3::IUpdateHandler, opendnp3::PyIUpdateHandler>(m, "IUpdateHandler",
      "An interface used to update measurement values.")

      .def(py::init<>())

      .def(
          "Update",
          (bool (opendnp3::IUpdateHandler::*)(const opendnp3::Binary&, uint16_t, opendnp3::EventMode))
              & opendnp3::IUpdateHandler::Update,
          "   Update a Binary measurement. \n"
          ":param meas: measurement to be processed \n"
          ":param index: index of the measurement \n"
          ":param mode Describes how event generation is handled for this method \n"
          ":type index: unsigned short \n"
          ":return: true if the value exists and it was updated",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          (bool (opendnp3::IUpdateHandler::*)(const opendnp3::DoubleBitBinary&, uint16_t, opendnp3::EventMode))
              & opendnp3::IUpdateHandler::Update,
          "   Update a DoubleBitBinary measurement. \n"
          ":param meas: measurement to be processed \n"
          ":param index: index of the measurement \n"
          ":param mode Describes how event generation is handled for this method \n"
          ":type index: unsigned short \n"
          ":return: true if the value exists and it was updated",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update", (bool (opendnp3::IUpdateHandler::*)(const opendnp3::Analog&, uint16_t, opendnp3::EventMode)) & opendnp3::IUpdateHandler::Update,
          "   Update a Analog measurement. \n"
          ":param meas: measurement to be processed \n"
          ":param index: index of the measurement \n"
          ":param mode Describes how event generation is handled for this method \n"
          ":type index: unsigned short \n"
          ":return: true if the value exists and it was updated",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          (bool (opendnp3::IUpdateHandler::*)(const opendnp3::Counter&, uint16_t, opendnp3::EventMode))
              & opendnp3::IUpdateHandler::Update,
          "   Update a Counter measurement. \n"
          ":param meas: measurement to be processed \n"
          ":param index: index of the measurement \n"
          ":param mode Describes how event generation is handled for this method \n"
          ":type index: unsigned short \n"
          ":return: true if the value exists and it was updated",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          (bool (opendnp3::IUpdateHandler::*)(const opendnp3::FrozenCounter&, uint16_t, opendnp3::EventMode))
              & opendnp3::IUpdateHandler::Update,
          "   Update a FrozenCounter measurement. \n"
          ":param meas: measurement to be processed \n"
          ":param index: index of the measurement \n"
          ":param mode Describes how event generation is handled for this method \n"
          ":type index: unsigned short \n"
          ":return: true if the value exists and it was updated",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          (bool (opendnp3::IUpdateHandler::*)(const opendnp3::BinaryOutputStatus&, uint16_t, opendnp3::EventMode))
              & opendnp3::IUpdateHandler::Update,
          "   Update a BinaryOutputStatus measurement. \n"
          ":param meas: measurement to be processed \n"
          ":param index: index of the measurement \n"
          ":param mode Describes how event generation is handled for this method \n"
          ":type index: unsigned short \n"
          ":return: true if the value exists and it was updated",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          (bool (opendnp3::IUpdateHandler::*)(const opendnp3::AnalogOutputStatus&, uint16_t, opendnp3::EventMode))
              & opendnp3::IUpdateHandler::Update,
          "   Update a AnalogOutputStatus measurement. \n"
          ":param meas: measurement to be processed \n"
          ":param index: index of the measurement \n"
          ":param mode Describes how event generation is handled for this method \n"
          ":type index: unsigned short \n"
          ":return: true if the value exists and it was updated",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          (bool (opendnp3::IUpdateHandler::*)(const opendnp3::OctetString&, uint16_t, opendnp3::EventMode))
              & opendnp3::IUpdateHandler::Update,
          "   Update an octet string value. \n"
          ":param meas: measurement to be processed \n"
          ":param index: index of the measurement \n"
          ":param mode Describes how event generation is handled for this method \n"
          ":type index: unsigned short \n"
          ":return: true if the value exists and it was updated",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          (bool (opendnp3::IUpdateHandler::*)(const opendnp3::TimeAndInterval&, uint16_t))
              & opendnp3::IUpdateHandler::Update,
          "   Update a TimeAndInterval valueindex. \n"
          ":param meas: measurement to be processed \n"
          ":param index: index of the measurement \n"
          ":type index: unsigned short \n"
          ":return: true if the value exists and it was updated",
          py::arg("measurement"), py::arg("index"))

      .def(
          "Modify",
          &opendnp3::IUpdateHandler::Modify,
          "   Update the flags of a measurement without changing it's value. \n"
          ":param type: enumeration specifiy the type to change \n"
          ":param start: the start index at which to begin changing flags \n"
          ":param stop: the stop index at which to end changing flags \n"
          ":param flags: the new value of the flags \n"
          ":type start: unsigned short \n"
          ":type stop: unsigned short",
          py::arg("type"), py::arg("start"), py::arg("stop"), py::arg("flags"));
}

#endif // PYDNP3_OPENDNP3
#endif
