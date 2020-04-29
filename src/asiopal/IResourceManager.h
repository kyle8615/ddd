#ifndef PYDNP3_ASIOPAL_IRESOURCEMANAGER_H
#define PYDNP3_ASIOPAL_IRESOURCEMANAGER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/IResourceManager.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal {
/**
* Overriding virtual functions from interface class IResource.
*/
struct PyIResource : public IResource {
  public:
  /* Inherit the constructors */
  using IResource::IResource;

  /* Trampoline for IResource virtual functions */
  void Shutdown() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IResource,
        Shutdown, );
  }
};

/**
* Overriding virtual functions from interface class IResourceManager.
*/
struct PyIResourceManager : public IResourceManager {
  public:
  /* Inherit the constructors */
  using IResourceManager::IResourceManager;

  /* Trampoline for IResourceManager virtual functions */
  void Detach(const std::shared_ptr<IResource>& resource) override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IResourceManager,
        Detach,
        resource);
  }
};
}

void bind_IResourceManager(py::module& m)
{
  // ----- struct: asiopal::IResource -----
  py::class_<asiopal::IResource, asiopal::PyIResource, std::shared_ptr<asiopal::IResource>>(m, "IResource",
      "Anything that can be shutdown.")

      .def(py::init<>())

      .def(
          "Shutdown",
          &asiopal::IResource::Shutdown,
          py::call_guard<py::gil_scoped_release>());

  // ----- struct: asiopal::IResourceManager -----
  py::class_<asiopal::IResourceManager,
      asiopal::PyIResourceManager,
      std::shared_ptr<asiopal::IResourceManager>>(m, "IResourceManager")

      .def(py::init<>())

      .def(
          "Detach",
          &asiopal::IResourceManager::Detach,
          "Notify the handler that the resource is shutting down, and it doesn't have to track it anymore.");
}

#endif // PYDNP3_ASIOPAL
#endif
