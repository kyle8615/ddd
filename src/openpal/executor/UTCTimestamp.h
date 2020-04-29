#ifndef PYDNP3_OPENPAL_EXECUTOR_UTCTIMESTAMP_H
#define PYDNP3_OPENPAL_EXECUTOR_UTCTIMESTAMP_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/executor/UTCTimestamp.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;
using namespace std;

void bind_UTCTimestamp(py::module& m)
{
  // ----- class: openpal::UTCTimestamp -----
  py::class_<openpal::UTCTimestamp>(m, "UTCTimestamp",
      "Strong typing for UTCTimestamps")

      .def(py::init<>())

      .def(
          py::init<uint64_t>(),
          ":type msSinceEpoch: unsigned long",
          py::arg("msSinceEpoch"))

      .def_readwrite(
          "msSinceEpoch",
          &openpal::UTCTimestamp::msSinceEpoch,
          ":type msSinceEpoch: unsigned long");
}

#endif // PYDNP3_OPENPAL
#endif
