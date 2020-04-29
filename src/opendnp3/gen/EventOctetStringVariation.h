#ifndef PYDNP3_OPENDNP3_GEN_EVENTOCTETSTRINGVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTOCTETSTRINGVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventOctetStringVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventOctetStringVariation(py::module& m)
{
  // ----- enum class: opendnp3::EventOctetStringVariation
  py::enum_<opendnp3::EventOctetStringVariation>(m, "EventOctetStringVariation")
      .value("Group111Var0", opendnp3::EventOctetStringVariation::Group111Var0);
}

#endif // PYDNP3_OPENDNP3
#endif
