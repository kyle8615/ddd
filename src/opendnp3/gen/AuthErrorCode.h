#ifndef PYDNP3_OPENDNP3_GEN_AUTHERRORCODE_H
#define PYDNP3_OPENDNP3_GEN_AUTHERRORCODE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/AuthErrorCode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_AuthErrorCode(py::module& m)
{
  // ----- enum class: opendnp3::AuthErrorCode -----
  py::enum_<opendnp3::AuthErrorCode>(m, "AuthErrorCode",
      "Specifies the reason that an auth error message was transmitted.")

      .value(
          "AUTHENTICATION_FAILED",
          opendnp3::AuthErrorCode::AUTHENTICATION_FAILED,
          "Supplied auth information.")

      .value(
          "AGGRESSIVE_MODE_UNSUPPORTED",
          opendnp3::AuthErrorCode::AGGRESSIVE_MODE_UNSUPPORTED,
          "Aggressive mode not supported on this link.")

      .value(
          "MAC_NOT_SUPPORTED",
          opendnp3::AuthErrorCode::MAC_NOT_SUPPORTED,
          "The specified MAC algorithm is not supported.")

      .value(
          "KEY_WRAP_NOT_SUPPORTED",
          opendnp3::AuthErrorCode::KEY_WRAP_NOT_SUPPORTED,
          "The key-wrap algorithm is not supported.")

      .value(
          "AUTHORIZATION_FAILED",
          opendnp3::AuthErrorCode::AUTHORIZATION_FAILED,
          "Authentication passed, but that user not authorized for requested operation.")

      .value(
          "UPDATE_KEY_METHOD_NOT_PERMITTED",
          opendnp3::AuthErrorCode::UPDATE_KEY_METHOD_NOT_PERMITTED,
          "The outstation does not support specified key change method on this link.")

      .value(
          "INVALID_SIGNATURE",
          opendnp3::AuthErrorCode::INVALID_SIGNATURE,
          "The digital signature supplied in a user status change object was invalid.")

      .value(
          "INVALID_CERTIFICATION_DATA",
          opendnp3::AuthErrorCode::INVALID_CERTIFICATION_DATA,
          "The certification data supplied in a user status change object was invalid.")

      .value(
          "UNKNOWN_USER",
          opendnp3::AuthErrorCode::UNKNOWN_USER,
          "The master attempted to change the Update Key of a user without a valid prior user status change.")

      .value(
          "MAX_SESSION_KEY_STATUS_REQUESTS_EXCEEDED",
          opendnp3::AuthErrorCode::MAX_SESSION_KEY_STATUS_REQUESTS_EXCEEDED,
          "The master on a different association has requred session key status too often.")

      .value(
          "UNKNOWN",
          opendnp3::AuthErrorCode::UNKNOWN,
          "Unknown error code.");

  // ----- func: opendnp3::AuthErrorCodeToType -----
  m.def(
      "AuthErrorCodeToType",
      &opendnp3::AuthErrorCodeToType,
      py::arg("code"));

  // ----- func: opendnp3::AuthErrorCodeFromType -----
  m.def(
      "AuthErrorCodeFromType",
      &opendnp3::AuthErrorCodeFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- func: opendnp3::AuthErrorCodeToString -----
  m.def(
      "AuthErrorCodeToString",
      &opendnp3::AuthErrorCodeToString,
      py::arg("code"));
}

#endif // PYDNP3_OPENDNP3
#endif
