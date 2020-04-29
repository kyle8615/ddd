#ifndef PYDNP3_OPENDNP3_GEN_USEROPERATION_H
#define PYDNP3_OPENDNP3_GEN_USEROPERATION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/UserOperation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_UserOperation(py::module& m)
{
  // ----- enum class: opendnp3::UserOperation -----
  py::enum_<opendnp3::UserOperation>(m, "UserOperation",
      "Enumerates possible remote operations on users.")

      .value("OP_ADD", opendnp3::UserOperation::OP_ADD)
      .value("OP_DELETE", opendnp3::UserOperation::OP_DELETE)
      .value("OP_CHANGE", opendnp3::UserOperation::OP_CHANGE)
      .value("OP_UNDEFINED", opendnp3::UserOperation::OP_UNDEFINED);

  // ----- func: opendnp3::UserOperationToType -----
  m.def(
      "UserOperationToType",
      &opendnp3::UserOperationToType,
      py::arg("userOperation"));

  // ----- func: opendnp3::UserOperationFromType -----
  m.def(
      "UserOperationFromType",
      &opendnp3::UserOperationFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- func: opendnp3::UserOperationToString -----
  m.def(
      "UserOperationToString",
      &opendnp3::UserOperationToString,
      py::arg("userOperation"));
}

#endif // PYDNP3_OPENDNP3
#endif
