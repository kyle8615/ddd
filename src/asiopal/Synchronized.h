#ifndef PYDNP3_ASIOPAL_SYNCHRONIZED_H
#define PYDNP3_ASIOPAL_SYNCHRONIZED_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/Synchronized.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

template <class T>
void declareSynchronized(py::module& m, string const& type)
{
  // ----- class: asiopal::Synchronized<T> -----
  py::class_<asiopal::Synchronized<T>>(m, ("Synchronized" + type).c_str(),
      "Provides thread-safe access to a value that can be set once.")

      .def(py::init<>())

      .def(
          "WaitForValue",
          &asiopal::Synchronized<T>::WaitForValue)

      .def(
          "SetValue",
          &asiopal::Synchronized<T>::SetValue,
          py::arg("value"));
}

void bind_Synchronized(py::module& m)
{
}

#endif // PYDNP3_ASIOPAL
#endif
