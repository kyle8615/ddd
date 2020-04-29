#ifndef PYDNP3_ASIOPAL_TIMER_H
#define PYDNP3_ASIOPAL_TIMER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/Timer.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_Timer(py::module& m)
{
  // ----- class: asiopal::Timer -----
  py::class_<asiopal::Timer>(m, "Timer",
      "Implementation of openpal::ITimer backed by asio::basic_waitable_timer<steady_clock>.")

      .def(
          py::init<asio::io_context&>(),
          py::arg("service"))

      .def(
          "Cancel",
          &asiopal::Timer::Cancel)

      .def(
          "ExpireAt",
          &asiopal::Timer::ExpiresAt);
}

#endif // PYDNP3_ASIOPAL
#endif
