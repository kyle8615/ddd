#ifndef PYDNP3_OPENPAL_CONTAINER_HASSIZE_H
#define PYDNP3_OPENPAL_CONTAINER_HASSIZE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/container/HasSize.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <class W>
void declareHasSize(py::module& m, std::string const& type, std::string const& sizeType)
{
  // ----- class: openpal::HasSize<W> -----
  py::class_<openpal::HasSize<W>>(m, ("HasSize" + type).c_str())

      .def(
          py::init<W>(),
          (":type size: " + sizeType).c_str(),
          py::arg("size"))

      .def(
          "Size",
          &openpal::HasSize<W>::Size)

      .def(
          "IsEmpty",
          &openpal::HasSize<W>::IsEmpty)

      .def(
          "IsNotEmpty",
          &openpal::HasSize<W>::IsNotEmpty);

  // ----- func: openpal::HasSize -----
  m.def(
      "HasSize",
      [](W size) { return openpal::HasSize<W>(size); },
      "Return instance of class HasSize<W>");
}

void bind_HasSize(py::module& m)
{
  declareHasSize<uint16_t>(m, "Uint16", "unsigned short");
  declareHasSize<uint32_t>(m, "Uint32", "unsigned int");
}

#endif // PYDNP3_OPENPAL
#endif
