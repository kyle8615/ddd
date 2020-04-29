#ifndef PYDNP3_OPENDNP3_GEN_STATICBINARYOUTPUTSTATUSVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICBINARYOUTPUTSTATUSVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticBinaryOutputStatusVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticBinaryOutputStatusVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticBinaryOutputStatusVariation -----
  py::enum_<opendnp3::StaticBinaryOutputStatusVariation>(m, "StaticBinaryOutputStatusVariation")
      .value("Group10Var2", opendnp3::StaticBinaryOutputStatusVariation::Group10Var2);
}

#endif // PYDNP3_OPENDNP3
#endif
