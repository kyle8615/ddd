#ifndef PYDNP3_OPENDNP3_MASTER_HEADERINFO_H
#define PYDNP3_OPENDNP3_MASTER_HEADERINFO_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/HeaderInfo.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_HeaderInfo(py::module& m)
{
  py::class_<opendnp3::HeaderInfo>(m, "HeaderInfo",
      "Simple structure used in the ISOEHandler callbacks to return information about the associated header.")

      .def(py::init<>())

      .def(
          py::init<opendnp3::GroupVariation, opendnp3::QualifierCode, opendnp3::TimestampMode, uint32_t>(),
          ":type headerIndex: unsigned int",
          py::arg("gv"), py::arg("qualifier"), py::arg("tsmode"), py::arg("headerIndex"))

      .def_readwrite(
          "gv",
          &opendnp3::HeaderInfo::gv,
          "The group/variation enumeration for the header.")

      .def_readwrite(
          "qualifier",
          &opendnp3::HeaderInfo::qualifier,
          "The qualifier code enumeration for the header.")

      .def_readwrite(
          "tsmode",
          &opendnp3::HeaderInfo::tsmode,
          "Enumeration that provides information about the validity of timestamps on the associated objects.")

      .def_readwrite(
          "isEventVariation",
          &opendnp3::HeaderInfo::isEventVariation,
          "True if the specfied variation is an event variation.")

      .def_readwrite(
          "flagsValid",
          &opendnp3::HeaderInfo::flagsValid,
          "True if the flags on the value were present on underlying type, false if online is just assumed.")

      .def_readwrite(
          "headerIndex",
          &opendnp3::HeaderInfo::headerIndex,
          "   The 0-based index of the header within the ASDU. \n"
          ":type headerIndex: unsigned int");
}

#endif // PYDNP3_OPENDNP3
#endif
