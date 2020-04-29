#ifndef PYDNP3_OPENPAL_UTIL_COMPARISONS_H
#define PYDNP3_OPENPAL_UTIL_COMPARISONS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/util/Comparisons.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <class T>
void declareComparisions(py::module& m)
{
  // ----- function: openpal::Min<T> -----
  m.def(
      "Min",
      &openpal::Min<T>);

  // ----- function: openpal::Max<T> -----
  m.def(
      "Max",
      &openpal::Max<T>);

  // ----- function: openpal::Bounded<T> -----
  m.def(
      "Bounded",
      &openpal::Bounded<T>,
      py::arg("value"), py::arg("min"), py::arg("max"));

  // ----- function: openpal::WithinLimits<T> -----
  m.def(
      "WithinLimits",
      &openpal::WithinLimits<T>,
      py::arg("value"), py::arg("min"), py::arg("max"));

  // ----- function: openpal::FloatEqual<T> -----
  m.def(
      "FloatEqual",
      &openpal::FloatEqual<T>);
}

void bind_Comparisons(py::module& m)
{
  declareComparisions<uint16_t>(m);
  declareComparisions<uint32_t>(m);
}

#endif // PYDNP3_OPENPAL
#endif
