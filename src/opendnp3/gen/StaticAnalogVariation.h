#ifndef PYDNP3_OPENDNP3_GEN_STATICANALOGVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICANALOGVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticAnalogVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticAnalogVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticAnalogVariation -----
  py::enum_<opendnp3::StaticAnalogVariation>(m, "StaticAnalogVariation")
      .value("Group30Var1", opendnp3::StaticAnalogVariation::Group30Var1)
      .value("Group30Var2", opendnp3::StaticAnalogVariation::Group30Var2)
      .value("Group30Var3", opendnp3::StaticAnalogVariation::Group30Var3)
      .value("Group30Var4", opendnp3::StaticAnalogVariation::Group30Var4)
      .value("Group30Var5", opendnp3::StaticAnalogVariation::Group30Var5)
      .value("Group30Var6", opendnp3::StaticAnalogVariation::Group30Var6);
}

#endif // PYDNP3_OPENDNP3
#endif
