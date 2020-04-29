#ifndef PYDNP3_ASIODNP3_X509INFO_H
#define PYDNP3_ASIODNP3_X509INFO_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/X509Info.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_X509Info(py::module& m)
{
  // ----- class: asiodnp3::X509Info -----
  py::class_<asiodnp3::X509Info>(m, "X509Info",
      "Select information from a preverified x509 certificate that user can can inspect an optionally reject.")

      .def(
          py::init<int, const openpal::RSlice, std::string>(),
          py::arg("depth"), py::arg("sha1thumbprint"), py::arg("subjectName"))

      .def_readwrite(
          "depth",
          &asiodnp3::X509Info::depth,
          "The depth of the certificate in the chain.")

      .def_readwrite(
          "sha1thumbprint",
          &asiodnp3::X509Info::sha1thumbprint,
          "The sha1 thumbprint.")

      .def_readwrite(
          "subjectName",
          &asiodnp3::X509Info::subjectName,
          "The extracted subject name.");
}

#endif // PYDNP3_ASIODNP3
#endif
