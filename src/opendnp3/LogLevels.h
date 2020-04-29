#ifndef PYDNP3_OPENDNP3_LOGLEVELS_H
#define PYDNP3_OPENDNP3_LOGLEVELS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/LogLevels.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_OpendnpLogLevels(py::module& m)
{
  // ----- constants: opendnp3::flags -----
  m.def_submodule("flags").attr("EVENT") = &opendnp3::flags::EVENT;
  m.def_submodule("flags").attr("ERR") = &opendnp3::flags::ERR;
  m.def_submodule("flags").attr("WARN") = &opendnp3::flags::WARN;
  m.def_submodule("flags").attr("INFO") = &opendnp3::flags::INFO;
  m.def_submodule("flags").attr("DBG") = &opendnp3::flags::DBG;
  m.def_submodule("flags").attr("LINK_RX") = &opendnp3::flags::LINK_RX;
  m.def_submodule("flags").attr("LINK_RX_HEX") = &opendnp3::flags::LINK_RX_HEX;
  m.def_submodule("flags").attr("LINK_TX") = &opendnp3::flags::LINK_TX;
  m.def_submodule("flags").attr("LINK_TX_HEX") = &opendnp3::flags::LINK_TX_HEX;
  m.def_submodule("flags").attr("TRANSPORT_RX") = &opendnp3::flags::TRANSPORT_RX;
  m.def_submodule("flags").attr("TRANSPORT_TX") = &opendnp3::flags::TRANSPORT_TX;
  m.def_submodule("flags").attr("APP_HEADER_RX") = &opendnp3::flags::APP_HEADER_RX;
  m.def_submodule("flags").attr("APP_HEADER_TX") = &opendnp3::flags::APP_HEADER_TX;
  m.def_submodule("flags").attr("APP_OBJECT_RX") = &opendnp3::flags::APP_OBJECT_RX;
  m.def_submodule("flags").attr("APP_OBJECT_TX") = &opendnp3::flags::APP_OBJECT_TX;
  m.def_submodule("flags").attr("APP_HEX_RX") = &opendnp3::flags::APP_HEX_RX;
  m.def_submodule("flags").attr("APP_HEX_TX") = &opendnp3::flags::APP_HEX_TX;

  // ----- constants: opendnp3::level -----
  m.def_submodule("levels").attr("NOTHING") = &opendnp3::levels::NOTHING;
  m.def_submodule("levels").attr("ALL") = &opendnp3::levels::ALL;
  m.def_submodule("levels").attr("NORMAL") = &opendnp3::levels::NORMAL;
  m.def_submodule("levels").attr("ALL_APP_COMMS") = &opendnp3::levels::ALL_APP_COMMS;
  m.def_submodule("levels").attr("ALL_COMMS") = &opendnp3::levels::ALL_COMMS;

  // ----- func: opendnp3::LogFlagToString -----
  m.def(
      "LogFlagToString",
      &opendnp3::LogFlagToString,
      py::arg("flag"));
}

#endif // PYDNP3_OPENDNP3
#endif
