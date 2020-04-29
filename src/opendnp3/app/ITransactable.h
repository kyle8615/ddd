#ifndef PYDNP3_OPENDNP3_APP_ITRANSACTABLE_H
#define PYDNP3_OPENDNP3_APP_ITRANSACTABLE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/app/ITransactable.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class ITransactable.
*/
class PyITransactable : public ITransactable {
  public:
  /* Trampoline for ITransactable virtual functions */
  void Start() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ITransactable,
        Start, );
  }
  void End() override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ITransactable,
        End, )
  }
};

class PubITransactable : public ITransactable {
  public:
  /* Make ITransactable protected member functions public */
  using ITransactable::End;
  using ITransactable::Start;
};
}

void bind_ITransactable(py::module& m)
{
  // ----- class: opendnp3::ITransactable -----
  py::class_<opendnp3::ITransactable,
      opendnp3::PyITransactable,
      std::shared_ptr<opendnp3::ITransactable>>(m, "ITransactable",
      "Something that can be performed atomically or needing Start()/End() signals.")

      .def(py::init<>())

      .def(
          "Start",
          &opendnp3::PubITransactable::Start)

      .def(
          "End",
          &opendnp3::PubITransactable::End);

  // ----- class: opendnp3::Transaction -----
  py::class_<opendnp3::Transaction, std::shared_ptr<opendnp3::Transaction>>(m, "Transaction",
      "Uses RAII to safely perform a transaction.")

      .def(
          py::init<opendnp3::ITransactable&>(),
          py::arg("transactable"))

      .def(
          py::init<opendnp3::ITransactable*>(),
          py::arg("pTransactable"))

      .def_static(
          "Start",
          &opendnp3::Transaction::Start,
          py::arg("pTransactable"))

      .def_static(
          "End",
          &opendnp3::Transaction::End,
          py::arg("pTransactable"))

      .def_static(
          "Apply",
          &opendnp3::Transaction::Apply<void, opendnp3::ITransactable&, std::function<void(const opendnp3::Transaction&)>>,
          py::arg("transactable"), py::arg("fun"));
}

#endif // PYDNP3_OPENDNP3
#endif
