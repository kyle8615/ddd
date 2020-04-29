#ifndef PYDNP3_OPENDNP3_MASTER_COMMANDCALLBACKT_H
#define PYDNP3_OPENDNP3_MASTER_COMMANDCALLBACKT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/CommandCallbackT.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CommandCallbackT(py::module& m)
{
  // ----- class: opendnp3::CommandCallbackT -----
  py::class_<opendnp3::CommandCallbackT>(m, "CommandCallbackT");
}

#endif // PYDNP3_OPENDNP3
#endif
