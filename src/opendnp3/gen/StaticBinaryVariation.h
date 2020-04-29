#ifndef PYDNP3_OPENDNP3_GEN_STATICBINARYVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICBINARYVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticBinaryVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticBinaryVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticBinaryVariation -----
  py::enum_<opendnp3::StaticBinaryVariation>(m, "StaticBinaryVariation")
      .value("Group1Var1", opendnp3::StaticBinaryVariation::Group1Var1)
      .value("Group1Var2", opendnp3::StaticBinaryVariation::Group1Var2);
}

#endif // PYDNP3_OPENDNP3
#endif
