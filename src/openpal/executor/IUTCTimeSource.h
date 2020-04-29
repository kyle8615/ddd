#ifndef PYDNP3_OPENPAL_EXECUTOR_IUTCTIMESOURCE_H
#define PYDNP3_OPENPAL_EXECUTOR_IUTCTIMESOURCE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/executor/IUTCTimeSource.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

namespace openpal {
/**
* Overriding virtual functions from interface class IUTCTimeSource.
*/
class PyIUTCTimeSource : public IUTCTimeSource {
  public:
  /* Inherit the constructors */
  using IUTCTimeSource::IUTCTimeSource;

  /* Trampoline for IUTCTimeSource virtual functions */
  UTCTimestamp Now() override
  {
    PYBIND11_OVERLOAD_PURE(
        UTCTimestamp,
        IUTCTimeSource,
        Now, );
  }
};
}

void bind_IUTCTimeSource(py::module& m)
{
  // ----- class: openpal::IUTCTimeSource -----
  py::class_<openpal::IUTCTimeSource,
      openpal::PyIUTCTimeSource,
      std::shared_ptr<openpal::IUTCTimeSource>>(m, "IUTCTimeSource",
      "Interface that defines a method to get UTC timestamps.")

      .def(py::init<>())

      .def(
          "Now",
          &openpal::IUTCTimeSource::Now);

  // ----- class: openpal::FixedUTCTimeSource -----
  py::class_<openpal::FixedUTCTimeSource,
      openpal::IUTCTimeSource,
      std::shared_ptr<openpal::FixedUTCTimeSource>>(m, "FixedUTCTimeSource",
      "Mock usable for testing.")

      .def(
          py::init<int64_t>(),
          ":type time: long",
          py::arg("time"))

      .def(
          "Now",
          &openpal::FixedUTCTimeSource::Now)

      .def_readwrite(
          "time",
          &openpal::FixedUTCTimeSource::time,
          ":type time: long");
}

#endif // PYDNP3_OPENPAL
#endif
