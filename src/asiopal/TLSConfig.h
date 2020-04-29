#ifndef PYDNP3_ASIOPAL_TLSCONFIG_H
#define PYDNP3_ASIOPAL_TLSCONFIG_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/TLSConfig.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_TLSConfig(py::module& m)
{
  // ----- struct: asiopal:::TLSConfig -----
  py::class_<asiopal::TLSConfig>(m, "TLSConfig",
      "TLS configuration information.")

      .def(
          py::init<const std::string&, const std::string&, const std::string&, int, bool, bool, bool, const std::string&>(),
          "   Construct a TLS configuration. \n"
          ":param peerCertFilePath: Certificate file used to verify the peer or server. Can be CA file or a "
          "self-signed cert provided by other party. \n"
          ":param localCertFilePath: File that contains the certificate (or certificate chain) that will be "
          "presented to the remote side of the connection \n"
          ":param privateKeyFilePath: File that contains the private key corresponding to the local certificate \n"
          ":param maxVerifyDepth: The maximum certificate chain verification depth (0 == self-signed only) \n"
          ":param allowTLSv10: Allow TLS version 1.0 (default false) \n"
          ":param allowTLSv11: Allow TLS version 1.1 (default false) \n"
          ":param allowTLSv12: Allow TLS version 1.2 (default true) \n"
          ":param cipherList: The openssl cipher-list, defaults to empty string which does not modify the default "
          "cipher list \n"
          "localCertFilePath and privateKeyFilePath can optionally be the same file, i.e. a PEM that contains both "
          "pieces of data.",
          py::arg("peerCertFilePath"),
          py::arg("localCertFilePath"),
          py::arg("privateKeyFilePath"),
          py::arg("maxVerifyDepth") = 0,
          py::arg("allowTLSv10") = false,
          py::arg("allowTLSv11") = false,
          py::arg("allowTLSv12") = false,
          py::arg("cipherList") = "")

      .def_readwrite(
          "peerCertFilePath",
          &asiopal::TLSConfig::peerCertFilePath,
          "Certificate file used to verify the peer or server. Can be CA file or a self-signed cert provided "
          "by other party.")

      .def_readwrite(
          "localCertFilePath",
          &asiopal::TLSConfig::localCertFilePath,
          "File that contains the certificate (or certificate chain) that will be presented to the remote side "
          "of the connection.")

      .def_readwrite(
          "privateKeyFilePath",
          &asiopal::TLSConfig::privateKeyFilePath,
          "File that contains the private key corresponding to the local certificate.")

      .def_readwrite(
          "maxVerifyDepth",
          &asiopal::TLSConfig::maxVerifyDepth,
          "Max verification depth (defaults to 0 - peer certificate only).")

      .def_readwrite(
          "allowTLSv10",
          &asiopal::TLSConfig::allowTLSv10,
          "Allow TLS version 1.0 (default false).")

      .def_readwrite(
          "allowTLSv11",
          &asiopal::TLSConfig::allowTLSv11,
          "Allow TLS version 1.1 (default false).")

      .def_readwrite(
          "allowTLSv12",
          &asiopal::TLSConfig::allowTLSv12,
          "Allow TLS version 1.2 (default true).")

      .def_readwrite(
          "cipherList",
          &asiopal::TLSConfig::cipherList,
          "Openssl format cipher list");
}

#endif // PYDNP3_ASIOPAL
#endif
