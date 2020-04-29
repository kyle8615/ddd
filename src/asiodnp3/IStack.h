#ifndef PYDNP3_ASIODNP3_ISTACK_H
#define PYDNP3_ASIODNP3_ISTACK_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/IStack.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3 {
/**
* Overriding virtual functions from interface class IStack.
*/
class PyIStack : public IStack {
  public:
  /* Inherit the constructors */
  using IStack::IStack;

  /* Trampoline for IStack virtual functions */
  bool Enable() override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IStack,
        Enable, );
  }
  bool Disable() override
  {
    PYBIND11_OVERLOAD_PURE(
        bool,
        IStack,
        Disable, );
  }
  opendnp3::StackStatistics GetStackStatistics() override
  {
    PYBIND11_OVERLOAD_PURE(
        opendnp3::StackStatistics,
        IStack,
        GetStackStatistics, );
  }

  /* Trampoline for IResource virtual functions */
  void Shutdown() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IStack,
        Shutdown, );
  }
};
}

void bind_IStack(py::module& m)
{
  // ----- class: asiodnp3::IStack -----
  py::class_<asiodnp3::IStack, asiodnp3::PyIStack, asiopal::IResource, std::shared_ptr<asiodnp3::IStack>>(m, "IStack",
      "Base class for masters or outstations.")

      .def(py::init<>())

      // the GIL is held when calling Log (py::gil_scoped_acquire by default)
      .def(
          "Enable",
          &asiodnp3::IStack::Enable,
          py::call_guard<py::gil_scoped_release>(),
          "Synchronously enable communications.")

      // the GIL is held when calling Log (py::gil_scoped_acquire by default)
      .def(
          "Disable",
          &asiodnp3::IStack::Disable,
          py::call_guard<py::gil_scoped_release>(),
          "Synchronously disable communications.")

      .def(
          "GetStackStatistics",
          &asiodnp3::IStack::GetStackStatistics,
          ":return: stack statistics counters.");
}

#endif // PYDNP3_ASIODNP3
#endif
