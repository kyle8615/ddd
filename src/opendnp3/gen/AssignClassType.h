#ifndef PYDNP3_OPENDNP3_GEN_ASSIGNCLASSTYPE_H
#define PYDNP3_OPENDNP3_GEN_ASSIGNCLASSTYPE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/AssignClassType.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_AssignClassType(py::module& m)
{
  // ----- enum class: opendnp3::AssignClassType -----
  py::enum_<opendnp3::AssignClassType>(m, "AssignClassType",
      "Groups that can be used inconjunction with the ASSIGN_CLASS function code.")

      .value("BinaryInput", opendnp3::AssignClassType::BinaryInput)
      .value("DoubleBinaryInput", opendnp3::AssignClassType::DoubleBinaryInput)
      .value("Counter", opendnp3::AssignClassType::Counter)
      .value("FrozenCounter", opendnp3::AssignClassType::FrozenCounter)
      .value("AnalogInput", opendnp3::AssignClassType::AnalogInput)
      .value("BinaryOutputStatus", opendnp3::AssignClassType::BinaryOutputStatus)
      .value("AnalogOutputStatus", opendnp3::AssignClassType::AnalogOutputStatus);
}

#endif // PYDNP3_OPENDNP3
#endif
