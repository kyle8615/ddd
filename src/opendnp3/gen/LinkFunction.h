#ifndef PYDNP3_OPENDNP3_GEN_LINKFUNCTION_H
#define PYDNP3_OPENDNP3_GEN_LINKFUNCTION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/LinkFunction.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_LinkFunction(py::module& m)
{
  // ----- enum class: opendnp3::LinkFunction -----
  py::enum_<opendnp3::LinkFunction>(m, "LinkFunction",
      "Link layer function code enumeration.")

      .value("PRI_RESET_LINK_STATES", opendnp3::LinkFunction::PRI_RESET_LINK_STATES)
      .value("PRI_TEST_LINK_STATES", opendnp3::LinkFunction::PRI_TEST_LINK_STATES)
      .value("PRI_CONFIRMED_USER_DATA", opendnp3::LinkFunction::PRI_CONFIRMED_USER_DATA)
      .value("PRI_UNCONFIRMED_USER_DATA", opendnp3::LinkFunction::PRI_UNCONFIRMED_USER_DATA)
      .value("PRI_REQUEST_LINK_STATUS", opendnp3::LinkFunction::PRI_REQUEST_LINK_STATUS)
      .value("SEC_ACK", opendnp3::LinkFunction::SEC_ACK)
      .value("SEC_NACK", opendnp3::LinkFunction::SEC_NACK)
      .value("SEC_LINK_STATUS", opendnp3::LinkFunction::SEC_LINK_STATUS)
      .value("SEC_NOT_SUPPORTED", opendnp3::LinkFunction::SEC_NOT_SUPPORTED)
      .value("INVALID", opendnp3::LinkFunction::INVALID);

  // ----- function: opendnp3::LinkFunctionToType -----
  m.def(
      "LinkFunctionToType",
      &opendnp3::LinkFunctionToType,
      py::arg("linkFunction"));

  // ----- function: opendnp3::LinkFunctionFromType -----
  m.def(
      "LinkFunctionFromType",
      &opendnp3::LinkFunctionFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::LinkFunctionToString -----
  m.def(
      "LinkFunctionToString",
      &opendnp3::LinkFunctionToString,
      py::arg("linkFunction"));
}

#endif // PYDNP3_OPENDNP3
#endif
