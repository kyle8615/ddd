#ifndef PYDNP3_OPENDNP3_GEN_OPERATETYPE_H
#define PYDNP3_OPENDNP3_GEN_OPERATETYPE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/OperateType.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_OperateType(py::module& m)
{
  // ----- enum class: opendnp3::OperateType -----
  py::enum_<opendnp3::OperateType>(m, "OperateType",
      "Various ways that an outstation can receive a request to operate a BO or AO point.")

      .value(
          "SELECT_BEFORE_OPERATE",
          opendnp3::OperateType::SelectBeforeOperate,
          "The outstation received a valid prior SELECT followed by OPERATE.")

      .value(
          "DIRECT_OPERATE",
          opendnp3::OperateType::DirectOperate,
          "The outstation received a direct operate request.")

      .value(
          "DIRECT_OPERATE_NO_ACK",
          opendnp3::OperateType::DirectOperateNoAck,
          "The outstation received a direct operate no ack request.");
}

#endif // PYDNP3_OPENDNP3
#endif
