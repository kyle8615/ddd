#ifndef PYDNP3_OPENPAL_EXECUTOR_IEXECUTOR_H
#define PYDNP3_OPENPAL_EXECUTOR_IEXECUTOR_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/executor/IExecutor.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;
using namespace std;

namespace openpal {
/**
* Overriding virtual functions from interface class IExecutor.
*/
class PyIExecutor : public IExecutor {
  public:
  /* Inherit the constructors */
  using IExecutor::IExecutor;

  /* Trampoline for IExecutor virtual functions */
  ITimer* Start(const TimeDuration& duration, const action_t& action) override
  {
    PYBIND11_OVERLOAD_PURE(
        ITimer*,
        IExecutor,
        Start,
        duration, action);
  }
  ITimer* Start(const MonotonicTimestamp& expiration, const action_t& action) override
  {
    PYBIND11_OVERLOAD_PURE(
        ITimer*,
        IExecutor,
        Start,
        expiration, action);
  }
  void Post(const action_t& action) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IExecutor,
        Post,
        action);
  }

  /* Trampoline for IMonotonicTimeSource virtual functions */
  MonotonicTimestamp GetTime() override
  {
    PYBIND11_OVERLOAD_PURE(
        MonotonicTimestamp,
        IExecutor,
        GetTime, );
  }
};
}

void bind_IExecutor(py::module& m)
{
  // ----- class: openpal::IExecutor -----
  py::class_<openpal::IExecutor,
      openpal::PyIExecutor,
      openpal::IMonotonicTimeSource,
      std::shared_ptr<openpal::IExecutor>>(m, "IExecutor",
      "Interface for posting events to a queue. \n"
      "Events can be posted for immediate consumption or some time in the future. \n"
      "Events are processed in the order they are received.")

      .def(py::init<>())

      .def(
          "Start",
          (openpal::ITimer * (openpal::IExecutor::*)(const openpal::TimeDuration&, const openpal::action_t&))
              & openpal::IExecutor::Start,
          ":return: a new timer based on a relative time duration",
          py::arg("duration"), py::arg("action"),
          py::return_value_policy::reference)

      .def(
          "Start",
          (openpal::ITimer * (openpal::IExecutor::*)(const openpal::MonotonicTimestamp&, const openpal::action_t&))
              & openpal::IExecutor::Start,
          ":return: a new timer based on an absolute timestamp of the monotonic clock",
          py::arg("expiration"), py::arg("action"),
          py::return_value_policy::reference)

      .def(
          "Post",
          &openpal::IExecutor::Post,
          ":return: thread-safe way to post an event to be handled asynchronously",
          py::arg("action"));
}

#endif // PYDNP3_OPENPAL
#endif
