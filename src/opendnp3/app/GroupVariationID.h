#ifndef PYDNP3_OPENDNP3_APP_GROUPVARIATIONID_H
#define PYDNP3_OPENDNP3_APP_GROUPVARIATIONID_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/GroupVariationID.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_GroupVariationID(py::module& m)
{
  // ----- class: opendnp3::GroupVariationID -----
  py::class_<opendnp3::GroupVariationID>(m, "GroupVariationID",
      "Simple uint8_t/uint8_t tuple for group and variation.")

      .def(
          py::init<uint8_t, uint8_t>(),
          ":param group: defaults to 0xFF \n"
          ":param variation: defaults to 0xFF \n"
          ":type group: unsigned char \n"
          ":type varitaion: unsigned char",
          py::arg("group") = 0xFF, py::arg("variation") = 0xFF)

      .def_readwrite(
          "group",
          &opendnp3::GroupVariationID::group,
          ":type group: unsigned char")

      .def_readwrite(
          "variation",
          &opendnp3::GroupVariationID::variation,
          ":type varitaion: unsigned char");
}

#endif // PYDNP3_OPENDNP3
#endif
