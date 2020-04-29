#ifndef PYDNP3_ASIODNP3_ISESSIONACCEPTOR_H
#define PYDNP3_ASIODNP3_ISESSIONACCEPTOR_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiodnp3/ISessionAcceptor.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3 {
/**
* Overriding virtual functions from interface class ISessionAcceptor.
*/
class PyISessionAcceptor : public ISessionAcceptor {
  public:
  /* Inherit the constructors */
  using ISessionAcceptor::ISessionAcceptor;

  /* Trampoline for ISessionAcceptor virtual functions */
  std::shared_ptr<IMasterSession> AcceptSession(const std::string& sessionid,
      std::shared_ptr<opendnp3::ISOEHandler> SOEHandler,
      std::shared_ptr<opendnp3::IMasterApplication> application,
      const MasterStackConfig& config) override
  {
    PYBIND11_OVERLOAD_PURE(
        std::shared_ptr<IMasterSession>,
        ISessionAcceptor,
        AcceptSession,
        sessionid, SOEHandler, application, config);
  }
};
}

void bind_ISessionAcceptor(py::module& m)
{
  // ----- class: asiodnp3::ISessionAcceptor -----
  py::class_<asiodnp3::ISessionAcceptor, asiodnp3::PyISessionAcceptor>(m, "ISessionAcceptor",
      "Callback interface invoked when a new connection is accepted")

      .def(py::init<>())

      .def(
          "AcceptSession",
          &asiodnp3::ISessionAcceptor::AcceptSession,
          ":return: shared_ptr to asiodnp3.IMasterSession",
          py::arg("sessionid"), py::arg("SOEHandler"), py::arg("application"), py::arg("config"));
}

#endif // PYDNP3_ASIODNP3
#endif
