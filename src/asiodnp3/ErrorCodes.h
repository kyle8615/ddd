#ifndef PYDNP3_ASIODNP3_ERRORCODES_H
#define PYDNP3_ASIODNP3_ERRORCODES_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/ErrorCodes.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;
using namespace std;

void bind_ErrorCodes(py::module& m)
{
  // ----- enum class: asiodnp3::Error -----
  py::enum_<asiodnp3::Error>(m, "Error")
      .value("SHUTTING_DOWN", asiodnp3::Error::SHUTTING_DOWN)
      .value("NO_TLS_SUPPORT", asiodnp3::Error::NO_TLS_SUPPORT)
      .value("NO_SERIAL_SUPPORT", asiodnp3::Error::NO_SERIAL_SUPPORT);

  // ----- class: asiodnp3::ErrorCategory -----
  py::class_<asiodnp3::ErrorCategory>(m, "ErrorCategory")

      .def_static(
          "Instance",
          &asiodnp3::ErrorCategory::Instance)

      .def(
          "name",
          &asiodnp3::ErrorCategory::name)

      .def(
          "message",
          &asiodnp3::ErrorCategory::message,
          py::arg("ev"));

  // ----- func: asiodnp3::make_error_code -----
  m.def(
      "make_error_code",
      &asiodnp3::make_error_code,
      py::arg("err"));

  // ----- class: asiodnp3::is_error_code_enum -----
  py::class_<std::is_error_code_enum<asiodnp3::Error>>(m, "is_error_code_enum");
}

#endif // PYDNP3_ASIODNP3
#endif
