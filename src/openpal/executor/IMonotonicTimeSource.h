#ifndef PYDNP3_OPENPAL_EXECUTOR_IMONOTONICTIMESOURCE_H
#define PYDNP3_OPENPAL_EXECUTOR_IMONOTONICTIMESOURCE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/executor/IMonotonicTimeSource.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;
using namespace std;

namespace openpal {
/**
* Overriding virtual functions from interface class IMonotonicTimeSource.
*/
class PyIMonotonicTimeSource : public IMonotonicTimeSource {
  public:
  /* Inherit the constructors */
  using IMonotonicTimeSource::IMonotonicTimeSource;

  /* Trampoline for IMonotonicTimeSource virtual functions */
  MonotonicTimestamp GetTime() override
  {
    PYBIND11_OVERLOAD_PURE(
        MonotonicTimestamp,
        IMonotonicTimeSource,
        GetTime, );
  }
};
}

void bind_IMonotonicTimeSource(py::module& m)
{
  // ----- class: openpal::IMonotonicTimeSource -----
  py::class_<openpal::IMonotonicTimeSource,
      openpal::PyIMonotonicTimeSource,
      std::shared_ptr<openpal::IMonotonicTimeSource>>(m, "IMonotonicTimeSource")

      .def(py::init<>())

      .def(
          "GetTime",
          &openpal::IMonotonicTimeSource::GetTime,
          ":return: a non-absolute timestamp for the monotonic time source");
}

#endif // PYDNP3_OPENPAL
#endif
