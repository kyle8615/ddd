#ifndef PYDNP3_OPENDNP3_APP_SECURITYSTAT_H
#define PYDNP3_OPENDNP3_APP_SECURITYSTAT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/SecurityStat.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_SecurityStat(py::module& m)
{
  // ----- struct: opendnp3::SecurityStatValue -----
  py::class_<opendnp3::SecurityStat::Value>(m, "SecurityStatValue")

      .def(
          py::init<uint16_t, uint32_t>(),
          ":param assocId: defaults to 0 \n"
          ":param count: defaults to 0 \n"
          ":type assocId: unsigned short \n"
          ":type count: unsigned int",
          py::arg("assocId") = 0, py::arg("count") = 0)

      .def_readwrite(
          "assocId",
          &opendnp3::SecurityStat::Value::assocId,
          ":type assocId: unsigned short")

      .def_readwrite(
          "count",
          &opendnp3::SecurityStat::Value::count,
          ":type count: unsigned int");

  // ----- class: opendnp3::SecurityStat -----
  py::class_<opendnp3::SecurityStat, std::shared_ptr<opendnp3::SecurityStat>>(m, "SecurityStat",
      "SA security statistic object as used by the API.")

      .def(py::init<>())

      .def(
          py::init<opendnp3::SecurityStat::Value, uint8_t, opendnp3::DNPTime>(),
          ":type quality: unsigned char",
          py::arg("value"), py::arg("quality"), py::arg("time"))

      .def(
          py::init<uint8_t, uint16_t, uint32_t>(),
          ":type quality: unsigned char \n"
          ":type assocId: unsigned short \n"
          ":type count: unsigned int",
          py::arg("quality"), py::arg("assocId"), py::arg("count"))

      .def(
          py::init<uint8_t, uint16_t, uint32_t, opendnp3::DNPTime>(),
          ":type quality: unsigned char \n"
          ":type assocId: unsigned short \n"
          ":type count: unsigned int \n",
          py::arg("quality"), py::arg("assocId"), py::arg("count"), py::arg("time"))

      .def_readwrite(
          "quality",
          &opendnp3::SecurityStat::quality,
          ":type quality: unsigned char")

      .def_readwrite(
          "value",
          &opendnp3::SecurityStat::value)

      .def_readwrite(
          "time",
          &opendnp3::SecurityStat::time);
}

#endif // PYDNP3_OPENDNP3
#endif
