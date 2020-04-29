#ifndef PYDNP3_OPENDNP3_GEN_STATICOCTETSTRINGVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICOCTETSTRINGVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticSecurityStatVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticOctetStringVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticOctetStringVariation
  py::enum_<opendnp3::StaticOctetStringVariation>(m, "StaticOctetStringVariation")
      .value("Group110Var0", opendnp3::StaticOctetStringVariation::Group110Var0);
}

#endif // PYDNP3_OPENDNP3
#endif
