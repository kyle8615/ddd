#ifndef PYDNP3_OPENDNP3_MASTER_ICOMMANDTASKRESULT_H
#define PYDNP3_OPENDNP3_MASTER_ICOMMANDTASKRESULT_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/master/ICommandTaskResult.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class ICommandTaskResult.
*/
class PyICommandTaskResult : public ICommandTaskResult {
  public:
  /* Inherit the constructors */
  using ICommandTaskResult::ICommandTaskResult;

  /* Trampoline for ICollection virtual functions */
  size_t Count() const override
  {
    PYBIND11_OVERLOAD_PURE(
        size_t,
        ICommandTaskResult,
        Count, );
  }
  void Foreach(IVisitor<opendnp3::CommandPointResult>& visitor) const override
  {
    PYBIND11_OVERLOAD_PURE(
        void,
        ICommandTaskResult,
        Foreach,
        visitor);
  }
};
}

void bind_ICommandTaskResult(py::module& m)
{
  // ----- class: opendnp3::ICommandTaskResult -----
  py::class_<opendnp3::ICommandTaskResult,
      opendnp3::PyICommandTaskResult,
      opendnp3::ICollection<opendnp3::CommandPointResult>>(m, "ICommandTaskResult",
      "Abstract result type returned via callback to a command operation. \n"
      "Provides the TaskCompleton summary value and access to a collection of flatten results. \n"
      "A result value is provided for every object in every header specified in the CommandSet used "
      "to start the operation.")

      .def(
          py::init<opendnp3::TaskCompletion>(),
          py::arg("summary"))

      .def_readwrite(
          "summary",
          &opendnp3::ICommandTaskResult::summary,
          "A summary result for the entire task.");
}

#endif // PYDNP3_OPENDNP3
#endif
