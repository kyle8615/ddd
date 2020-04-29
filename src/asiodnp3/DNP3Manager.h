#ifndef PYDNP3_ASIODNP3_DNP3MANAGER_H
#define PYDNP3_ASIODNP3_DNP3MANAGER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/DNP3Manager.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_DNP3Manager(py::module& m)
{
  // ----- class: asiodnp3::DNP3Manager -----
  py::class_<asiodnp3::DNP3Manager, std::shared_ptr<asiodnp3::DNP3Manager>>(m, "DNP3Manager",
      "Root DNP3 object used to create channels and sessions.")

      .def(
          py::init<uint32_t>(),
          py::arg("concurrencyHint"))

      .def(
          py::init<uint32_t, std::shared_ptr<openpal::ILogHandler>>(),
          py::arg("concurrencyHint"), py::arg("handler"))

      .def(
          py::init<uint32_t, std::shared_ptr<openpal::ILogHandler>, std::function<void()>>(),
          py::arg("concurrencyHint"), py::arg("handler"), py::arg("onThreadStart"))

      .def(
          py::init<uint32_t, std::shared_ptr<openpal::ILogHandler>, std::function<void()>, std::function<void()>>(),
          "   Construct a manager: \n"
          ":param concurrencyHint: How many threads to allocate in the thread pool \n"
          ":param handler: Callback interface for log messages \n"
          ":param onThreadStart Action to run when a thread pool thread starts \n"
          ":param onThreadExit Action to run just before a thread pool thread exits",
          py::arg("concurrencyHint"), py::arg("handler"), py::arg("onThreadStart"), py::arg("onThreadExit"))

      .def(
          "__del__",
          [](asiodnp3::DNP3Manager& self) {
            self.~DNP3Manager();
          },
          "Destructor with gil_scoped_release.",
          py::call_guard<py::gil_scoped_release>())

      .def(
          "Shutdown",
          [](asiodnp3::DNP3Manager& self) {
            self.Shutdown();
            self.~DNP3Manager();
          },
          "Permanently shutdown the manager and all sub-objects that have been created. Stop the thread pool.",
          py::call_guard<py::gil_scoped_release>())

      .def(
          "AddTCPClient", (std::shared_ptr<asiodnp3::IChannel>(asiodnp3::DNP3Manager::*)(const std::string&, int32_t, const asiopal::ChannelRetry&, const std::string&, const std::string&, uint16_t, std::shared_ptr<asiodnp3::IChannelListener>)) & asiodnp3::DNP3Manager::AddTCPClient,
          "   Add a persistent TCP client channel. Automatically attempts to reconnect.\n"
          ":param id: Alias that will be used for logging purposes with this channel \n"
          ":param levels: Bitfield that describes the logging level for this channel and associated sessions \n"
          ":param retry: Retry parameters for failed channels \n"
          ":param host: IP address of remote outstation (i.e. 127.0.0.1 or www.google.com) \n"
          ":param local: adapter address on which to attempt the connection (use 0.0.0.0 for all adapters) \n"
          ":param port: Port of remote outstation is listening on \n"
          ":param listener optional callback interface (can be nullptr) for info about the running channel \n"
          ":return: shared_ptr to a channel interface",
          py::call_guard<py::gil_scoped_release>(),
          py::arg("id"), py::arg("levels"), py::arg("retry"), py::arg("host"), py::arg("local"), py::arg("port"), py::arg("listener"),
          py::return_value_policy::reference)

      .def(
          "AddTCPClient", (std::shared_ptr<asiodnp3::IChannel>(asiodnp3::DNP3Manager::*)(const std::string&, int32_t, const asiopal::ChannelRetry&, const std::vector<asiopal::IPEndpoint>&, const std::string&, std::shared_ptr<asiodnp3::IChannelListener>)) & asiodnp3::DNP3Manager::AddTCPClient,
          "   Add a persistent TCP client channel. Automatically attempts to reconnect.\n"
          ":param id: Alias that will be used for logging purposes with this channel \n"
          ":param levels: Bitfield that describes the logging level for this channel and associated sessions \n"
          ":param retry: Retry parameters for failed channels \n"
          ":param hosts: List of host addresses to use to connect to the remote outstation (i.e. 127.0.0.1 or www.google.com) \n"
          ":param local: adapter address on which to attempt the connection (use 0.0.0.0 for all adapters) \n"
          ":param listener optional callback interface (can be nullptr) for info about the running channel \n"
          ":return: shared_ptr to a channel interface",
          py::call_guard<py::gil_scoped_release>(),
          py::arg("id"), py::arg("levels"), py::arg("retry"), py::arg("hosts"), py::arg("local"), py::arg("listener"),
          py::return_value_policy::reference)

      // @todo Return value policies still experimental
      //.def("AddTCPServer", &asiodnp3::DNP3Manager::AddTCPServer, py::return_value_policy::reference_internal, py::keep_alive<1,0>())
      .def(
          "AddTCPServer",
          &asiodnp3::DNP3Manager::AddTCPServer,
          "   Add a persistent TCP server channel. Only accepts a single connection at a time. \n"
          ":param id: Alias that will be used for logging purposes with this channel \n"
          ":param levels: Bitfield that describes the logging level for this channel and associated sessions \n"
          ":param mode: Describes how new connections are treated when another session already exists \n"
          ":param endpoint: Network adapter to listen on, i.e. 128.0.0.1 or 0.0.0.0 \n"
          ":param port: Port to listen on \n"
          ":param listener: optional callback interface (can be nullptr) for info about the running channel \n"
          ":return: shared_ptr to a channel interface",
          py::call_guard<py::gil_scoped_release>(),
          py::arg("id"), py::arg("levels"), py::arg("mode"), py::arg("endpoint"), py::arg("port"), py::arg("listener"),
          py::return_value_policy::reference)

      .def(
          "AddSerial",
          &asiodnp3::DNP3Manager::AddSerial,
          "   Add a persistent TCP serial channel. \n"
          ":param id: Alias that will be used for logging purposes with this channel \n"
          ":param levels: Bitfield that describes the logging level for this channel and associated sessions \n"
          ":param retry: Retry parameters for failed channels \n"
          ":param settings: settings object that fully parameterizes the serial port \n"
          ":param listener: optional callback interface (can be nullptr) for info about the running channel \n"
          ":return: shared_ptr to a channel interface",
          py::arg("id"), py::arg("levels"), py::arg("retry"), py::arg("settings"), py::arg("listener"),
          py::return_value_policy::reference)

      .def(
          "AddTLSClient", (std::shared_ptr<asiodnp3::IChannel>(asiodnp3::DNP3Manager::*)(const std::string&, int32_t, const asiopal::ChannelRetry&, const std::string&, const std::string&, uint16_t, const asiopal::TLSConfig&, std::shared_ptr<asiodnp3::IChannelListener>, std::error_code&)) & asiodnp3::DNP3Manager::AddTLSClient,
          "   Add a TLS client channel. \n"
          ":throw std::system_error Throws underlying ASIO exception of TLS configuration is invalid \n"
          ":param id: Alias that will be used for logging purposes with this channel \n"
          ":param levels: Bitfield that describes the logging level for this channel and associated sessions \n"
          ":param retry: Retry parameters for failed channels \n"
          ":param host: IP address of remote outstation (i.e. 127.0.0.1 or www.google.com) \n"
          ":param local: adapter address on which to attempt the connection (use 0.0.0.0 for all adapters) \n"
          ":param port: Port of remote outstation is listening on \n"
          ":param config: TLS configuration information \n"
          ":param listener: optional callback interface (can be nullptr) for info about the running channel \n"
          ":param ec: An error code. If set, a nullptr will be returned \n"
          ":return: shared_ptr to a channel interface",
          py::arg("id"), py::arg("levels"), py::arg("retry"), py::arg("host"), py::arg("local"), py::arg("port"), py::arg("config"), py::arg("listener"), py::arg("ec"),
          py::return_value_policy::reference)

      .def(
          "AddTLSClient", (std::shared_ptr<asiodnp3::IChannel>(asiodnp3::DNP3Manager::*)(const std::string&, int32_t, const asiopal::ChannelRetry&, const std::vector<asiopal::IPEndpoint>&, const std::string&, const asiopal::TLSConfig&, std::shared_ptr<asiodnp3::IChannelListener>, std::error_code&)) & asiodnp3::DNP3Manager::AddTLSClient,
          "   Add a TLS client channel. \n"
          ":throw std::system_error Throws underlying ASIO exception of TLS configuration is invalid \n"
          ":param id: Alias that will be used for logging purposes with this channel \n"
          ":param levels: Bitfield that describes the logging level for this channel and associated sessions \n"
          ":param retry: Retry parameters for failed channels \n"
          ":param hosts: List of host addresses to use to connect to the remote outstation (i.e. 127.0.0.1 or www.google.com) \n"
          ":param local: adapter address on which to attempt the connection (use 0.0.0.0 for all adapters) \n"
          ":param config: TLS configuration information \n"
          ":param listener: optional callback interface (can be nullptr) for info about the running channel \n"
          ":param ec: An error code. If set, a nullptr will be returned \n"
          ":return: shared_ptr to a channel interface",
          py::arg("id"), py::arg("levels"), py::arg("retry"), py::arg("hosts"), py::arg("local"), py::arg("config"), py::arg("listener"), py::arg("ec"),
          py::return_value_policy::reference)

      .def(
          "AddTLSServer",
          &asiodnp3::DNP3Manager::AddTLSServer,
          "   Add a TLS server channel. \n"
          ":throw std::system_error Throws underlying ASIO exception of TLS configuration is invalid \n"
          ":param id: Alias that will be used for logging purposes with this channel \n"
          ":param levels: Bitfield that describes the logging level for this channel and associated sessions \n"
          ":param mode: Describes how new connections are treated when another session already exists \n"
          ":param endpoint: Network adapter to listen on, i.e. 127.0.0.1 or 0.0.0.0 \n"
          ":param port: Port to listen on \n"
          ":param config: TLS configuration information \n"
          ":param listener: optional callback interface (can be nullptr) for info about the running channel \n"
          ":param ec: An error code. If set, a nullptr will be returned \n"
          ":return: shared_ptr to a channel interface",
          py::arg("id"), py::arg("levels"), py::arg("mode"), py::arg("endpoint"), py::arg("port"), py::arg("config"), py::arg("listener"), py::arg("ec"),
          py::return_value_policy::reference)

      .def(
          "CreateListener",
          (std::shared_ptr<asiopal::IListener>(asiodnp3::DNP3Manager::*)(std::string,
              openpal::LogFilters,
              asiopal::IPEndpoint,
              const std::shared_ptr<asiodnp3::IListenCallbacks>&,
              std::error_code&))
              & asiodnp3::DNP3Manager::CreateListener,
          "   Create a TCP listener that will be used to accept incoming connections. \n"
          ":return: shared_ptr to a listener interface",
          py::arg("loggerid"), py::arg("loglevel"), py::arg("endpoint"), py::arg("callbacks"), py::arg("ec"))

      .def("CreateListener",
          (std::shared_ptr<asiopal::IListener>(asiodnp3::DNP3Manager::*)(std::string, openpal::LogFilters, asiopal::IPEndpoint, const asiopal::TLSConfig&, const std::shared_ptr<asiodnp3::IListenCallbacks>&, std::error_code&)) & asiodnp3::DNP3Manager::CreateListener,
          "   Create a TLS listener that will be used to accept incoming connections. \n"
          ":return: shared_ptr to a listener interface",
          py::arg("loggerid"), py::arg("loglevel"), py::arg("endpoint"), py::arg("config"), py::arg("callbacks"), py::arg("ec"));
}

#endif // PYDNP3_ASIODNP3
#endif
