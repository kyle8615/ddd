#ifndef PYDNP3_OPENDNP3_GEN_STATICDOUBLEBINARYVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICDOUBLEBINARYVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticDoubleBinaryVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticDoubleBinaryVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticDoubleBinaryVariation
  py::enum_<opendnp3::StaticDoubleBinaryVariation>(m, "StaticDoubleBinaryVariation")
      .value("Group3Var2", opendnp3::StaticDoubleBinaryVariation::Group3Var2);
}

#endif // PYDNP3_OPENDNP3
#endif
