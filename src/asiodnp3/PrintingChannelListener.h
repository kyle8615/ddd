#ifndef PYDNP3_ASIODNP3_PRINTINGCHANNELLISTENER_H
#define PYDNP3_ASIODNP3_PRINTINGCHANNELLISTENER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/PrintingChannelListener.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_PrintingChannelListener(py::module& m)
{
  // ----- class: asiodnp3::PrintingChannelListener -----
  py::class_<asiodnp3::PrintingChannelListener,
      asiodnp3::IChannelListener,
      std::shared_ptr<asiodnp3::PrintingChannelListener>>(m, "PrintingChannelListener",
      "Callback interface for receiving information about a running channel.")

      .def(py::init<>())

      // @todo Return value policy experimental
      .def_static(
          "Create",
          &asiodnp3::PrintingChannelListener::Create,
          ":return: shared_ptr to asiodnp3.IChannelListener",
          py::return_value_policy::reference)

      .def(
          "OnStateChange",
          &asiodnp3::PrintingChannelListener::OnStateChange);
}

#endif // PYDNP3_ASIODNP3
#endif
