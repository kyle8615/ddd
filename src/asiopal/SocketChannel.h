#ifndef PYDNP3_ASIOPAL_SOCKETCHANNEL_H
#define PYDNP3_ASIOPAL_SOCKETCHANNEL_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/SocketChannel.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_SocketChannel(py::module& m)
{
  // ----- class: asiopal::SocketChannel -----
  py::class_<asiopal::SocketChannel,
      asiopal::IAsyncChannel,
      std::shared_ptr<asiopal::SocketChannel>>(m, "SocketChannel");
}

#endif // PYDNP3_ASIOPAL
#endif
