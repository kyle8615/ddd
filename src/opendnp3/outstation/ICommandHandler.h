#ifndef PYDNP3_OPENDNP3_OUTSTATION_ICOMMANDHANDLER_H
#define PYDNP3_OPENDNP3_OUTSTATION_ICOMMANDHANDLER_H

#include <Python.h>
#include <opendnp3/outstation/ICommandHandler.h>
#include <pybind11/pybind11.h>

#include "opendnp3/app/ITransactable.h"

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class ICommandHandler.
*/
class PyICommandHandler : public ICommandHandler {
  public:
  /* Inherit the constructors */
  using ICommandHandler::ICommandHandler;

  /* Trampoline for ITransactable virtual functions */
  void Start() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ICommandHandler,
        Start, );
  }
  void End() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ICommandHandler,
        End, );
  }

  /* Trampoline for ICommandHandler virtual functions */
  CommandStatus Select(const ControlRelayOutputBlock& command, uint16_t index) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Select,
        command, index);
  }
  CommandStatus Operate(const ControlRelayOutputBlock& command, uint16_t index, OperateType opType) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Operate,
        command, index, opType);
  }
  CommandStatus Select(const AnalogOutputInt16& command, uint16_t index) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Select,
        command, index);
  }
  CommandStatus Operate(const AnalogOutputInt16& command, uint16_t index, OperateType opType) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Operate,
        command, index, opType);
  }
  CommandStatus Select(const AnalogOutputInt32& command, uint16_t index) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Select,
        command, index);
  }
  CommandStatus Operate(const AnalogOutputInt32& command, uint16_t index, OperateType opType) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Operate,
        command, index, opType);
  }
  CommandStatus Select(const AnalogOutputFloat32& command, uint16_t index) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Select,
        command, index);
  }
  CommandStatus Operate(const AnalogOutputFloat32& command, uint16_t index, OperateType opType) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Operate,
        command, index, opType);
  }
  CommandStatus Select(const AnalogOutputDouble64& command, uint16_t index) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Select,
        command, index);
  }
  CommandStatus Operate(const AnalogOutputDouble64& command, uint16_t index, OperateType opType) override
  {
    PYBIND11_OVERLOAD_PURE(
        CommandStatus,
        ICommandHandler,
        Operate,
        command, index, opType);
  }
};
}

void bind_ICommandHandler(py::module& m)
{
  // ----- class: opendnp3::ICommandHandler -----
  py::class_<opendnp3::ICommandHandler,
      opendnp3::ITransactable,
      opendnp3::PyICommandHandler,
      std::shared_ptr<opendnp3::ICommandHandler>>(m, "ICommandHandler",
      "Interface used to dispatch SELECT / OPERATE / DIRECT OPERATE (Binary/Analog output) from the outstation "
      "to application code. \n"
      "The ITransactable sub-interface is used to determine the start and end of an ASDU containing commands.")

      .def(py::init<>())

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::ControlRelayOutputBlock&, uint16_t))
              & opendnp3::ICommandHandler::Select,
          "   Ask if the application supports a ControlRelayOutputBlock - group 12 variation 1. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::ControlRelayOutputBlock&,
              uint16_t,
              opendnp3::OperateType))
              & opendnp3::ICommandHandler::Operate,
          "   Operate a ControlRelayOutputBlock - group 12 variation 1. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":param opType: the operation type the outstation received \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"), py::arg("opType"))

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputInt16&, uint16_t))
              & opendnp3::ICommandHandler::Select,
          "   Ask if the application supports a 16 bit analog output - group 41 variation 2. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputInt16&,
              uint16_t,
              opendnp3::OperateType))
              & opendnp3::ICommandHandler::Operate,
          "   Ask if the application supports a 16 bit analog output - group 41 variation 2. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":param opType: the operation type the outstation received \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"), py::arg("opType"))

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputInt32&, uint16_t))
              & opendnp3::ICommandHandler::Select,
          "   Ask if the application supports a 32 bit analog output - group 41 variation 1. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputInt32&,
              uint16_t,
              opendnp3::OperateType))
              & opendnp3::ICommandHandler::Operate,
          "   Operate a 32 bit analog output - group 41 variation 1. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":param opType: the operation type the outstation received \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"), py::arg("opType"))

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputFloat32&, uint16_t))
              & opendnp3::ICommandHandler::Select,
          "   Ask if the application supports a single precision, floating point analog output - "
          "group 41 variation 3. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputFloat32&,
              uint16_t,
              opendnp3::OperateType))
              & opendnp3::ICommandHandler::Operate,
          "   Operate a single precision, floating point analog output - group 41 variation 3. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":param opType: the operation type the outstation received \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"), py::arg("opType"))

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputDouble64&, uint16_t))
              & opendnp3::ICommandHandler::Select,
          "   Ask if the application supports a double precision, floating point analog output - "
          "group 41 variation 4. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputDouble64&,
              uint16_t,
              opendnp3::OperateType))
              & opendnp3::ICommandHandler::Operate,
          "   Operate a double precision, floating point analog output - group 41 variation 4. \n"
          ":param command: command to operate \n"
          ":param index: index of the command \n"
          ":param opType: the operation type the outstation received \n"
          ":type index: unsigned short \n"
          ":return: result of request",
          py::arg("command"), py::arg("index"), py::arg("opType"));
}

#endif // PYDNP3_OPENDNP3
#endif
