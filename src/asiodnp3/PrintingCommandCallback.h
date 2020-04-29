#ifndef PYDNP3_ASIODNP3_PRINTINGCOMMANDCALLBACK_H
#define PYDNP3_ASIODNP3_PRINTINGCOMMANDCALLBACK_H

#include <Python.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/PrintingCommandCallback.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_PrintingCommandCallback(py::module& m)
{
  // ----- class: asiodnp3::PrintingCommandCallback -----
  py::class_<asiodnp3::PrintingCommandCallback, openpal::StaticOnly>(m, "PrintingCommandCallback")

      .def_static(
          "Get",
          &asiodnp3::PrintingCommandCallback::Get);
}

#endif // PYDNP3_ASIODNP3
#endif
