#ifndef PYDNP3_OPENPAL_CONTAINER_STATICBUFFER_H
#define PYDNP3_OPENPAL_CONTAINER_STATICBUFFER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/container/StaticBuffer.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <uint32_t SIZE>
void declareStaticBuffer(py::module& m, std::string const& type)
{
  // ----- class: openpal::StaticBuffer<SIZE> -----
  py::class_<openpal::StaticBuffer<SIZE>>(m, ("StaticBuffer" + type).c_str())

      .def(py::init<>())

      .def(
          "ToRSlice",
          (openpal::RSlice(openpal::StaticBuffer<SIZE>::*)() const)
              & openpal::StaticBuffer<SIZE>::ToRSlice)

      .def(
          "ToRSlice",
          (openpal::RSlice(openpal::StaticBuffer<SIZE>::*)(uint32_t) const)
              & openpal::StaticBuffer<SIZE>::ToRSlice,
          ":type maxSize: unsigned int",
          py::arg("maxSize"))

      .def(
          "GetWSlice",
          (openpal::WSlice(openpal::StaticBuffer<SIZE>::*)())
              & openpal::StaticBuffer<SIZE>::GetWSlice)

      .def(
          "GetWSlice",
          (openpal::WSlice(openpal::StaticBuffer<SIZE>::*)(uint32_t))
              & openpal::StaticBuffer<SIZE>::GetWSlice,
          ":type maxSize: unsigned int",
          py::arg("maxSize"))

      .def(
          "Size",
          &openpal::StaticBuffer<SIZE>::Size);
}

void bind_StaticBuffer(py::module& m)
{
  declareStaticBuffer<100>(m, "100");
  declareStaticBuffer<14>(m, "14");
  declareStaticBuffer<292>(m, "292");
  declareStaticBuffer<4>(m, "4");
}

#endif // PYDNP3_OPENPAL
#endif
