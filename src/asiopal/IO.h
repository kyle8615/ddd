#ifndef PYDNP3_ASIOPAL_IO_H
#define PYDNP3_ASIOPAL_IO_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/IO.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal {
/**
* Overriding virtual functions from interface class IO.
*/
class PyIO : public IO {
  public:
  /* Inherit the constructors */
  using IO::IO;
};
}

void bind_IO(py::module& m)
{
  // ----- class: asiopal::IO -----
  py::class_<asiopal::IO, asiopal::PyIO, std::shared_ptr<asiopal::IO>>(m, "IO",
      "Container class for an asio::io_service.")

      .def(py::init<>())

      .def_readonly(
          "service",
          &asiopal::IO::service);
}

#endif // PYDNP3_ASIOPAL
#endif
