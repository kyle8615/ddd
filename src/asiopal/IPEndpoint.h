#ifndef PYDNP3_ASIOPAL_IPENDPOINT_H
#define PYDNP3_ASIOPAL_IPENDPOINT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/IPEndpoint.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_IPEndpoint(py::module& m)
{
  // ----- class: asiopal::IPEndpoint -----
  py::class_<asiopal::IPEndpoint>(m, "IPEndpoint")

      .def(
          py::init<const std::string&, uint16_t>(),
          ":type port: unsigned short",
          py::arg("address"), py::arg("port"))

      .def_static(
          "AllAdapters",
          &asiopal::IPEndpoint::AllAdapters,
          ":type port: unsigned short",
          py::arg("port"))

      .def_static(
          "AllAdapters",
          &asiopal::IPEndpoint::Localhost,
          ":type port: unsigned short",
          py::arg("port"))

      .def_readwrite(
          "address",
          &asiopal::IPEndpoint::address)

      .def_readwrite(
          "port",
          &asiopal::IPEndpoint::port,
          ":type port: unsigned short");
}

#endif // PYDNP3_ASIOPAL
#endif
