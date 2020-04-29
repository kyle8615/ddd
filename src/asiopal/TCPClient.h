#ifndef PYDNP3_ASIOPAL_TCPCLIENT_H
#define PYDNP3_ASIOPAL_TCPCLIENT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/TCPClient.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_TCPClient(py::module& m)
{
  // ----- class: asiopal::TCPClient -----
  py::class_<asiopal::TCPClient, std::shared_ptr<asiopal::TCPClient>>(m, "TCPClient")

      .def(
          py::init<openpal::Logger&, std::shared_ptr<asiopal::Executor>&, std::string>(),
          py::arg("logger"), py::arg("executor"), py::arg("adapter"))

      .def_static(
          "Create",
          &asiopal::TCPClient::Create)

      .def(
          "Cancel",
          &asiopal::TCPClient::Cancel)

      .def(
          "BeginConnect",
          &asiopal::TCPClient::BeginConnect);
}

#endif // PYDNP3_ASIOPAL
#endif
