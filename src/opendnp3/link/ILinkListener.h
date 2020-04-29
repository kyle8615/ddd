#ifndef PYDNP3_OPENDNP3_LINK_ILINKLISTENER_H
#define PYDNP3_OPENDNP3_LINK_ILINKLISTENER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/link/ILinkListener.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class ILinkListener.
*/
class PyILinkListener : public ILinkListener {
  public:
  /* Inherit the constructors */
  using ILinkListener::ILinkListener;

  /* Trampoline for ILinkListener virtual functions */
  void OnStateChange(LinkStatus value) override
  {
    PYBIND11_OVERLOAD(
        void,
        ILinkListener,
        OnStateChange,
        value);
  }
  void OnUnknownDestinationAddress(uint16_t destination) override
  {
    PYBIND11_OVERLOAD(
        void,
        ILinkListener,
        OnUnknownDestinationAddress,
        destination);
  }
  void OnUnknownSourceAddress(uint16_t source) override
  {
    PYBIND11_OVERLOAD(
        void,
        ILinkListener,
        OnUnknownSourceAddress,
        source);
  }
  void OnKeepAliveInitiated() override
  {
    PYBIND11_OVERLOAD(
        void,
        ILinkListener,
        OnKeepAliveInitiated, );
  }
  void OnKeepAliveFailure() override
  {
    PYBIND11_OVERLOAD(
        void,
        ILinkListener,
        OnKeepAliveFailure, );
  }
  void OnKeepAliveSuccess() override
  {
    PYBIND11_OVERLOAD(
        void,
        ILinkListener,
        OnKeepAliveSuccess, );
  }
};
}

void bind_ILinkListener(py::module& m)
{
  // ----- class: opendnp3::ILinkListener -----
  py::class_<opendnp3::ILinkListener,
      opendnp3::PyILinkListener,
      std::shared_ptr<opendnp3::ILinkListener>>(m, "ILinkListener",
      "Various optional callbacks that can be received for the link layer.")

      .def(py::init<>())

      .def(
          "OnStateChange",
          &opendnp3::ILinkListener::OnStateChange,
          "Called when a the reset/unreset status of the link layer changes.",
          py::arg("value"))

      .def(
          "OnUnknownDestinationAddress",
          &opendnp3::ILinkListener::OnUnknownDestinationAddress,
          "Called when a link-layer frame is received from an unknown destination address.",
          py::arg("destination"))

      .def(
          "OnUnknownSourceAddress",
          &opendnp3::ILinkListener::OnUnknownSourceAddress,
          "Called when a link-layer frame is received from an unknown source address.",
          py::arg("source"))

      .def(
          "OnKeepAliveInitiated",
          &opendnp3::ILinkListener::OnKeepAliveInitiated,
          "Called when the keep alive timer elapses. This doesn't denote a keep-alive failure, "
          "it's just a notification.")

      .def(
          "OnKeepAliveFailure",
          &opendnp3::ILinkListener::OnKeepAliveFailure,
          "Called when a keep alive message (request link status) receives no response.")

      .def(
          "OnKeepAliveSuccess",
          &opendnp3::ILinkListener::OnKeepAliveSuccess,
          "Called when a keep alive message receives a valid response.");
}

#endif // PYDNP3_OPENDNP3
#endif
