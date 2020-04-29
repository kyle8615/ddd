#ifndef PYDNP3_ASIOPAL_IASYNCCHANNEL_H
#define PYDNP3_ASIOPAL_IASYNCCHANNEL_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/IAsyncChannel.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal {
/**
* Overriding virtual functions from interface class IAsyncChannel.
*/
class PyIAsyncChannel : public IAsyncChannel {
  public:
  /* Inherit the constructors */
  using IAsyncChannel::IAsyncChannel;

  /* Trampoline for IAsyncChannel virtual functions */
  void BeginReadImpl(openpal::WSlice buffer) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IAsyncChannel,
        BeginReadImpl,
        buffer);
  }
  void BeginWriteImpl(const openpal::RSlice& buffer) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IAsyncChannel,
        BeginWriteImpl,
        buffer);
  }
  void ShutdownImpl() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IAsyncChannel,
        ShutdownImpl, );
  }
};
}

void bind_IAsyncChannel(py::module& m)
{
  // ----- class: asiopal::IAsyncChannel -----
  py::class_<asiopal::IAsyncChannel,
      asiopal::PyIAsyncChannel,
      std::shared_ptr<asiopal::IAsyncChannel>>(m, "IAsyncChannel")

      .def(
          py::init<const std::shared_ptr<asiopal::Executor>&>(),
          py::arg("executor"))

      .def(
          "SetCallbacks",
          &asiopal::IAsyncChannel::SetCallbacks,
          py::arg("callbacks"))

      .def(
          "BeginRead",
          &asiopal::IAsyncChannel::BeginRead,
          py::arg("buffer"))

      .def(
          "BeginWrite",
          &asiopal::IAsyncChannel::BeginWrite,
          py::arg("buffer"))

      .def(
          "Shutdown",
          &asiopal::IAsyncChannel::Shutdown)

      .def(
          "CanRead",
          &asiopal::IAsyncChannel::CanRead)

      .def(
          "CanWrite",
          &asiopal::IAsyncChannel::CanWrite);
}

#endif // PYDNP3_ASIOPAL
#endif
