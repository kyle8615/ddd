#ifndef PYDNP3_OPENPAL_SERIALIZATION_FLOATBYTEORDER_H
#define PYDNP3_OPENPAL_SERIALIZATION_FLOATBYTEORDER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/serialization/FloatByteOrder.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_FloatByteOrder(py::module& m)
{
  // ----- enum class: openpal::FloatByteOrder::Value -----
  py::enum_<openpal::FloatByteOrder::Value>(m, "FloatByteOrderValue")
      .value("NORMAL", openpal::FloatByteOrder::Value::NORMAL)
      .value("REVERSE", openpal::FloatByteOrder::Value::REVERSE)
      .value("UNSUPPORTED", openpal::FloatByteOrder::Value::UNSUPPORTED);

  // ----- class: openpal::FloatByteOrder -----
  py::class_<openpal::FloatByteOrder>(m, "FloatByteOrder")

      .def_property_readonly_static(
          "ORDER",
          [](py::object) { return openpal::FloatByteOrder::ORDER; });
}

#endif // PYDNP3_OPENPAL
#endif
