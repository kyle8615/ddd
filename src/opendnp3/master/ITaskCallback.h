#ifndef PYDNP3_OPENDNP3_MASTER_ITASKCALLBACK_H
#define PYDNP3_OPENDNP3_MASTER_ITASKCALLBACK_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/ITaskCallback.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class ITaskCallback.
*/
class PyITaskCallback : public ITaskCallback {
  /* Inherit the constructors */
  using ITaskCallback::ITaskCallback;

  /* Trampoline for ITaskCallback virtual functions */
  void OnStart() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ITaskCallback,
        OnStart, )
  }
  void OnComplete(TaskCompletion result) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ITaskCallback,
        OnComplete,
        result)
  }
  virtual void OnDestroyed() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ITaskCallback,
        OnDestroyed, )
  }
};
}

void bind_ITaskCallback(py::module& m)
{
  // ----- class: opendnp3::ITaskCallback -----
  py::class_<opendnp3::ITaskCallback, opendnp3::PyITaskCallback>(m, "ITaskCallback",
      "Callbacks for when a task starts and completes.")

      .def(py::init<>())

      .def(
          "OnStart",
          &opendnp3::ITaskCallback::OnStart,
          "Called when the task starts running.")

      .def(
          "OnComplete",
          &opendnp3::ITaskCallback::OnComplete,
          "Called when the task succeeds or fails.",
          py::arg("result"))

      .def(
          "OnDestroyed",
          &opendnp3::ITaskCallback::OnDestroyed,
          "Called when the task no longer exists and no more calls will be made to OnStart/OnComplete.");
}

#endif // PYDNP3_OPENDNP3
#endif
