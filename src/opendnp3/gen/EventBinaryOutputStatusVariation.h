#ifndef PYDNP3_OPENDNP3_GEN_EVENTBINARYOUTPUTSTATUSVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTBINARYOUTPUTSTATUSVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/EventBinaryOutputStatusVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventBinaryOutputStatusVariation(py::module& m)
{
  // ----- enum class: opendnp3::EventBinaryOutputStatusVariation
  py::enum_<opendnp3::EventBinaryOutputStatusVariation>(m, "EventBinaryOutputStatusVariation")
      .value("Group11Var1", opendnp3::EventBinaryOutputStatusVariation::Group11Var1)
      .value("Group11Var2", opendnp3::EventBinaryOutputStatusVariation::Group11Var2);
}

#endif // PYDNP3_OPENDNP3
#endif
