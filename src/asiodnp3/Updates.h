#ifndef PYDNP3_ASIODNP3_UPDATES_H
#define PYDNP3_ASIODNP3_UPDATES_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/Updates.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_Updates(py::module& m)
{
  // ----- class: asiodnp3::update_func_t -----
  py::class_<asiodnp3::update_func_t>(m, "update_func_t");

  // ----- class: asiodnp3::shared_updates_t -----
  py::class_<asiodnp3::shared_updates_t>(m, "shared_updates_t");

  // ----- class: asiodnp3::Updates -----
  py::class_<asiodnp3::Updates>(m, "Updates")

      .def(
          "Apply",
          &asiodnp3::Updates::Apply,
          py::arg("handler"))

      .def(
          "IsEmpty",
          &asiodnp3::Updates::IsEmpty);
}

#endif // PYDNP3_ASIODNP3
#endif
