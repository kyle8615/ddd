#ifndef PYDNP3_OPENDNP3_GEN_EVENTSECURITYSTATVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTSECURITYSTATVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventSecurityStatVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventSecurityStatVariation(py::module& m)
{
  // ----- enum class: opendnp3::EventSecurityStatVariation
  py::enum_<opendnp3::EventSecurityStatVariation>(m, "EventSecurityStatVariation")
      .value("Group122Var1", opendnp3::EventSecurityStatVariation::Group122Var1)
      .value("Group122Var2", opendnp3::EventSecurityStatVariation::Group122Var2);
}

#endif // PYDNP3_OPENDNP3
#endif
