#ifndef PYDNP3_OPENDNP3_GEN_EVENTFROZENCOUNTERVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTFROZENCOUNTERVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventFrozenCounterVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventFrozenCounterVariation(py::module& m)
{
  // ----- enum class: opendnp3::EventFrozenCounterVariation
  py::enum_<opendnp3::EventFrozenCounterVariation>(m, "EventFrozenCounterVariation")
      .value("Group23Var1", opendnp3::EventFrozenCounterVariation::Group23Var1)
      .value("Group23Var2", opendnp3::EventFrozenCounterVariation::Group23Var2)
      .value("Group23Var5", opendnp3::EventFrozenCounterVariation::Group23Var5)
      .value("Group23Var6", opendnp3::EventFrozenCounterVariation::Group23Var6);
}

#endif // PYDNP3_OPENDNP3
#endif
