#ifndef PYDNP3_OPENDNP3_OUTSTATION_APPLICATIONIIN_H
#define PYDNP3_OPENDNP3_OUTSTATION_APPLICATIONIIN_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/ApplicationIIN.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_ApplicationIIN(py::module& m)
{
  // ----- class: opendnp3::ApplicationIIN -----
  py::class_<opendnp3::ApplicationIIN>(m, "ApplicationIIN",
      "Some IIN bits are necessarily controlled by the outstation application, not the underlying protocol stack. \n"
      "This structure describes the state of the bits controllable by the application.")

      .def(py::init<>())

      .def_readwrite(
          "needTime",
          &opendnp3::ApplicationIIN::needTime)

      .def_readwrite(
          "localControl",
          &opendnp3::ApplicationIIN::localControl)

      .def_readwrite(
          "deviceTrouble",
          &opendnp3::ApplicationIIN::deviceTrouble)

      .def_readwrite(
          "configCorrupt",
          &opendnp3::ApplicationIIN::configCorrupt)

      .def_readwrite(
          "eventBufferOverflow",
          &opendnp3::ApplicationIIN::eventBufferOverflow)

      .def(
          "ToIIN",
          &opendnp3::ApplicationIIN::ToIIN);
}

#endif // PYDNP3_OPENDNP3
#endif
