#ifndef PYDNP3_OPENPAL_CONFIGURE_H
#define PYDNP3_OPENPAL_CONFIGURE_H

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/Configure.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Configure(py::module& m)
{
  // ----- const: openpal::sizes::MAX_ERASURE_SIZE -----
  m.def_submodule("sizes").attr("MAX_ERASURE_SIZE") = &openpal::sizes::MAX_ERASURE_SIZE;
}

#endif // PYDNP3_OPENPAL
#endif
