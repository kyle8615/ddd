#ifndef PYDNP3_OPENDNP3_GEN_MASTERTASKTYPE_H
#define PYDNP3_OPENDNP3_GEN_MASTERTASKTYPE_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/gen/MasterTaskType.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

void bind_MasterTaskType(py::module& m)
{
  // ----- enum class: opendnp3::MasterTaskType -----
  py::enum_<opendnp3::MasterTaskType>(m, "MasterTaskType",
      "Enumeration of internal tasks.")

      .value("CLEAR_RESTART", opendnp3::MasterTaskType::CLEAR_RESTART)
      .value("DISABLE_UNSOLICITED", opendnp3::MasterTaskType::DISABLE_UNSOLICITED)
      .value("ASSIGN_CLASS", opendnp3::MasterTaskType::ASSIGN_CLASS)
      .value("STARTUP_INTEGRITY_POLL", opendnp3::MasterTaskType::STARTUP_INTEGRITY_POLL)
      .value("NON_LAN_TIME_SYNC", opendnp3::MasterTaskType::NON_LAN_TIME_SYNC)
      .value("LAN_TIME_SYNC", opendnp3::MasterTaskType::LAN_TIME_SYNC)
      .value("ENABLE_UNSOLICITED", opendnp3::MasterTaskType::ENABLE_UNSOLICITED)
      .value("AUTO_EVENT_SCAN", opendnp3::MasterTaskType::AUTO_EVENT_SCAN)
      .value("USER_TASK", opendnp3::MasterTaskType::USER_TASK);

  // ----- func: opendnp3::MasterTaskTypeToString -----
  m.def(
      "MasterTaskTypeToString",
      &opendnp3::MasterTaskTypeToString);
}

#endif // PYDNP3_OPENDNP3
#endif
