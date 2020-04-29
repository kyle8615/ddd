#ifndef PYDNP3_ASIODNP3_MASTERSTACKCONFIG_H
#define PYDNP3_ASIODNP3_MASTERSTACKCONFIG_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/MasterStackConfig.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_MasterStackConfig(py::module& m)
{
  // ----- class: asiodnp3::MasterStackConfig -----
  py::class_<asiodnp3::MasterStackConfig>(m, "MasterStackConfig",
      "A composite configuration struct that contains all the config information for a dnp3 master stack.")

      .def(py::init<>())

      .def_readwrite(
          "master",
          &asiodnp3::MasterStackConfig::master,
          "Master config.")

      .def_readwrite(
          "link",
          &asiodnp3::MasterStackConfig::link,
          "Link layer config.");
}

#endif // PYDNP3_ASIODNP3
#endif
