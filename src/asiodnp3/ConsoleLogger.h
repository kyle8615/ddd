#ifndef PYDNP3_ASIODNP3_CONSOLELOGGER_H
#define PYDNP3_ASIODNP3_CONSOLELOGGER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/ConsoleLogger.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_ConsoleLogger(py::module &m)
{
  // ----- class: asiodnp3::ConsoleLogger -----
    py::class_<asiodnp3::ConsoleLogger,
               openpal::ILogHandler,
               std::shared_ptr<asiodnp3::ConsoleLogger>>(m, "ConsoleLogger",
        "LogHandler that prints all log messages to the console.")

        .def(
            py::init<bool>(),
            ":param printLocation: defaults to False",
            py::arg("printLocation") = false
        )

        .def(
            "Log",
            &asiodnp3::ConsoleLogger::Log,
            "   Callback method for log messages. \n"
            ":param entry: the log message to handle",
            py::arg("entry")
        )

        .def_static(
            "Create",
            &asiodnp3::ConsoleLogger::Create,
            ":param printLocation: defaults to False \n"
            ":return: shared_ptr to openpal.ILogHandler",
            py::arg("printLocation") = false
        );
}

#endif // PYDNP3_ASIODNP3
#endif
