#ifndef PYDNP3_OPENDNP3_GEN_EVENTANALOGVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTANALOGVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventAnalogVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventAnalogVariation(py::module& m)
{
  // ----- enum class: opendnp3::EventAnalogVariation -----
  py::enum_<opendnp3::EventAnalogVariation>(m, "EventAnalogVariation")
      .value("Group32Var1", opendnp3::EventAnalogVariation::Group32Var1)
      .value("Group32Var2", opendnp3::EventAnalogVariation::Group32Var2)
      .value("Group32Var3", opendnp3::EventAnalogVariation::Group32Var3)
      .value("Group32Var4", opendnp3::EventAnalogVariation::Group32Var4)
      .value("Group32Var5", opendnp3::EventAnalogVariation::Group32Var5)
      .value("Group32Var6", opendnp3::EventAnalogVariation::Group32Var6)
      .value("Group32Var7", opendnp3::EventAnalogVariation::Group32Var7)
      .value("Group32Var8", opendnp3::EventAnalogVariation::Group32Var8);
}

#endif // PYDNP3_OPENDNP3
#endif
