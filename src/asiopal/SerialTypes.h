#ifndef PYDNP3_ASIOPAL_SERIALTYPES_H
#define PYDNP3_ASIOPAL_SERIALTYPES_H

#include <Python.h>
#include <pybind11/pybind11.h>

#include <asiopal/SerialTypes.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_SerialTypes(py::module& m)
{
  // ----- class: asiopal::SerialSettings -----
  py::class_<asiopal::SerialSettings>(m, "SerialSettings",
      "Settings structure for the serial port.")

      .def(
          py::init<>(),
          "Defaults to the familiar 9600 8/N/1, no flow control.")

      .def_readwrite(
          "deviceName",
          &asiopal::SerialSettings::deviceName,
          "name of the port, i.e. COM1 or /dev/tty0.")

      .def_readwrite(
          "baud",
          &asiopal::SerialSettings::baud,
          "Baud rate of the port, i.e. 9600 or 57600.")

      .def_readwrite(
          "dataBits",
          &asiopal::SerialSettings::dataBits,
          "Data bits, usually 8.")

      .def_readwrite(
          "stopBits",
          &asiopal::SerialSettings::stopBits,
          "Stop bits, usually set to 1.")

      .def_readwrite(
          "parity",
          &asiopal::SerialSettings::parity,
          "Parity setting for the port, usually PAR_NONE.")

      .def_readwrite(
          "flowType",
          &asiopal::SerialSettings::flowType,
          "Flow control setting, usually FLOW_NONE.")

      .def_readwrite(
          "asyncOpenDelay",
          &asiopal::SerialSettings::asyncOpenDelay,
          "Some physical layers need time to settle so that the first tx isn't lost.");
}

#endif // PYDNP3_ASIOPAL
#endif
