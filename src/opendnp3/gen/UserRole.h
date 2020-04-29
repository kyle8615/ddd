#ifndef PYDNP3_OPENDNP3_GEN_USERROLE_H
#define PYDNP3_OPENDNP3_GEN_USERROLE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/UserRole.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_UserRole(py::module& m)
{
  // ----- enum class: opendnp3::UserRole -----
  py::enum_<opendnp3::UserRole>(m, "UserRole",
      "Enumerates pre-defined rules in secure authentication.")

      .value("VIEWER", opendnp3::UserRole::VIEWER)
      .value("OPERATOR", opendnp3::UserRole::OPERATOR)
      .value("ENGINEER", opendnp3::UserRole::ENGINEER)
      .value("INSTALLER", opendnp3::UserRole::INSTALLER)
      .value("SECADM", opendnp3::UserRole::SECADM)
      .value("SECAUD", opendnp3::UserRole::SECAUD)
      .value("RBACMNT", opendnp3::UserRole::RBACMNT)
      .value("SINGLE_USER", opendnp3::UserRole::SINGLE_USER)
      .value("UNDEFINED", opendnp3::UserRole::UNDEFINED);

  // ----- func: opendnp3::UserRoleToType -----
  m.def(
      "UserRoleToType",
      &opendnp3::UserRoleToType,
      py::arg("userRole"));

  // ----- func: opendnp3::UserRoleFromType -----
  m.def(
      "UserRoleFromType",
      &opendnp3::UserRoleFromType,
      ":type rawType: unsigned short",
      py::arg("rawType"));

  // ----- func: opendnp3::UserRoleToString -----
  m.def(
      "UserRoleToString",
      &opendnp3::UserRoleToString,
      py::arg("userRole"));
}

#endif // PYDNP3_OPENDNP3
#endif
