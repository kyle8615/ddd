#ifndef PYDNP3_OPENDNP3_APP_DNPTIME_H
#define PYDNP3_OPENDNP3_APP_DNPTIME_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/DNPTime.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_DNPTime(py::module& m)
{
  // ----- class: opendnp3::DNPTime -----
  py::class_<opendnp3::DNPTime>(m, "DNPTime")

      .def(py::init<>())

      .def(
          py::init<int64_t>(),
          ":type value: long",
          py::arg("value"))

      .def_readwrite(
          "value",
          &opendnp3::DNPTime::value,
          ":type value: long");
}

#endif // PYDNP3_OPENDNP3
#endif
