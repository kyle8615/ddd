#ifndef PYDNP3_OPENDNP3_MASTER_COMMANDPOINTRESULT_H
#define PYDNP3_OPENDNP3_MASTER_COMMANDPOINTRESULT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/CommandPointResult.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CommandPointResult(py::module& m)
{
  py::class_<opendnp3::CommandPointResult>(m, "CommandPointResult",
      "Represents the result of a command operation on a particular point.")

      .def(
          py::init<uint32_t, uint16_t, opendnp3::CommandPointState, opendnp3::CommandStatus>(),
          "   Fully construct based on all members. \n"
          ":type headerIndex: unsigned int \n"
          ":type index: unsigned short",
          py::arg("headerIndex"), py::arg("index"), py::arg("state"), py::arg("status"))

      .def(
          "Equals",
          &opendnp3::CommandPointResult::Equals,
          "Check the result for equality against another value.",
          py::arg("other"))

      .def_readwrite(
          "headerIndex",
          &opendnp3::CommandPointResult::headerIndex,
          "   The index of the header when request was made (0-based). \n"
          ":type headerIndex: unsigned int")

      .def_readwrite(
          "index",
          &opendnp3::CommandPointResult::index,
          "   The index of the command that was requested. \n"
          ":type index: unsigned short")

      .def_readwrite(
          "state",
          &opendnp3::CommandPointResult::state,
          "The final state of the command operation on this point.")

      .def_readwrite(
          "status",
          &opendnp3::CommandPointResult::status,
          "The response value. This is only valid if state == SUCCESS or state == SELECT_FAIL.");
}

#endif // PYDNP3_OPENDNP3
#endif
