#ifndef PYDNP3_OPENDNP3_OUTSTATION_SIMPLECOMMANDHANDLER_H
#define PYDNP3_OPENDNP3_OUTSTATION_SIMPLECOMMANDHANDLER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/SimpleCommandHandler.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_SimpleCommandHandler(py::module& m)
{
  // ----- class: opendnp3::SimpleCommandHandler -----
  py::class_<opendnp3::SimpleCommandHandler,
      opendnp3::ICommandHandler,
      std::shared_ptr<opendnp3::SimpleCommandHandler>>(m, "SimpleCommandHandler",
      "Mock ICommandHandler used for examples and demos.")

      .def(
          py::init<opendnp3::CommandStatus>(),
          ":param status: The status value to return in response to all commands")

      .def_readwrite(
          "numOperate",
          &opendnp3::SimpleCommandHandler::numOperate,
          ":type numOperate: unsigned int")

      .def_readwrite(
          "numSelect",
          &opendnp3::SimpleCommandHandler::numSelect,
          ":type numSelect: unsigned int")

      .def_readwrite(
          "numStart",
          &opendnp3::SimpleCommandHandler::numStart,
          ":type numStart: unsigned int")

      .def_readwrite(
          "numEnd",
          &opendnp3::SimpleCommandHandler::numEnd,
          ":type numEnd: unsigned int")

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::ControlRelayOutputBlock&,
              unsigned short))
              & opendnp3::SimpleCommandHandler::Select,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::ControlRelayOutputBlock&,
              unsigned short,
              opendnp3::OperateType))
              & opendnp3::SimpleCommandHandler::Operate,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"), py::arg("opType"))

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputInt16&,
              unsigned short))
              & opendnp3::SimpleCommandHandler::Select,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputInt16&,
              unsigned short,
              opendnp3::OperateType))
              & opendnp3::SimpleCommandHandler::Operate,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"), py::arg("opType"))

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputInt32&,
              unsigned short))
              & opendnp3::SimpleCommandHandler::Select,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputInt32&,
              unsigned short,
              opendnp3::OperateType))
              & opendnp3::SimpleCommandHandler::Operate,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"), py::arg("opType"))

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputFloat32&,
              unsigned short))
              & opendnp3::SimpleCommandHandler::Select,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputFloat32&,
              unsigned short,
              opendnp3::OperateType))
              & opendnp3::SimpleCommandHandler::Operate,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"), py::arg("opType"))

      .def(
          "Select",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputDouble64&,
              unsigned short))
              & opendnp3::SimpleCommandHandler::Select,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"))

      .def(
          "Operate",
          (opendnp3::CommandStatus(opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputDouble64&,
              unsigned short,
              opendnp3::OperateType))
              & opendnp3::SimpleCommandHandler::Operate,
          ":type index: unsigned short",
          py::arg("command"), py::arg("index"), py::arg("opType"));

  // ----- class: opendnp3::SuccessCommandHandler -----
  py::class_<opendnp3::SuccessCommandHandler,
      opendnp3::SimpleCommandHandler,
      std::shared_ptr<opendnp3::SuccessCommandHandler>>(m, "SuccessCommandHandler",
      "A singleton command handler that always returns success.")

      .def(py::init<>())

      .def_static(
          "Create",
          &opendnp3::SuccessCommandHandler::Create,
          ":return: shared_ptr to opendnp3.ICommandHandler");
}

#endif // PYDNP3_OPENDNP3
#endif
