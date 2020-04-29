#ifndef PYDNP3_OPENDNP3_MASTER_ICOMMANDCOLLECTION_H
#define PYDNP3_OPENDNP3_MASTER_ICOMMANDCOLLECTION_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/ICommandCollection.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class ICommandCollection<T>.
*/
template <class T>
class PyICommandCollection : public ICommandCollection<T> {
  public:
  /* Trampoline for ICommandCollection virtual functions */
  ICommandCollection<T>& Add(const T& command, uint16_t index) override
  {
    PYBIND11_OVERLOAD_PURE(
        ICommandCollection<T>&,
        ICommandCollection<T>,
        Add,
        command, index);
  }
};
}

template <class T>
void declareICommandCollection(py::module& m, string const& type)
{
  // ----- class: opendnp3::ICommandCollection<T> -----
  py::class_<opendnp3::ICommandCollection<T>,
      opendnp3::PyICommandCollection<T>>(m, ("ICommandCollection" + type).c_str(),
      "A collection type for command to which the user can add by type and index.")

      .def(py::init<>())

      .def(
          "Add",
          &opendnp3::ICommandCollection<T>::Add,
          py::arg("command"), py::arg("index"));
}

void bind_ICommandCollection(py::module& m)
{
  declareICommandCollection<opendnp3::ControlRelayOutputBlock>(m, "ControlRelayOutputBlock");
  declareICommandCollection<opendnp3::AnalogOutputInt32>(m, "AnalogOutputInt32");
  declareICommandCollection<opendnp3::AnalogOutputInt16>(m, "AnalogOutputInt16");
  declareICommandCollection<opendnp3::AnalogOutputFloat32>(m, "AnalogOutputFloat32");
  declareICommandCollection<opendnp3::AnalogOutputDouble64>(m, "AnalogOutputDouble64");
}

#endif // PYDNP3_OPENDNP3
#endif
