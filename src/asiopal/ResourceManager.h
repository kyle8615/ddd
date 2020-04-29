#ifndef PYDNP3_ASIOPAL_RESOURCEMANAGER_H
#define PYDNP3_ASIOPAL_RESOURCEMANAGER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/IChannel.h>
#include <asiopal/ResourceManager.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_ResourceManager(py::module& m)
{
  // ----- class: asiopal::ResourceManager -----
  py::class_<asiopal::ResourceManager,
      asiopal::IResourceManager,
      std::shared_ptr<asiopal::ResourceManager>>(m, "ResourceManager")

      .def(py::init<>())

      .def_static(
          "Create",
          &asiopal::ResourceManager::Create)

      .def(
          "Detach",
          &asiopal::ResourceManager::Detach)

      .def(
          "Shutdown",
          &asiopal::ResourceManager::Shutdown)

      .def(
          "Bind",
          [](asiopal::ResourceManager& self, std::function<std::shared_ptr<asiodnp3::IChannel>()> create) {
            return self.Bind<asiodnp3::IChannel>(create);
          })

      .def(
          "Bind",
          [](asiopal::ResourceManager& self, std::function<std::shared_ptr<asiopal::IListener>()> create) {
            return self.Bind<asiopal::IListener>(create);
          });
}

#endif // PYDNP3_ASIOPAL
#endif
