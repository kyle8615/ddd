#ifndef PYDNP3_OPENDNP3_MASTER_COMMANDSET_H
#define PYDNP3_OPENDNP3_MASTER_COMMANDSET_H

#include <Python.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <opendnp3/master/CommandSet.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CommandSet(py::module& m)
{
  // ----- class: opendnp3::CommandSet -----
  py::class_<opendnp3::CommandSet, std::shared_ptr<opendnp3::CommandSet>>(m, "CommandSet",
      "Provides a mechanism for building a set of one or more command headers.")

      .def(
          py::init<>(),
          "Contrsuct an empty command set.")

      .def(
          py::init([](opendnp3::CommandSet& other) { return opendnp3::CommandSet(std::move(other)); }),
          "Construct a new command set and take ownership of the headers in argument.")

      .def(
          py::init([](std::vector<opendnp3::Indexed<opendnp3::ControlRelayOutputBlock>> items) {
            opendnp3::CommandSet commands = opendnp3::CommandSet();
            commands.Add<opendnp3::ControlRelayOutputBlock>(items);
            return commands;
          }),
          "Construct a command set from a list of CROB.",
          py::arg("items"))

      .def(
          py::init([](std::vector<opendnp3::Indexed<opendnp3::AnalogOutputInt16>> items) {
            opendnp3::CommandSet commands = opendnp3::CommandSet();
            commands.Add<opendnp3::AnalogOutputInt16>(items);
            return commands;
          }),
          "Construct a command set from a list of AOInt16.",
          py::arg("items"))

      .def(
          py::init([](std::vector<opendnp3::Indexed<opendnp3::AnalogOutputInt32>> items) {
            opendnp3::CommandSet commands = opendnp3::CommandSet();
            commands.Add<opendnp3::AnalogOutputInt32>(items);
            return commands;
          }),
          "Construct a command set from a list of AOInt32.",
          py::arg("items"))

      .def(
          py::init([](std::vector<opendnp3::Indexed<opendnp3::AnalogOutputFloat32>> items) {
            opendnp3::CommandSet commands = opendnp3::CommandSet();
            commands.Add<opendnp3::AnalogOutputFloat32>(items);
            return commands;
          }),
          "Construct a command set from a list of AOFloat32.",
          py::arg("items"))

      .def(
          py::init([](std::vector<opendnp3::Indexed<opendnp3::AnalogOutputDouble64>> items) {
            opendnp3::CommandSet commands = opendnp3::CommandSet();
            commands.Add<opendnp3::AnalogOutputDouble64>(items);
            return commands;
          }),
          "Construct a command set from a list of AODouble64.",
          py::arg("items"))

      .def(
          "Add",
          (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::ControlRelayOutputBlock>> items))
              & opendnp3::CommandSet::Add<opendnp3::ControlRelayOutputBlock>,
          py::arg("items"))

      .def(
          "Add",
          (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::AnalogOutputInt16>> items))
              & opendnp3::CommandSet::Add<opendnp3::AnalogOutputInt16>,
          py::arg("items"))

      .def(
          "Add",
          (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::AnalogOutputInt32>> items))
              & opendnp3::CommandSet::Add<opendnp3::AnalogOutputInt32>,
          py::arg("items"))

      .def(
          "Add",
          (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::AnalogOutputFloat32>> items))
              & opendnp3::CommandSet::Add<opendnp3::AnalogOutputFloat32>,
          py::arg("items"))

      .def(
          "Add",
          (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::AnalogOutputDouble64>> items))
              & opendnp3::CommandSet::Add<opendnp3::AnalogOutputDouble64>,
          py::arg("items"))

      .def(
          "StartHeader",
          &opendnp3::CommandSet::StartHeader<opendnp3::ControlRelayOutputBlock>,
          "Begin a header of the parameterized type.")

      .def(
          "StartHeader",
          &opendnp3::CommandSet::StartHeader<opendnp3::AnalogOutputInt16>,
          "Begin a header of the parameterized type.")

      .def(
          "StartHeader",
          &opendnp3::CommandSet::StartHeader<opendnp3::AnalogOutputInt32>,
          "Begin a header of the parameterized type.")

      .def(
          "StartHeader",
          &opendnp3::CommandSet::StartHeader<opendnp3::AnalogOutputFloat32>,
          "Begin a header of the parameterized type.")

      .def(
          "StartHeader",
          &opendnp3::CommandSet::StartHeader<opendnp3::AnalogOutputDouble64>,
          "Begin a header of the parameterized type.");
}

#endif // PYDNP3_OPENDNP3
#endif
