#ifndef PYDNP3_ASIOPAL_UTCTIMESOURCE_H
#define PYDNP3_ASIOPAL_UTCTIMESOURCE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/UTCTimeSource.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_UTCTimeSource(py::module& m)
{
  // ----- class: asiopal::UTCTimeSource -----
  py::class_<asiopal::UTCTimeSource,
      openpal::IUTCTimeSource,
      std::shared_ptr<asiopal::UTCTimeSource>>(m, "UTCTimeSource",
      "Interface that defines a method to get UTC timestamps")

      .def_static(
          "Instance",
          &asiopal::UTCTimeSource::Instance)

      .def(
          "Now",
          &asiopal::UTCTimeSource::Now);
}

#endif // PYDNP3_ASIOPAL
#endif
