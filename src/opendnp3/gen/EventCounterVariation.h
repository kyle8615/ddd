#ifndef PYDNP3_OPENDNP3_GEN_EVENTCOUNTERVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTCOUNTERVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventCounterVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventCounterVariation(py::module& m)
{
  // ----- enum class: opendnp3::EventCounterVariation
  py::enum_<opendnp3::EventCounterVariation>(m, "EventCounterVariation")
      .value("Group22Var1", opendnp3::EventCounterVariation::Group22Var1)
      .value("Group22Var2", opendnp3::EventCounterVariation::Group22Var2)
      .value("Group22Var5", opendnp3::EventCounterVariation::Group22Var5)
      .value("Group22Var6", opendnp3::EventCounterVariation::Group22Var6);
}

#endif // PYDNP3_OPENDNP3
#endif
