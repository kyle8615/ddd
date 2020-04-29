#ifndef PYDNP3_OPENDNP3_APP_EVENTTRIGGERS_H
#define PYDNP3_OPENDNP3_APP_EVENTTRIGGERS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/EventTriggers.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventTriggers(py::module& m)
{
  // ----- func: opendnp3::measurements::IsEvent -----
  m.def_submodule("measurements").def("IsEvent", &opendnp3::measurements::IsEvent<uint32_t, uint64_t>);

  m.def_submodule("measurements").def("IsEvent", (bool (*)(const opendnp3::TypedMeasurement<double>&, const opendnp3::TypedMeasurement<double>&, double)) & opendnp3::measurements::IsEvent, py::arg("newMeas"), py::arg("oldMeas"), py::arg("deadband"));
}

#endif // PYDNP3_OPENDNP3
#endif
