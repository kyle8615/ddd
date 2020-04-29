#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>

#include <pybind11/pybind11.h>

#include "asiodnp3/AllHeaders.h"

namespace py = pybind11;

void init_asiodnp3(py::module &asiodnp3)
{
    // -------------------- PYDNP3.OPENDNP3 --------------------
    bind_ConsoleLogger(asiodnp3);
    bind_IStack(asiodnp3);                      // GIL release: enable, disable
    bind_IMasterScan(asiodnp3);
    bind_IMasterOperations(asiodnp3);
    bind_IMaster(asiodnp3);
    bind_Updates(asiodnp3);
    bind_IOutstation(asiodnp3);
    bind_MasterStackConfig(asiodnp3);
    bind_DatabaseConfig(asiodnp3);
    bind_OutstationStackConfig(asiodnp3);
    bind_IChannel(asiodnp3);                    // GIL release: AddMaster, AddOutstation
    bind_IChannelListener(asiodnp3);
    bind_IMasterSession(asiodnp3);
    bind_ISessionAcceptor(asiodnp3);
    bind_X509Info(asiodnp3);
    bind_IListenCallbacks(asiodnp3);
    bind_DNP3Manager(asiodnp3);                 // GIL release: AddTCPClient, AddTCPServer, Shutdown
    bind_PrintingSOEHandler(asiodnp3);
    bind_DefaultMasterApplication(asiodnp3);
    bind_DefaultListenCallbacks(asiodnp3);
    bind_ErrorCodes(asiodnp3);                  //@todo: referenced unknown base type "std::error_category"
    bind_MasterTCPServer(asiodnp3);
    bind_PrintingChannelListener(asiodnp3);
    bind_PrintingCommandCallback(asiodnp3);
    bind_UpdateBuilder(asiodnp3);
}
