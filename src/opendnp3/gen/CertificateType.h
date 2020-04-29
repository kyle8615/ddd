#ifndef PYDNP3_OPENDNP3_GEN_CERTIFICATETYPE_H
#define PYDNP3_OPENDNP3_GEN_CERTIFICATETYPE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/CertificateType.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CertificateType(py::module& m)
{
  // ----- enum class: opendnp3::CertificateType -----
  py::enum_<opendnp3::CertificateType>(m, "CertificateType",
      "Specifies the reason that an auth error message was transmitted")

      .value(
          "ID_CERTIFICATE",
          opendnp3::CertificateType::ID_CERTIFICATE,
          "ID certificate.")

      .value(
          "ATTRIBUTE_CERTIFICATE",
          opendnp3::CertificateType::ATTRIBUTE_CERTIFICATE,
          "Attribute certificate.")

      .value(
          "UNKNOWN",
          opendnp3::CertificateType::UNKNOWN,
          "Unknown certificate type.");

  // ----- func: opendnp3::CertificateTypeToType -----
  m.def(
      "CertificateTypeToType",
      &opendnp3::CertificateTypeToType,
      py::arg("certificateType"));

  // ----- func: opendnp3::CertificateTypeFromType -----
  m.def(
      "CertificateTypeFromType",
      &opendnp3::CertificateTypeFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- func: opendnp3::CertificateTypeToString -----
  m.def(
      "CertificateTypeToString",
      &opendnp3::CertificateTypeToString,
      py::arg("certificateType"));
}

#endif // PYDNP3_OPENDNP3
#endif
