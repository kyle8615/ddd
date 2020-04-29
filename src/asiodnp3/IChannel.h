#ifndef PYDNP3_ASIODNP3_ICHANNEL_H
#define PYDNP3_ASIODNP3_ICHANNEL_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/IChannel.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3 {
/**
* Overriding virtual functions from interface class IChannel.
*/
class PyIChannel : public IChannel {
  public:
  /* Inherit the constructors */
  using IChannel::IChannel;

  /* Trampoline for IResource virtual functions */
  void Shutdown() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IChannel,
        Shutdown, );
  }

  /* Trampoline for IChannel virtual functions */
  opendnp3::LinkStatistics GetStatistics() override
  {
    PYBIND11_OVERLOAD_PURE(
        opendnp3::LinkStatistics,
        IChannel,
        GetStatistics, );
  }
  openpal::LogFilters GetLogFilters() const override
  {
    PYBIND11_OVERLOAD_PURE(
        openpal::LogFilters,
        IChannel,
        GetLogFilters, );
  }
  void SetLogFilters(const openpal::LogFilters& filters) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IChannel,
        SetLogFilters,
        filters);
  }
  std::shared_ptr<IMaster> AddMaster(const std::string& id,
      std::shared_ptr<opendnp3::ISOEHandler> SOEHandler,
      std::shared_ptr<opendnp3::IMasterApplication> application,
      const MasterStackConfig& config) override
  {
    PYBIND11_OVERLOAD_PURE(
        std::shared_ptr<IMaster>,
        IChannel,
        AddMaster,
        id, SOEHandler, application, config);
  }
  std::shared_ptr<IOutstation> AddOutstation(const std::string& id,
      std::shared_ptr<opendnp3::ICommandHandler> commandHandler,
      std::shared_ptr<opendnp3::IOutstationApplication> application,
      const OutstationStackConfig& config) override
  {
    PYBIND11_OVERLOAD_PURE(
        std::shared_ptr<IOutstation>,
        IChannel,
        AddOutstation,
        id, commandHandler, application, config);
  }
};
}

void bind_IChannel(py::module& m)
{
  // ----- class: asiodnp3::IChannel -----
  py::class_<asiodnp3::IChannel,
      asiodnp3::PyIChannel,
      asiopal::IResource,
      std::shared_ptr<asiodnp3::IChannel>>(m, "IChannel",
      "Represents a communication channel upon which masters and outstations can be bound.")

      .def(py::init<>())

      .def(
          "GetStatistics",
          &asiodnp3::IChannel::GetStatistics,
          "Synchronously read the channel statistics.")

      .def(
          "GetLogFilters",
          &asiodnp3::IChannel::GetLogFilters,
          ":return: the current logger settings for this channel")

      .def(
          "SetLogFilters",
          &asiodnp3::IChannel::SetLogFilters,
          ":param filters: adjust the filters to this value",
          py::arg("filters"))

      .def(
          "AddMaster",
          &asiodnp3::IChannel::AddMaster,
          "   Add a master to the channel. \n"
          ":param id: An ID that gets used for logging. \n"
          ":param SOEHandler: Callback object for all received measurements \n"
          ":param application: The master application bound to the master session \n"
          ":param config: Configuration object that controls how the master behaves \n"
          ":return: shared_ptr to the running master",
          py::call_guard<py::gil_scoped_release>(),
          py::arg("id"), py::arg("SOEHandler"), py::arg("application"), py::arg("config"))

      .def(
          "AddOutstation",
          &asiodnp3::IChannel::AddOutstation,
          "   Add an outstation to the channel. \n"
          ":param id: An ID that gets used for logging \n"
          ":param commandHandler: Callback object for handling command requests \n"
          ":param application: Callback object for user code \n"
          ":param config: Configuration object that controls how the outstation behaves \n"
          ":return: shared_ptr to the running outstation",
          py::call_guard<py::gil_scoped_release>(),
          py::arg("id"), py::arg("commandHandler"), py::arg("application"), py::arg("config"));
}

#endif // PYDNP3_ASIODNP3
#endif
