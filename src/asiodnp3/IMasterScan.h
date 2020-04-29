#ifndef PYDNP3_ASIODNP3_IMASTERSCAN_H
#define PYDNP3_ASIODNP3_IMASTERSCAN_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/IMasterScan.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3 {
/**
* Overriding virtual functions from interface class IMasterScan.
*/
class PyIMasterScan : public IMasterScan {
  /* Inherit the constructors */
  using IMasterScan::IMasterScan;

  /* Trampoline for IMasterScan virtual functions */
  void Demand() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IMasterScan,
        Demand, );
  }
};
}

void bind_IMasterScan(py::module& m)
{
  // ----- class: asiodnp3::IMasterScan -----
  py::class_<asiodnp3::IMasterScan, asiodnp3::PyIMasterScan, std::shared_ptr<asiodnp3::IMasterScan>>(m, "IMasterScan",
      "Interface for interacting with a permanently bound scan.")

      .def(py::init<>())

      .def(
          "Demand",
          &asiodnp3::IMasterScan::Demand,
          "Request that the scan be performed as soon as possible.");
}

#endif // PYDNP3_ASIODNP3
#endif
