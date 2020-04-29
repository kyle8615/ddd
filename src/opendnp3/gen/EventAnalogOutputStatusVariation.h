#ifndef PYDNP3_OPENDNP3_GEN_EVENTANALOGOUTPUTSTATUSVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTANALOGOUTPUTSTATUSVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventAnalogOutputStatusVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventAnalogOutputStatusVariation(py::module& m)
{
  // ----- enum class: opendnp3::EventAnalogOutputStatusVariation
  py::enum_<opendnp3::EventAnalogOutputStatusVariation>(m, "EventAnalogOutputStatusVariation")
      .value("Group42Var1", opendnp3::EventAnalogOutputStatusVariation::Group42Var1)
      .value("Group42Var2", opendnp3::EventAnalogOutputStatusVariation::Group42Var2)
      .value("Group42Var3", opendnp3::EventAnalogOutputStatusVariation::Group42Var3)
      .value("Group42Var4", opendnp3::EventAnalogOutputStatusVariation::Group42Var4)
      .value("Group42Var5", opendnp3::EventAnalogOutputStatusVariation::Group42Var5)
      .value("Group42Var6", opendnp3::EventAnalogOutputStatusVariation::Group42Var6)
      .value("Group42Var7", opendnp3::EventAnalogOutputStatusVariation::Group42Var7)
      .value("Group42Var8", opendnp3::EventAnalogOutputStatusVariation::Group42Var8);
}

#endif // PYDNP3_OPENDNP3
#endif
