#ifndef PYDNP3_OPENDNP3_GEN_EVENTDOUBLEBINARYVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTDOUBLEBINARYVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventDoubleBinaryVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventDoubleBinaryVariation(py::module& m)
{
  // ----- enum class: opendnp3::EventDoubleBinaryVariation
  py::enum_<opendnp3::EventDoubleBinaryVariation>(m, "EventDoubleBinaryVariation")
      .value("Group4Var1", opendnp3::EventDoubleBinaryVariation::Group4Var1)
      .value("Group4Var2", opendnp3::EventDoubleBinaryVariation::Group4Var2)
      .value("Group4Var3", opendnp3::EventDoubleBinaryVariation::Group4Var3);
}

#endif // PYDNP3_OPENDNP3
#endif
