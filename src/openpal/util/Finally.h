#ifndef PYDNP3_OPENPAL_UTIL_FINALLY_H
#define PYDNP3_OPENPAL_UTIL_FINALLY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/util/Finally.h>

#ifdef PYDNP3_OPENPAL

template <class Cleanup>
void declareFinally(py::module& m, string const& type)
{
  // ----- class: openpal::RAII<Cleanup> -----
  py::class_<openpal::RAII<Cleanup>>(m, ("RAII" + type).c_str(),
      "Finally is an RAII helper that takes a functor to run when it destructs.");

  // ----- func: openpal::Finally<Cleanup> -----
  m.def(
      "Finally",
      &openpal::Finally<Cleanup>);
}

void bind_Finally(py::module& m)
{
}

#endif // PYDNP3_OPENPAL
#endif
