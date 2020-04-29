#ifndef PYDNP3_ASIOPAL_EXECUTOR_H
#define PYDNP3_ASIOPAL_EXECUTOR_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/Executor.h>
#include <opendnp3/StackStatistics.h>
#include <opendnp3/link/LinkStatistics.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace openpal {
class LogFilters;
}

void bind_Executor(py::module& m)
{
  // ----- class: asiopal::Executor -----
  py::class_<asiopal::Executor, openpal::IExecutor, std::shared_ptr<asiopal::Executor>>(m, "Executor",
      "Implementation of openpal::IExecutor backed by asio::strand. \n"
      "Shutdown life-cycle guarantees are provided by using std::shared_ptr.")

      .def(
          py::init<const std::shared_ptr<asiopal::IO>&>(),
          py::arg("io"))

      .def_static(
          "Create",
          &asiopal::Executor::Create,
          ":return: shared_ptr to openpal.Executor",
          py::arg("io"))

      .def(
          "GetTime",
          &asiopal::Executor::GetTime)

      .def(
          "Start",
          (openpal::ITimer * (asiopal::Executor::*)(const openpal::TimeDuration&, const openpal::action_t&))
              & asiopal::Executor::Start,
          py::arg("duration"), py::arg("runnable"))

      .def(
          "Start",
          (openpal::ITimer * (asiopal::Executor::*)(const openpal::MonotonicTimestamp&, const openpal::action_t&))
              & asiopal::Executor::Start,
          py::arg("duration"), py::arg("runnable"))

      .def(
          "Post",
          &asiopal::Executor::Post,
          py::arg("runnable"))

      .def(
          "ReturnFrom",
          &asiopal::Executor::ReturnFrom<bool>,
          py::arg("action"))

      .def(
          "ReturnFrom",
          &asiopal::Executor::ReturnFrom<opendnp3::StackStatistics>,
          py::arg("action"))

      .def(
          "ReturnFrom",
          &asiopal::Executor::ReturnFrom<opendnp3::LinkStatistics>,
          py::arg("action"))

      .def(
          "ReturnFrom",
          &asiopal::Executor::ReturnFrom<openpal::LogFilters>,
          py::arg("action"))

      .def(
          "BlockUntil",
          &asiopal::Executor::BlockUntil,
          py::arg("action"))

      .def(
          "BlockUntilAndFlush",
          &asiopal::Executor::BlockUntilAndFlush,
          py::arg("action"))

      .def(
          "Fork",
          &asiopal::Executor::Fork,
          "Create a new Executor that shares the underling std::shared_ptr<IO>.")

      .def_readonly(
          "strand",
          &asiopal::Executor::strand);
}

#endif // PYDNP3_ASIOPAL
#endif
