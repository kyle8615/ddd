#ifndef PYDNP3_ASIOPAL_SERIALCHANNEL_H
#define PYDNP3_ASIOPAL_SERIALCHANNEL_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/SerialChannel.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_SerialChannel(py::module& m)
{
  // ----- class: asiopal::SerialChannel -----
  py::class_<asiopal::SerialChannel,
      asiopal::IAsyncChannel,
      std::shared_ptr<asiopal::SerialChannel>>(m, "SerialChannel")

      .def(
          py::init<std::shared_ptr<asiopal::Executor>&>(),
          py::arg("executor"))

      .def_static(
          "Create",
          &asiopal::SerialChannel::Create,
          py::arg("executor"))

      .def(
          "Open",
          &asiopal::SerialChannel::Open,
          py::arg("settings"), py::arg("ec"));
}

#endif // PYDNP3_ASIOPAL
#endif
