#ifndef PYDNP3_OPENPAL_UTIL_TOHEX_H
#define PYDNP3_OPENPAL_UTIL_TOHEX_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/util/ToHex.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_ToHex(py::module& m)
{
  // ----- function: openpal::ToHexChar -----
  m.def(
      "ToHexChar",
      &openpal::ToHexChar,
      py::arg("char"));
}

#endif // PYDNP3_OPENPAL
#endif
