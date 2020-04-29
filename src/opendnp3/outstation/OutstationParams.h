#ifndef PYDNP3_OPENDNP3_OUTSTATION_OUTSTATIONPARAMS_H
#define PYDNP3_OPENDNP3_OUTSTATION_OUTSTATIONPARAMS_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <opendnp3/outstation/OutstationParams.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_OutstationParams(py::module& m)
{
  // ----- struct: opendnp3::OutstationParams -----
  py::class_<opendnp3::OutstationParams>(m, "OutstationParams",
      "Static configuration parameters for an outstation session.")

      .def(
          py::init<opendnp3::IndexMode, uint8_t, openpal::TimeDuration, openpal::TimeDuration, openpal::TimeDuration,
              openpal::TimeDuration, uint32_t, uint32_t, bool, opendnp3::StaticTypeBitField,
              opendnp3::ClassField>(),
          ":type maxControlsPerRequest: unsigned char \n"
          ":type maxTxFragSize: unsigned int \n"
          ":type maxRxFragSize: unsigned int",
          py::arg("indexMode") = opendnp3::IndexMode::Contiguous,
          py::arg("maxControlsPerRequest") = 16,
          py::arg("selectTimeout") = openpal::TimeDuration::Seconds(10),
          py::arg("solConfirmTimeout") = opendnp3::DEFAULT_APP_TIMEOUT,
          py::arg("unsolConfirmTimeout") = opendnp3::DEFAULT_APP_TIMEOUT,
          py::arg("unsolRetryTimeout") = opendnp3::DEFAULT_APP_TIMEOUT,
          py::arg("maxTxFragSize") = opendnp3::DEFAULT_MAX_APDU_SIZE,
          py::arg("maxRxFragSize") = opendnp3::DEFAULT_MAX_APDU_SIZE,
          py::arg("allowUnsolicited") = false,
          py::arg("typesAllowedInClass0") = opendnp3::StaticTypeBitField::AllTypes(),
          py::arg("unsolClassMask") = opendnp3::ClassField::None())

      .def_readwrite(
          "indexMode",
          &opendnp3::OutstationParams::indexMode,
          "Controls the index mode (defaults to contiguous).")

      .def_readwrite(
          "maxControlsPerRequest",
          &opendnp3::OutstationParams::maxControlsPerRequest,
          "   The maximum number of controls the outstation will attempt to process from a single APDU. \n"
          ":type maxControlsPerRequest: unsigned char")

      .def_readwrite(
          "selectTimeout",
          &opendnp3::OutstationParams::selectTimeout,
          "How long the outstation will allow an operate to proceed after a prior select.")

      .def_readwrite(
          "solConfirmTimeout",
          &opendnp3::OutstationParams::solConfirmTimeout,
          "Timeout for solicited confirms.")

      .def_readwrite(
          "unsolConfirmTimeout",
          &opendnp3::OutstationParams::unsolConfirmTimeout,
          "Timeout for unsolicited confirms.")

      .def_readwrite(
          "unsolRetryTimeout",
          &opendnp3::OutstationParams::unsolRetryTimeout,
          "Timeout for unsolicited retries.")

      .def_readwrite(
          "maxTxFragSize",
          &opendnp3::OutstationParams::maxTxFragSize,
          "   The maximum fragment size the outstation will use for fragments it sends. \n"
          ":type maxTxFragSize: unsigned int")

      .def_readwrite(
          "maxRxFragSize",
          &opendnp3::OutstationParams::maxRxFragSize,
          "   The maximum fragment size the outstation will be able to receive. \n"
          ":type maxRxFragSize: unsigned int")

      .def_readwrite(
          "allowUnsolicited",
          &opendnp3::OutstationParams::allowUnsolicited,
          "Global enabled/ disable for unsolicited messages. If false, the NULL unsolicited message is not even sent.")

      .def_readwrite(
          "typesAllowedInClass0",
          &opendnp3::OutstationParams::typesAllowedInClass0,
          "A bitmask type that specifies the types allowed in a class 0 reponse.")

      .def_readwrite(
          "unsolClassMask",
          &opendnp3::OutstationParams::unsolClassMask,
          "Class mask for unsolicted, default to 0 as unsolicited has to be enabled.")

      .def_readwrite(
          "respondToAnyMaster",
          &opendnp3::OutstationParams::respondToAnyMaster,
          "If true, the outstation processes responds to any request/confirmation as if it came from the expected master address.");
}

#endif // PYDNP3_OPENDNP3
#endif
