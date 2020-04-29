#ifndef PYDNP3_OPENDNP3_GEN_STATICFROZENCOUNTERVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICFROZENCOUNTERVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticFrozenCounterVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticFrozenCounterVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticFrozenCounterVariation
  py::enum_<opendnp3::StaticFrozenCounterVariation>(m, "StaticFrozenCounterVariation")
      .value("Group21Var1", opendnp3::StaticFrozenCounterVariation::Group21Var1)
      .value("Group21Var2", opendnp3::StaticFrozenCounterVariation::Group21Var2)
      .value("Group21Var5", opendnp3::StaticFrozenCounterVariation::Group21Var5)
      .value("Group21Var6", opendnp3::StaticFrozenCounterVariation::Group21Var6)
      .value("Group21Var9", opendnp3::StaticFrozenCounterVariation::Group21Var9)
      .value("Group21Var10", opendnp3::StaticFrozenCounterVariation::Group21Var10);
}

#endif // PYDNP3_OPENDNP3
#endif
