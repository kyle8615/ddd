#ifndef PYDNP3_ASIOPAL_LOGGINGCONNECTIONCONDITION_H
#define PYDNP3_ASIOPAL_LOGGINGCONNECTIONCONDITION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/LoggingConnectionCondition.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_LoggingConnectionCondition(py::module& m)
{
  // ----- class: asiopal::LoggingConnectionCondition -----
  py::class_<asiopal::LoggingConnectionCondition>(m, "LoggingConnectionCondition")

      .def(
          py::init<openpal::Logger>(),
          py::arg("logger"));
}

#endif // PYDNP3_ASIOPAL
#endif
