#ifndef PYDNP3_OPENDNP3_GEN_HMACTYPE_H
#define PYDNP3_OPENDNP3_GEN_HMACTYPE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/HMACType.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_HMACType(py::module& m)
{
  // ----- enum class: opendnp3::HMACType -----
  py::enum_<opendnp3::HMACType>(m, "HMACType",
      "Enumerates possible algorithms used to calculate the HMAC.")

      .value(
          "NO_MAC_VALUE",
          opendnp3::HMACType::NO_MAC_VALUE,
          "No HMAC value in this message.")

      .value(
          "HMAC_SHA1_TRUNC_10",
          opendnp3::HMACType::HMAC_SHA1_TRUNC_10,
          "Networked version of SHA1.")

      .value(
          "HMAC_SHA256_TRUNC_8",
          opendnp3::HMACType::HMAC_SHA256_TRUNC_8,
          "Serial version of SHA256.")

      .value(
          "HMAC_SHA256_TRUNC_16",
          opendnp3::HMACType::HMAC_SHA256_TRUNC_16,
          "Networked version of SHA256.")

      .value(
          "HMAC_SHA1_TRUNC_8",
          opendnp3::HMACType::HMAC_SHA1_TRUNC_8,
          "Serial version of SHA1.")

      .value(
          "AES_GMAC",
          opendnp3::HMACType::AES_GMAC,
          "12 octet output for serial or network.")

      .value(
          "UNKNOWN",
          opendnp3::HMACType::UNKNOWN,
          "Unknown HMAC algorithm.");

  // ----- function: opendnp3::HMACTypeToType -----
  m.def(
      "HMACTypeToType",
      &opendnp3::HMACTypeToType);

  // ----- function: opendnp3::HMACTypeFromType -----
  m.def(
      "HMACTypeFromType",
      &opendnp3::HMACTypeFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::HMACTypeToString -----
  m.def(
      "HMACTypeToString",
      &opendnp3::HMACTypeToString);
}

#endif // PYDNP3_OPENDNP3
#endif
