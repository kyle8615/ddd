#ifndef PYDNP3_OPENDNP3_GEN_STATICTIMEANDINTERVALVARIATION_H
#define PYDNP3_OPENDNP3_GEN_STATICTIMEANDINTERVALVARIATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/StaticTimeAndIntervalVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StaticTimeAndIntervalVariation(py::module& m)
{
  // ----- enum class: opendnp3::StaticTimeAndIntervalVariation
  py::enum_<opendnp3::StaticTimeAndIntervalVariation>(m, "StaticTimeAndIntervalVariation")
      .value("Group50Var4", opendnp3::StaticTimeAndIntervalVariation::Group50Var4);
}

#endif // PYDNP3_OPENDNP3
#endif
