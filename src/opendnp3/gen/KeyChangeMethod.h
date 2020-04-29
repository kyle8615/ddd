#ifndef PYDNP3_OPENDNP3_GEN_KEYCHANGEMETHOD_H
#define PYDNP3_OPENDNP3_GEN_KEYCHANGEMETHOD_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/KeyChangeMethod.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_KeyChangeMethod(py::module& m)
{
  // ----- enum class: opendnp3::KeyChangeMethod -----
  py::enum_<opendnp3::KeyChangeMethod>(m, "KeyChangeMethod",
      "Enumerates possible algorithms for changing the update key.")

      .value("AES_128_SHA1_HMAC", opendnp3::KeyChangeMethod::AES_128_SHA1_HMAC)
      .value("AES_256_SHA256_HMAC", opendnp3::KeyChangeMethod::AES_256_SHA256_HMAC)
      .value("AES_256_AES_GMAC", opendnp3::KeyChangeMethod::AES_256_AES_GMAC)
      .value("RSA_1024_DSA_SHA1_HMAC_SHA1", opendnp3::KeyChangeMethod::RSA_1024_DSA_SHA1_HMAC_SHA1)
      .value("RSA_2048_DSA_SHA256_HMAC_SHA256", opendnp3::KeyChangeMethod::RSA_2048_DSA_SHA256_HMAC_SHA256)
      .value("RSA_3072_DSA_SHA256_HMAC_SHA256", opendnp3::KeyChangeMethod::RSA_3072_DSA_SHA256_HMAC_SHA256)
      .value("RSA_2048_DSA_SHA256_AES_GMAC", opendnp3::KeyChangeMethod::RSA_2048_DSA_SHA256_AES_GMAC)
      .value("RSA_3072_DSA_SHA256_AES_GMAC", opendnp3::KeyChangeMethod::RSA_3072_DSA_SHA256_AES_GMAC)
      .value("UNDEFINED", opendnp3::KeyChangeMethod::UNDEFINED);

  // ----- function: opendnp3::KeyChangeMethodToType -----
  m.def(
      "KeyChangeMethodToType",
      &opendnp3::KeyChangeMethodToType);

  // ----- function: opendnp3::KeyChangeMethodFromType -----
  m.def(
      "KeyChangeMethodFromType",
      &opendnp3::KeyChangeMethodFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::KeyChangeMethodToString -----
  m.def(
      "KeyChangeMethodToString",
      &opendnp3::KeyChangeMethodToString);
}

#endif // PYDNP3_OPENDNP3
#endif
