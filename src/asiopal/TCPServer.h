#ifndef PYDNP3_ASIOPAL_TCPSERVER_H
#define PYDNP3_ASIOPAL_TCPSERVER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/TCPServer.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal {
/**
* Overriding virtual functions from interface class TCPServer.
*/
class PyTCPServer : public TCPServer {
  public:
  /* Inherit the constructors */
  using TCPServer::TCPServer;

  /* Trampoline for TCPServer virtual functions */
  void OnShutdown() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        TCPServer,
        OnShutdown, );
  }
  void AcceptConnection(uint64_t sessionid,
      const std::shared_ptr<Executor>& executor,
      asio::ip::tcp::socket socket) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        TCPServer,
        AcceptConnection,
        sessionid, executor, socket);
  }
};
}

void bind_TCPServer(py::module& m)
{
  // ----- class: asiopal::TCPServer -----
  py::class_<asiopal::TCPServer,
      asiopal::PyTCPServer,
      asiopal::IListener,
      std::shared_ptr<asiopal::TCPServer>>(m, "TCPServer",
      "Binds and listens on an IPv4 TCP port. \n"
      "Meant to be used exclusively as a shared_ptr.")

      .def(
          py::init<const openpal::Logger&,
              const std::shared_ptr<asiopal::Executor>&,
              const asiopal::IPEndpoint&,
              std::error_code&>(),
          py::arg("logger"), py::arg("executor"), py::arg("endpoint"), py::arg("ec"))

      .def(
          "Shutdown",
          &asiopal::TCPServer::Shutdown,
          "Implement IListener.");
}

#endif // PYDNP3_ASIOPAL
#endif
