#ifndef PYDNP3_ASIODNP3_ICHANNELLISTENER_H
#define PYDNP3_ASIODNP3_ICHANNELLISTENER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/IChannelListener.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3 {
/**
* Overriding virtual functions from interface class IChannelListener.
*/
class PyIChannelListener : public IChannelListener {
  public:
  /* Inherit the constructors */
  using IChannelListener::IChannelListener;

  /* Trampoline for IChannelListener virtual functions */
  void OnStateChange(opendnp3::ChannelState state) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IChannelListener,
        OnStateChange,
        state);
  }
};
}

void bind_IChannelListener(py::module& m)
{
  // ----- class: asiodnp3::IChannelListener -----
  py::class_<asiodnp3::IChannelListener,
      asiodnp3::PyIChannelListener,
      std::shared_ptr<asiodnp3::IChannelListener>>(m, "IChannelListener",
      "Callback interface for receiving information about a running channel.")

      .def(py::init<>())

      .def(
          "OnStateChange",
          &asiodnp3::IChannelListener::OnStateChange,
          "Receive callbacks for state transitions on the channels executor.",
          py::arg("state"));
}

#endif // PYDNP3_ASIODNP3
#endif
