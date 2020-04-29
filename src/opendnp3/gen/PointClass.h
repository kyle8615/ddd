#ifndef PYDNP3_OPENDNP3_GEN_POINTCLASS_H
#define PYDNP3_OPENDNP3_GEN_POINTCLASS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/PointClass.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_PointClass(py::module& m)
{
  // ----- enum class: opendnp3::PointClass -----
  py::enum_<opendnp3::PointClass>(m, "PointClass",
      "Class assignment for a measurement point.")

      .value(
          "Class0",
          opendnp3::PointClass::Class0,
          "No event class assignment.")

      .value(
          "Class1",
          opendnp3::PointClass::Class1,
          "Assigned to event class 1.")

      .value(
          "Class2",
          opendnp3::PointClass::Class2,
          "Assigned to event class 2.")

      .value(
          "Class3",
          opendnp3::PointClass::Class3,
          "Assigned to event class 3.");
}

#endif // PYDNP3_OPENDNP3
#endif
