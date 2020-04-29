#ifndef PYDNP3_OPENDNP3_GEN_EVENTBINARYVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTBINARYVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventBinaryVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventBinaryVariation(py::module& m)
{
  // ----- enum class: opendnp3::EventBinaryVariation -----
  py::enum_<opendnp3::EventBinaryVariation>(m, "EventBinaryVariation")
      .value("Group2Var1", opendnp3::EventBinaryVariation::Group2Var1)
      .value("Group2Var2", opendnp3::EventBinaryVariation::Group2Var2)
      .value("Group2Var3", opendnp3::EventBinaryVariation::Group2Var3);
}

#endif // PYDNP3_OPENDNP3
#endif
