#ifndef PYDNP3_ASIOPAL_STEADYCLOCK_H
#define PYDNP3_ASIOPAL_STEADYCLOCK_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/SteadyClock.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_SteadyClock(py::module& m)
{
  // ----- struct: asiopal::steady_clock_t -----
  py::class_<asiopal::steady_clock_t>(m, "steady_clock_t",
      "Custom steady clock implementation to handle the situation where the Windows steady clock implementation "
      "is not monotonic. \n"
      "Normal steady clock implementation is used on other platforms.")

      .def(py::init<>())

      .def_static(
          "now",
          &asiopal::steady_clock_t::now);
}

#endif // PYDNP3_ASIOPAL
#endif
