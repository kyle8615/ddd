#ifndef PYDNP3_OPENDNP3_GEN_ATTRIBUTES_H
#define PYDNP3_OPENDNP3_GEN_ATTRIBUTES_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/Attributes.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_Attributes(py::module& m)
{
  // ----- func: opendnp3::HasAbsoluteTime -----
  m.def(
      "HasAbsoluteTime",
      &opendnp3::HasAbsoluteTime,
      py::arg("gv"));

  // ----- func: opendnp3::HasRelativeTime -----
  m.def(
      "HasRelativeTime",
      &opendnp3::HasRelativeTime,
      py::arg("gv"));

  // ----- func: opendnp3::HasFlags -----
  m.def(
      "HasFlags",
      &opendnp3::HasFlags,
      py::arg("gv"));

  // ----- func: opendnp3::IsEvent -----
  m.def(
      "IsEvent",
      (bool (*)(opendnp3::GroupVariation))
          & opendnp3::IsEvent,
      py::arg("gv"));
}

#endif // PYDNP3_OPENDNP3
#endif
