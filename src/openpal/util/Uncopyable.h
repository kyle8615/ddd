#ifndef PYDNP3_OPENPAL_UTIL_UNCOPYABLE_H
#define PYDNP3_OPENPAL_UTIL_UNCOPYABLE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/util/Uncopyable.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Uncopyable(py::module& m)
{
  // ----- class: openpal::Uncopyable -----
  py::class_<openpal::Uncopyable, std::unique_ptr<openpal::Uncopyable, py::nodelete>>(m, "Uncopyable",
      "Inherited classes will not have default copy/assignment.");

  // ----- class: openpal::StaticOnly -----
  py::class_<openpal::StaticOnly>(m, "StaticOnly");
}

#endif // PYDNP3_OPENPAL
#endif
