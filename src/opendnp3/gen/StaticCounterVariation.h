#ifndef PYDNP3_OPENDNP3_GEN_STATICCOUNTERVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICCOUNTERVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticCounterVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticCounterVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticCounterVariation -----
  py::enum_<opendnp3::StaticCounterVariation>(m, "StaticCounterVariation")
      .value("Group20Var1", opendnp3::StaticCounterVariation::Group20Var1)
      .value("Group20Var2", opendnp3::StaticCounterVariation::Group20Var2)
      .value("Group20Var5", opendnp3::StaticCounterVariation::Group20Var5)
      .value("Group20Var6", opendnp3::StaticCounterVariation::Group20Var6);
}

#endif // PYDNP3_OPENDNP3
#endif
