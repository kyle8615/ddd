#ifndef PYDNP3_OPENDNP3_LINK_LINKCONFIG_H
#define PYDNP3_OPENDNP3_LINK_LINKCONFIG_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/link/LinkConfig.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_LinkConfig(py::module& m)
{
  // ----- struct: opendnp3::LinkConfig -----
  py::class_<opendnp3::LinkConfig>(m, "LinkConfig",
      "Configuration for the dnp3 link layer.")

      .def(
          py::init<bool, bool, uint32_t, uint16_t, uint16_t, openpal::TimeDuration, openpal::TimeDuration>(),
          ":type NumRetry: unsigned int \n"
          ":type LocalAddr: unsigned short \n"
          ":type RemoteAddr: unsigned short",
          py::arg("IsMaster"), py::arg("UseConfirms"), py::arg("NumRetry"), py::arg("LocalAddr"),
          py::arg("RemoteAddr"), py::arg("Timeout"), py::arg("KeepAliveTimeout"))

      .def(
          py::init<bool, bool>(),
          py::arg("IsMaster"), py::arg("UseConfirms"))

      .def(
          "GetAddresses",
          &opendnp3::LinkConfig::GetAddresses,
          "Dnp3 address pair.")

      .def_readwrite(
          "IsMaster",
          &opendnp3::LinkConfig::IsMaster,
          "The master/outstation bit set on all messages.")

      .def_readwrite(
          "UseConfirms",
          &opendnp3::LinkConfig::UseConfirms,
          "If true, the link layer will send data requesting confirmation.")

      .def_readwrite(
          "NumRetry",
          &opendnp3::LinkConfig::NumRetry,
          "   The number of retry attempts the link will attempt after the initial try. \n"
          ":type NumRetry: unsigned int")

      .def_readwrite(
          "LocalAddr",
          &opendnp3::LinkConfig::LocalAddr,
          "   Dnp3 address of the local device. \n"
          ":type LocalAddr: unsigned short")

      .def_readwrite(
          "RemoteAddr",
          &opendnp3::LinkConfig::RemoteAddr,
          "   Dnp3 address of the remote device. \n"
          ":type RemoteAddr: unsigned short")

      .def_readwrite(
          "Timeout",
          &opendnp3::LinkConfig::Timeout,
          "The response timeout in milliseconds for confirmed requests.")

      .def_readwrite(
          "KeepAliveTimeout",
          &opendnp3::LinkConfig::KeepAliveTimeout,
          "The interval for keep-alive messages (link status requests) \n"
          "If set to TimeDuration::Max(), the keep-alive is disabled.");
}

#endif // PYDNP3_OPENDNP3
#endif
