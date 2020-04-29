#ifndef PYDNP3_OPENDNP3_OUTSTATION_CELL_H
#define PYDNP3_OPENDNP3_OUTSTATION_CELL_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/Cell.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

template <class Spec>
void declareCell(py::module& m, string const& type)
{
  // ----- struct: opendnp3::SelectedValue<Spec> -----
  py::class_<opendnp3::SelectedValue<Spec>>(m, ("SelectedValue" + type).c_str(),
      "Type used to record whether a value is requested in a response.")

      .def(py::init<>())

      .def_readwrite(
          "selected",
          &opendnp3::SelectedValue<Spec>::selected)

      .def_readwrite(
          "value",
          &opendnp3::SelectedValue<Spec>::value)

      .def_readwrite(
          "variation",
          &opendnp3::SelectedValue<Spec>::variation);

  // ----- struct: opendnp3::Cell<Spec> -----
  py::class_<opendnp3::Cell<Spec>>(m, ("Cell" + type).c_str(),
      "Holds particular measurement type in the database.")

      .def(py::init<>())

      .def_readwrite(
          "value",
          &opendnp3::Cell<Spec>::value,
          "Current value.")

      .def_readwrite(
          "config",
          &opendnp3::Cell<Spec>::config,
          "Configuration.")

      .def_readwrite(
          "event",
          &opendnp3::Cell<Spec>::event,
          "Event cell.")

      .def_readwrite(
          "selection",
          &opendnp3::Cell<Spec>::selection,
          "Selected value.");
}

void bind_Cell(py::module& m)
{
}

#endif // PYDNP3_OPENDNP3
#endif
