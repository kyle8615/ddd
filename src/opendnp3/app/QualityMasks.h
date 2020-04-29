#ifndef PYDNP3_OPENDNP3_APP_QUALITYMASKS_H
#define PYDNP3_OPENDNP3_APP_QUALITYMASKS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/QualityMasks.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

template <class T>
void declareToUnderlying(py::module& m)
{
  // ----- func: opendnp3::ToUnderlying -----
  m.def(
      "ToUnderlying",
      &opendnp3::ToUnderlying<T>,
      py::arg("flag"));
}

void bind_QualityMasks(py::module& m)
{
  declareToUnderlying<opendnp3::BinaryQuality>(m);
  declareToUnderlying<opendnp3::DoubleBitBinaryQuality>(m);
  declareToUnderlying<opendnp3::CounterQuality>(m);
  declareToUnderlying<opendnp3::FrozenCounterQuality>(m);
  declareToUnderlying<opendnp3::AnalogQuality>(m);
  declareToUnderlying<opendnp3::AnalogOutputStatusQuality>(m);
  declareToUnderlying<opendnp3::BinaryOutputStatusQuality>(m);
}

#endif // PYDNP3_OPENDNP3
#endif
