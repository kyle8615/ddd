#ifndef PYDNP3_OPENDNP3_MASTER_IMASTERAPPLICATION_H
#define PYDNP3_OPENDNP3_MASTER_IMASTERAPPLICATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/IMasterApplication.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class IMasterApplication.
*/
class PyIMasterApplication : public IMasterApplication {
  public:
  /* Inherit the constructors */
  using IMasterApplication::IMasterApplication;

  /* Trampoline for IMasterApplication virtual functions */
  void OnReceiveIIN(const IINField& iin) override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        OnReceiveIIN,
        iin);
  }
  void OnTaskStart(MasterTaskType type, TaskId id) override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        OnTaskStart,
        type,
        id);
  }
  void OnTaskComplete(const TaskInfo& info) override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        OnTaskComplete,
        info);
  }
  void OnOpen() override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        OnOpen);
  }
  void OnClose() override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        OnClose);
  }
  bool AssignClassDuringStartup() override
  {
    PYBIND11_OVERLOAD(
        bool,
        IMasterApplication,
        AssignClassDuringStartup);
  }
  void ConfigureAssignClassRequest(const WriteHeaderFunT& fun) override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        ConfigureAssignClassRequest,
        fun);
  }

  /* Trampoline for ILinkListener virtual functions */
  void OnStateChange(LinkStatus value) override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        OnStateChange,
        value);
  }
  void OnKeepAliveInitiated() override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        OnKeepAliveInitiated, );
  }
  void OnKeepAliveFailure() override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        OnKeepAliveFailure, );
  }
  void OnKeepAliveSuccess() override
  {
    PYBIND11_OVERLOAD(
        void,
        IMasterApplication,
        OnKeepAliveSuccess, );
  }

  /* Trampoline for IUTCTimeSource virtual functions */
  openpal::UTCTimestamp Now() override
  {
    PYBIND11_OVERLOAD_PURE(
        openpal::UTCTimestamp,
        IMasterApplication,
        Now, );
  }
};
}

void bind_IMasterApplication(py::module& m)
{
  // ----- class: opendnp3::WriteHeaderFunT -----
  py::class_<opendnp3::WriteHeaderFunT>(m, "WriteHeaderFunT")
      .def(py::init<>());

  // ----- class: opendnp3::IMasterApplication -----
  py::class_<opendnp3::IMasterApplication,
      opendnp3::PyIMasterApplication,
      opendnp3::ILinkListener,
      openpal::IUTCTimeSource,
      std::shared_ptr<opendnp3::IMasterApplication>>(m, "IMasterApplication",
      "Interface for all master application callback info except for measurement values.")

      .def(py::init<>())

      .def(
          "OnReceiveIIN",
          &opendnp3::IMasterApplication::OnReceiveIIN,
          "Called when a response or unsolicited response is receive from the outstation.",
          py::arg("iin"))

      .def(
          "OnTaskStart",
          &opendnp3::IMasterApplication::OnTaskStart,
          "Task start notification.",
          py::arg("type"), py::arg("id"))

      .def(
          "OnTaskComplete",
          &opendnp3::IMasterApplication::OnTaskComplete,
          "Task completion notification.",
          py::arg("info"))

      .def(
          "OnOpen",
          &opendnp3::IMasterApplication::OnOpen,
          "Called when the application layer is opened.")

      .def(
          "OnClose",
          &opendnp3::IMasterApplication::OnClose,
          "Called when the application layer is closed.")

      .def(
          "AssignClassDuringStartup",
          &opendnp3::IMasterApplication::AssignClassDuringStartup,
          "Return true if the master should do an assign class task during startup handshaking.")

      .def(
          "ConfigureAssignClassRequest",
          &opendnp3::IMasterApplication::ConfigureAssignClassRequest,
          "Configure the request headers for assign class. \n"
          "Only called if AssignClassDuringStartup returns true. \n"
          "The user only needs to call the function for each header type to be written.",
          py::arg("fun"));
}

#endif // PYDNP3_OPENDNP3
#endif
