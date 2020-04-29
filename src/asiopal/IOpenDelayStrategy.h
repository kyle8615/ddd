#ifndef PYDNP3_ASIOPAL_IOPENDELAYSTRATEGY_H
#define PYDNP3_ASIOPAL_IOPENDELAYSTRATEGY_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/IOpenDelayStrategy.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal {
/**
* Overriding virtual functions from interface class IOpenDelayStrategy.
*/
class PyIOpenDelayStrategy : public IOpenDelayStrategy {
  /* Inherit the constructors */
  using IOpenDelayStrategy::IOpenDelayStrategy;

  /* Trampoline for IOpenDelayStrategy virtual functions */
  openpal::TimeDuration GetNextDelay(const openpal::TimeDuration& current, const openpal::TimeDuration& max) const override
  {
    PYBIND11_OVERLOAD_PURE(
        openpal::TimeDuration,
        IOpenDelayStrategy,
        GetNextDelay,
        current, max);
  }
};
}

void bind_IOpenDelayStrategy(py::module& m)
{
  // ----- class: asiopal::IOpenDelayStrategy -----
  py::class_<asiopal::IOpenDelayStrategy, asiopal::PyIOpenDelayStrategy>(m, "IOpenDelayStrategy",
      "A strategy interface for controlling how connection are retried")

      .def(py::init<>())

      .def(
          "GetNextDelay",
          &asiopal::IOpenDelayStrategy::GetNextDelay,
          py::arg("current"), py::arg("max"));

  // ----- class: asiopal::ExponentialBackoffStrategy -----
  py::class_<asiopal::ExponentialBackoffStrategy, asiopal::IOpenDelayStrategy>(m, "ExponentialBackoffStrategy",
      "Implements IOpenDelayStrategy using exponential-backoff.")

      .def_static(
          "Instance",
          &asiopal::ExponentialBackoffStrategy::Instance)

      .def(
          "GetNextDelay",
          &asiopal::ExponentialBackoffStrategy::GetNextDelay,
          py::arg("current"), py::arg("max"));
}

#endif // PYDNP3_ASIOPAL
#endif
