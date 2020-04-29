#ifndef PYDNP3_OPENDNP3_GEN_FLOWCONTROL_H
#define PYDNP3_OPENDNP3_GEN_FLOWCONTROL_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/FlowControl.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_FlowControl(py::module& m)
{
  // ----- enum class: opendnp3::FlowControl -----
  py::enum_<opendnp3::FlowControl>(m, "FlowControl",
      "Enumeration for setting serial port flow control.")

      .value("Hardware", opendnp3::FlowControl::Hardware)
      .value("XONXOFF", opendnp3::FlowControl::XONXOFF)
      .value("None", opendnp3::FlowControl::None);

  // ----- function: opendnp3::FlowControlToType -----
  m.def(
      "FlowControlToType",
      &opendnp3::FlowControlToType,
      py::arg("flowControl"));

  // ----- function: opendnp3::FlowControlFromType -----
  m.def(
      "FlowControlFromType",
      &opendnp3::FlowControlFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::FlowControlToString -----
  m.def(
      "FlowControlToString",
      &opendnp3::FlowControlToString,
      py::arg("flowControl"));
}

#endif // PYDNP3_OPENDNP3
#endif
