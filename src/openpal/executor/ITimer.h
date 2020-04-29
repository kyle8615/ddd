#ifndef PYDNP3_OPENPAL_EXECUTOR_ITIMER_H
#define PYDNP3_OPENPAL_EXECUTOR_ITIMER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/executor/ITimer.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;
using namespace std;

namespace openpal {
/**
* Overriding virtual functions from interface class ITimer.
*/
class PyITimer : public ITimer {
  public:
  /* Inherit the constructors */
  using ITimer::ITimer;

  /* Trampoline for ITimer virtual functions */
  void Cancel() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ITimer,
        Cancel, );
  }
  MonotonicTimestamp ExpiresAt() override
  {
    PYBIND11_OVERLOAD_PURE(
        MonotonicTimestamp,
        ITimer,
        ExpiresAt, );
  }
};
}

void bind_ITimer(py::module& m)
{
  // ----- class: openpal::ITimer -----
  py::class_<openpal::ITimer, openpal::PyITimer>(m, "ITimer",
      "Timer are used to defer events for a later time on an executor.")

      .def(py::init<>())

      .def(
          "Cancel",
          &openpal::ITimer::Cancel)

      .def(
          "ExpiresAt",
          &openpal::ITimer::ExpiresAt);
}

#endif // PYDNP3_OPENPAL
#endif
