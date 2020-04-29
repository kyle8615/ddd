#ifndef PYDNP3_OPENPAL_LOGGING_ILOGHANDLER_H
#define PYDNP3_OPENPAL_LOGGING_ILOGHANDLER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <openpal/logging/ILogHandler.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

namespace openpal {
/**
* Overriding virtual functions from interface class ILogHandler.
*/
class PyILogHandler : public ILogHandler {
  public:
  /* Inherit the constructors */
  using ILogHandler::ILogHandler;

  /* Trampoline for ILogHandler virtual functions */
  void Log(const LogEntry& entry) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ILogHandler,
        Log,
        &entry);
  }
};
}

void bind_ILogHandler(py::module& m)
{
  // ----- class: openpal::ILogHandler -----
  py::class_<openpal::ILogHandler, openpal::PyILogHandler, std::shared_ptr<openpal::ILogHandler>>(m, "ILogHandler",
      "Callback interface for log messages.")

      .def(py::init<>())

      .def(
          "Log",
          &openpal::ILogHandler::Log,
          "   Callback method for log messages. \n"
          ":param entry: the log message to handle",
          py::arg("entry"));
}

#endif // PYDNP3_OPENPAL
#endif
