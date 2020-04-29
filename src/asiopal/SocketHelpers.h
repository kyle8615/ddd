#ifndef PYDNP3_ASIOPAL_SOCKETHELPERS_H
#define PYDNP3_ASIOPAL_SOCKETHELPERS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/SocketHelpers.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_SocketHelpers(py::module& m)
{
  // ----- class: asiopal::SocketHelpers -----
  py::class_<asiopal::SocketHelpers>(m, "SocketHelpers",
      "Bind a socket object to a local endpoint given an address. If the address is empty, 0.0.0.0 is used.")

      .def_static(
          "BindToLocalAddress",
          &asiopal::SocketHelpers::BindToLocalAddress<asio::ip::tcp::socket>);
}

#endif // PYDNP3_ASIOPAL
#endif
