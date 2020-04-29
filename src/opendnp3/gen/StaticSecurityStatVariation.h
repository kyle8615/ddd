#ifndef PYDNP3_OPENDNP3_GEN_STATICSECURITYSTATVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICSECURITYSTATVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticSecurityStatVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticSecurityStatVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticSecurityStatVariation
  py::enum_<opendnp3::StaticSecurityStatVariation>(m, "StaticSecurityStatVariation")
      .value("Group121Var1", opendnp3::StaticSecurityStatVariation::Group121Var1);
}

#endif // PYDNP3_OPENDNP3
#endif
