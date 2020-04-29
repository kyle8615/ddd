#ifndef PYDNP3_ASIOPAL_ILISTENER_H
#define PYDNP3_ASIOPAL_ILISTENER_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/IListener.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal {
/**
* Overriding virtual functions from interface class IListener.
*/
class PyIListener : public IListener {
  public:
  /* Inherit the constructors */
  using IListener::IListener;

  /* Trampoline for IResource virtual functions */
  void Shutdown() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        IResource,
        Shutdown, );
  }
};
}

void bind_IListener(py::module& m)
{
  // ----- class: asiopal::IListener -----
  py::class_<asiopal::IListener,
      asiopal::PyIListener,
      asiopal::IResource,
      std::shared_ptr<asiopal::IListener>>(m, "IListener",
      "Represents a running TCP or TLS listener that can be shutdown so that no new connections are accepted.")

      .def(py::init<>());
}

#endif // PYDNP3_ASIOPAL
#endif
