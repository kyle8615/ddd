#ifndef PYDNP3_OPENDNP3_GEN_KEYWRAPALGORITHM_H
#define PYDNP3_OPENDNP3_GEN_KEYWRAPALGORITHM_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/KeyWrapAlgorithm.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_KeyWrapAlgorithm(py::module& m)
{
  // ----- enum class: opendnp3::KeyWrapAlgorithm -----
  py::enum_<opendnp3::KeyWrapAlgorithm>(m, "KeyWrapAlgorithm",
      "Enumerates possible key-wrap algorithms.")

      .value(
          "AES_128",
          opendnp3::KeyWrapAlgorithm::AES_128,
          "AES 128 Key Wrap Algorithm.")

      .value(
          "AES_256",
          opendnp3::KeyWrapAlgorithm::AES_256,
          "AES 256 Key Wrap Algorithm.")

      .value(
          "UNDEFINED",
          opendnp3::KeyWrapAlgorithm::UNDEFINED);

  // ----- function: opendnp3::KeyWrapAlgorithmToType -----
  m.def(
      "KeyWrapAlgorithmToType",
      &opendnp3::KeyWrapAlgorithmToType);

  // ----- function: opendnp3::KeyWrapAlgorithmFromType -----
  m.def(
      "KeyWrapAlgorithmFromType",
      &opendnp3::KeyWrapAlgorithmFromType,
      ":rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::KeyWrapAlgorithmToString -----
  m.def(
      "KeyWrapAlgorithmToString",
      &opendnp3::KeyWrapAlgorithmToString);
}

#endif // PYDNP3_OPENDNP3
#endif
