#ifndef PYDNP3_ASIODNP3_MASTERTCPSERVER_H
#define PYDNP3_ASIODNP3_MASTERTCPSERVER_H
#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/MasterTCPServer.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_MasterTCPServer(py::module& m)
{
  // ----- class: asiodnp3::MasterTCPServer -----
  py::class_<asiodnp3::MasterTCPServer,
      asiopal::TCPServer,
      std::shared_ptr<asiodnp3::MasterTCPServer>>(m, "MasterTCPServer",
      "Binds and listens on an IPv4 TCP port. Meant to be used exclusively as a shared_ptr.")

      .def(
          py::init<const openpal::Logger&,
              const std::shared_ptr<asiopal::Executor>&,
              const asiopal::IPEndpoint&,
              const std::shared_ptr<asiodnp3::IListenCallbacks>,
              const std::shared_ptr<asiopal::ResourceManager>,
              std::error_code&>(),
          py::arg("logger"), py::arg("executor"), py::arg("endpoint"), py::arg("callbacks"), py::arg("manager"),
          py::arg("ec"),
          py::return_value_policy::reference)

      .def(
          "Create",
          &asiodnp3::MasterTCPServer::Create,
          py::return_value_policy::reference);
}

#endif // PYDNP3_ASIODNP3
#endif
