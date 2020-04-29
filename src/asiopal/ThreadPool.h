#ifndef PYDNP3_ASIOPAL_THREADPOOL_H
#define PYDNP3_ASIOPAL_THREADPOOL_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/ThreadPool.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_ThreadPool(py::module& m)
{
  // ----- class: asiopal::ThreadPool -----
  py::class_<asiopal::ThreadPool, std::shared_ptr<asiopal::ThreadPool>>(m, "ThreadPool",
      "A thread pool that calls asio::io_service::run.")

      .def(
          py::init<const openpal::Logger&,
              const std::shared_ptr<asiopal::IO>&,
              uint32_t>(),
          py::arg("logger"), py::arg("io"), py::arg("concurrency"))

      .def(
          py::init<const openpal::Logger&,
              const std::shared_ptr<asiopal::IO>&,
              uint32_t,
              std::function<void()>>(),
          py::arg("logger"), py::arg("io"), py::arg("concurrency"), py::arg("onThreadStart"))

      .def(
          py::init<const openpal::Logger&,
              const std::shared_ptr<asiopal::IO>&,
              uint32_t,
              std::function<void()>,
              std::function<void()>>(),
          py::arg("logger"), py::arg("io"), py::arg("concurrency"), py::arg("onThreadStart"), py::arg("onThreadExit"))

      .def(
          "CreateExecutor",
          &asiopal::ThreadPool::CreateExecutor)

      .def(
          "Shutdown",
          &asiopal::ThreadPool::Shutdown);
}

#endif // PYDNP3_ASIOPAL
#endif
