#ifndef PYDNP3_ASIODNP3_PRINTINGSOEHANDLER_H
#define PYDNP3_ASIODNP3_PRINTINGSOEHANDLER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/PrintingSOEHandler.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_PrintingSOEHandler(py::module& m)
{
  // ----- class: asiodnp3::PrintingSOEHandler -----
  py::class_<asiodnp3::PrintingSOEHandler,
      opendnp3::ISOEHandler,
      std::shared_ptr<asiodnp3::PrintingSOEHandler>>(m, "PrintingSOEHandler",
      "ISOEHandler singleton that prints to the console.")

      .def(py::init<>())

      .def_static(
          "Create",
          &asiodnp3::PrintingSOEHandler::Create,
          ":return: shared_ptr to opendnp3.ISOEHandler")

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Binary>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::DoubleBitBinary>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Analog>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Counter>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::FrozenCounter>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryOutputStatus>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogOutputStatus>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::OctetString>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::TimeAndInterval>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryCommandEvent>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogCommandEvent>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::SecurityStat>>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"))

      .def(
          "Process",
          (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
              const opendnp3::ICollection<opendnp3::DNPTime>&))
              & asiodnp3::PrintingSOEHandler::Process,
          py::arg("info"), py::arg("values"));
}

#endif // PYDNP3_ASIODNP3
#endif
