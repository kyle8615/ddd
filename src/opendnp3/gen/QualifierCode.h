#ifndef PYDNP3_OPENDNP3_GEN_QUALIFIERCODE_H
#define PYDNP3_OPENDNP3_GEN_QUALIFIERCODE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/QualifierCode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_QualifierCode(py::module& m)
{
  // ----- enum class: opendnp3::QualifierCode -----
  py::enum_<opendnp3::QualifierCode>(m, "QualifierCode",
      "Object header range/prefix as a single enumeration.")

      .value("UINT8_START_STOP", opendnp3::QualifierCode::UINT8_START_STOP)
      .value("UINT16_START_STOP", opendnp3::QualifierCode::UINT16_START_STOP)
      .value("ALL_OBJECTS", opendnp3::QualifierCode::ALL_OBJECTS)
      .value("UINT8_CNT", opendnp3::QualifierCode::UINT8_CNT)
      .value("UINT16_CNT", opendnp3::QualifierCode::UINT16_CNT)
      .value("UINT8_CNT_UINT8_INDEX", opendnp3::QualifierCode::UINT8_CNT_UINT8_INDEX)
      .value("UINT16_CNT_UINT16_INDEX", opendnp3::QualifierCode::UINT16_CNT_UINT16_INDEX)
      .value("UINT16_FREE_FORMAT", opendnp3::QualifierCode::UINT16_FREE_FORMAT)
      .value("UNDEFINED", opendnp3::QualifierCode::UNDEFINED);

  // ----- function: opendnp3::QualifierCodeToType -----
  m.def(
      "QualifierCodeToType",
      &opendnp3::QualifierCodeToType,
      py::arg("code"));

  // ----- function: opendnp3::QualifierCodeFromType -----
  m.def(
      "QualifierCodeFromType",
      &opendnp3::QualifierCodeFromType,
      ":type rawType: unsigned char",
      py::arg("rawType"));

  // ----- function: opendnp3::QualifierCodeToString -----
  m.def(
      "QualifierCodeToString",
      &opendnp3::QualifierCodeToString,
      py::arg("code"));
}

#endif // PYDNP3_OPENDNP3
#endif
