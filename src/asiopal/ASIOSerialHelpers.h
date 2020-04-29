#ifndef PYDNP3_ASIOPAL_ASIOSERIALHELPERS_H
#define PYDNP3_ASIOPAL_ASIOSERIALHELPERS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/ASIOSerialHelpers.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_ASIOSerialHelpers(py::module& m)
{
  // ----- func: asiopal::Configure -----
  m.def(
      "Configure",
      &asiopal::Configure,
      "Serial port configuration functions free to keep the classes simple.",
      py::arg("settings"), py::arg("port"), py::arg("ec"));
}

#endif // PYDNP3_ASIOPAL
#endif
