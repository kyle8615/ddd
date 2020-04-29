#ifndef PYDNP3_OPENPAL_CHANNEL_IPHYSICALLAYERCALLBACKS_H
#define PYDNP3_OPENPAL_CHANNEL_IPHYSICALLAYERCALLBACKS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/channel/IPhysicalLayerCallbacks.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

namespace openpal {
/**
* Overriding virtual functions from interface class IPhysicalLayerCallbacks.
*/
class PyIPhysicalLayerCallbacks : public IPhysicalLayerCallbacks {
  public:
  /* Inherit the constructors */
  using IPhysicalLayerCallbacks::IPhysicalLayerCallbacks;

  /* Trampoline for IPhysicalLayerCallbacks virtual functions */
  void OnLowerLayerUp() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IPhysicalLayerCallbacks,
        OnLowerLayerUp, );
  }
  void OnLowerLayerDown() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IPhysicalLayerCallbacks,
        OnLowerLayerDown, );
  }
  void OnOpenFailure() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IPhysicalLayerCallbacks,
        OnOpenFailure, );
  }
  void OnReceive(const RSlice& r) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IPhysicalLayerCallbacks,
        OnReceive,
        r);
  }
  void OnSendResult(bool isSucccess) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IPhysicalLayerCallbacks,
        OnSendResult,
        isSucccess);
  }
};
}

void bind_IPhysicalLayerCallbacks(py::module& m)
{
  // ----- class: openpal::IPhysicalLayerCallbacks -----
  py::class_<openpal::IPhysicalLayerCallbacks, openpal::PyIPhysicalLayerCallbacks>(m, "IPhysicalLayerCallbacks")

      .def(py::init<>())

      .def(
          "OnLowerLayerUp",
          &openpal::IPhysicalLayerCallbacks::OnLowerLayerUp,
          "Called by a lower Layer when it is available to this layer.")

      .def(
          "OnLowerLayerDown",
          &openpal::IPhysicalLayerCallbacks::OnLowerLayerDown,
          "Called by a lower layer when it is no longer available to this layer.")

      .def(
          "OnOpenFailure",
          &openpal::IPhysicalLayerCallbacks::OnOpenFailure,
          "In addition to all of the IUpperLayer functions, provide a mechanism to receive open failures. \n"
          "For consistency sake, use NVII pattern in case we want pre/post conditions in the future.")

      .def(
          "OnReceive",
          &openpal::IPhysicalLayerCallbacks::OnReceive,
          "Called by the physical layer when data arrives",
          py::arg("rSlice"))

      .def(
          "OnSendResult",
          &openpal::IPhysicalLayerCallbacks::OnSendResult,
          "Called by lower layer when a previously requested send operation succeeds or fails. \n"
          "Layers can only have 1 outstanding send operation. \n"
          "The callback is guaranteed unless the the OnLowerLayerDown() function is called beforehand.",
          py::arg("isSuccess"));
}

#endif // PYDNP3_OPENPAL
#endif
