#ifndef PYDNP3_OPENDNP3_GEN_STATICANALOGOUTPUTSTATUSVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICANALOGOUTPUTSTATUSVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticAnalogOutputStatusVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticAnalogOutputStatusVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticAnalogOutputStatusVariation -----
  py::enum_<opendnp3::StaticAnalogOutputStatusVariation>(m, "StaticAnalogOutputStatusVariation")
      .value("Group40Var1", opendnp3::StaticAnalogOutputStatusVariation::Group40Var1)
      .value("Group40Var2", opendnp3::StaticAnalogOutputStatusVariation::Group40Var2)
      .value("Group40Var3", opendnp3::StaticAnalogOutputStatusVariation::Group40Var3)
      .value("Group40Var4", opendnp3::StaticAnalogOutputStatusVariation::Group40Var4);
}

#endif // PYDNP3_OPENDNP3
#endif
