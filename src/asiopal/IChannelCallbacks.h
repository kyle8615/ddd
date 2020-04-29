#ifndef PYDNP3_ASIOPAL_ICHANNELCALLBACKS_H
#define PYDNP3_ASIOPAL_ICHANNELCALLBACKS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/IChannelCallbacks.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal {
/**
* Overriding virtual functions from interface class IChannelCallbacks.
*/
struct PyIChannelCallbacks : public IChannelCallbacks {
  public:
  /* Inherit the constructors */
  using IChannelCallbacks::IChannelCallbacks;

  /* Trampoline for IChannelCallbacks virtual functions */
  void OnReadComplete(const std::error_code& ec, size_t num) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IChannelCallbacks,
        OnReadComplete,
        ec, num);
  }
  void OnWriteComplete(const std::error_code& ec, size_t num) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IChannelCallbacks,
        OnWriteComplete,
        ec, num);
  }
};
}

void bind_IChannelCallbacks(py::module& m)
{
  // ----- struct: asiopal::IChannelCallbacks -----
  py::class_<asiopal::IChannelCallbacks, asiopal::PyIChannelCallbacks>(m, "IChannelCallbacks")

      .def(py::init<>())

      .def(
          "OnReadComplete",
          &asiopal::IChannelCallbacks::OnReadComplete,
          py::arg("ec"), py::arg("num"))

      .def(
          "OnWriteComplete",
          &asiopal::IChannelCallbacks::OnReadComplete,
          py::arg("ec"), py::arg("num"));
}

#endif // PYDNP3_ASIOPAL
#endif
