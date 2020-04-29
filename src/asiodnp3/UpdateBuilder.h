#ifndef PYDNP3_ASIODNP3_UPDATEBUILDER_H
#define PYDNP3_ASIODNP3_UPDATEBUILDER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/UpdateBuilder.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_UpdateBuilder(py::module& m)
{
  // ----- class: asiodnp3::UpdateBuilder -----
  py::class_<asiodnp3::UpdateBuilder>(m, "UpdateBuilder")

      .def(py::init<>())

      .def(
          "Update",
          [](asiodnp3::UpdateBuilder& self,
              const opendnp3::Binary& meas,
              uint16_t index,
              opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder& { return self.Update(meas, index, mode); },
          ":param mode: defaults to opendnp3.EventMode.Detect \n"
          ":type index: unsigned short",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          [](asiodnp3::UpdateBuilder& self,
              const opendnp3::DoubleBitBinary& meas,
              uint16_t index,
              opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder& { return self.Update(meas, index, mode); },
          ":param mode: defaults to opendnp3.EventMode.Detect \n"
          ":type index: unsigned short",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          [](asiodnp3::UpdateBuilder& self,
              const opendnp3::Analog& meas,
              uint16_t index,
              opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder& { return self.Update(meas, index, mode); },
          ":param mode: defaults to opendnp3.EventMode.Detect \n"
          ":type index: unsigned short",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          [](asiodnp3::UpdateBuilder& self,
              const opendnp3::Counter& meas,
              uint16_t index,
              opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder& { return self.Update(meas, index, mode); },
          ":param mode: defaults to opendnp3.EventMode.Detect \n"
          ":type index: unsigned short",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          [](asiodnp3::UpdateBuilder& self,
              const opendnp3::FrozenCounter& meas,
              uint16_t index,
              opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder& { return self.Update(meas, index, mode); },
          ":param mode: defaults to opendnp3.EventMode.Detect \n"
          ":type index: unsigned short",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          [](asiodnp3::UpdateBuilder& self,
              const opendnp3::BinaryOutputStatus& meas,
              uint16_t index,
              opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder& { return self.Update(meas, index, mode); },
          ":param mode: defaults to opendnp3.EventMode.Detect \n"
          ":type index: unsigned short",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          [](asiodnp3::UpdateBuilder& self,
              const opendnp3::AnalogOutputStatus& meas,
              uint16_t index,
              opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder& { return self.Update(meas, index, mode); },
          ":param mode: defaults to opendnp3.EventMode.Detect \n"
          ":type index: unsigned short",
          py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect)

      .def(
          "Update",
          [](asiodnp3::UpdateBuilder& self,
              const opendnp3::TimeAndInterval& meas,
              uint16_t index) -> asiodnp3::UpdateBuilder& { return self.Update(meas, index); },
          ":type index: unsigned short",
          py::arg("measurement"), py::arg("index"))

      .def(
          "Update",
          [](asiodnp3::UpdateBuilder& self,
              const opendnp3::OctetString& meas,
              uint16_t index) -> asiodnp3::UpdateBuilder& { return self.Update(meas, index); },
          ":type index: unsigned short",
          py::arg("measurement"), py::arg("index"))

      .def(
          "Modify",
          &asiodnp3::UpdateBuilder::Modify,
          ":type start: unsigned short \n"
          ":type stop: unsigned short \n"
          ":type flags: unsigned char",
          py::arg("type"), py::arg("start"), py::arg("stop"), py::arg("flags"))

      .def(
          "Build",
          &asiodnp3::UpdateBuilder::Build);
}

#endif // PYDNP3_ASIODNP3
#endif
