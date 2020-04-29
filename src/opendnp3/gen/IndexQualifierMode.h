#ifndef PYDNP3_OPENDNP3_GEN_INDEXQUALIFIERMODE_H
#define PYDNP3_OPENDNP3_GEN_INDEXQUALIFIERMODE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/IndexQualifierMode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_IndexQualifierMode(py::module& m)
{
  // ----- enum class: opendnp3::StaticSecurityStatVariation
  py::enum_<opendnp3::IndexQualifierMode>(m, "IndexQualifierMode")
      .value(
          "allow_one_byte",
          opendnp3::IndexQualifierMode::allow_one_byte,
          "Use a one byte qualifier if possible")

      .value(
          "allow_one_byte",
          opendnp3::IndexQualifierMode::allow_one_byte,
          "Always use two byte qualifiers even if the index is less than or equal to 255");
}

#endif // PYDNP3_OPENDNP3
#endif
