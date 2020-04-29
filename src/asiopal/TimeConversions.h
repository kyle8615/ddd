#ifndef PYDNP3_ASIOPAL_TIMECONVERSIONS_H
#define PYDNP3_ASIOPAL_TIMECONVERSIONS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/TimeConversions.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_TimeConversions(py::module& m)
{
  // ----- class: asiopal::TimeConversions -----
  py::class_<asiopal::TimeConversions>(m, "TimeConversions")

      .def_static(
          "Convert",
          [](const openpal::MonotonicTimestamp& timestamp) {
            return asiopal::TimeConversions::Convert(timestamp);
          })

      .def_static(
          "Convert",
          [](const asiopal::steady_clock_t::time_point& timestamp) {
            return asiopal::TimeConversions::Convert(timestamp);
          });
}

#endif // PYDNP3_ASIOPAL
#endif
