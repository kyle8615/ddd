#ifndef PYDNP3_OPENDNP3_GEN_INDEXMODE_H
#define PYDNP3_OPENDNP3_GEN_INDEXMODE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/IndexMode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_IndexMode(py::module& m)
{
  // ----- enum class: opendnp3::IndexMode -----
  py::enum_<opendnp3::IndexMode>(m, "IndexMode",
      "Select contiguous or dis-contiguous index mode.")

      .value(
          "Contiguous",
          opendnp3::IndexMode::Contiguous,
          "Indices are contiguous. Most efficient as direct indexing is used.")

      .value(
          "Discontiguous",
          opendnp3::IndexMode::Discontiguous,
          "Indices are dis-contiguous. Resorts to binary search to find raw index.");
}

#endif // PYDNP3_OPENDNP3
#endif
