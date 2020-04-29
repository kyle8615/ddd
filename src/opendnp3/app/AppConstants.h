#ifndef PYDNP3_OPENDNP3_APP_APPCONSTANTS_H
#define PYDNP3_OPENDNP3_APP_APPCONSTANTS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/AppConstants.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_AppConstants(py::module& m)
{
  // ----- const: opendnp3::DEFAULT_MAX_APDU_SIZE -----
  // The default size for an APDU
  m.attr("DEFAULT_MAX_APDU_SIZE") = &opendnp3::DEFAULT_MAX_APDU_SIZE;

  // ----- const: DEFAULT_APP_TIMEOUT -----
  // Default timeout in milliseconds for the application layer
  m.attr("DEFAULT_APP_TIMEOUT") = &opendnp3::DEFAULT_APP_TIMEOUT;
}

#endif // PYDNP3_OPENDNP3
#endif
