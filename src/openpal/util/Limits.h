#ifndef PYDNP3_OPENPAL_UTIL_LIMITS_H
#define PYDNP3_OPENPAL_UTIL_LIMITS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/util/Limits.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <class T>
void declareLimits(py::module& m)
{
  // ----- function: openpal::MinValue<T> -----
  m.def(
      "MinValue",
      &openpal::MinValue<T>);

  // ----- function: openpal::MaxValue<T> -----
  m.def(
      "MaxValue",
      &openpal::MaxValue<T>);
}

void bind_Limits(py::module& m)
{
  declareLimits<uint8_t>(m);
  declareLimits<uint16_t>(m);
  declareLimits<uint32_t>(m);
  declareLimits<float>(m);
  declareLimits<double>(m);
  declareLimits<int16_t>(m);
  declareLimits<int32_t>(m);
  declareLimits<int64_t>(m);
}

#endif // PYDNP3_OPENPAL
#endif
