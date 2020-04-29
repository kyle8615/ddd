#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>

#include <pybind11/pybind11.h>

#include "asiopal/AllHeaders.h"

namespace py = pybind11;

void init_asiopal(py::module &asiopal)
{
    // -------------------- PYDNP3.ASIOPAL --------------------
    bind_SerialTypes(asiopal);
    bind_ASIOSerialHelpers(asiopal);
    bind_IOpenDelayStrategy(asiopal);
    bind_ChannelRetry(asiopal);
    bind_IO(asiopal);
    bind_SteadyClock(asiopal);
    bind_Executor(asiopal);
    bind_IChannelCallbacks(asiopal);
    bind_IAsyncChannel(asiopal);
    bind_IResourceManager(asiopal);             // GIL release: Shutdown
    bind_IListener(asiopal);
    bind_IPEndpoint(asiopal);
    bind_LoggingConnectionCondition(asiopal);
    bind_ResourceManager(asiopal);
    bind_SerialChannel(asiopal);
    bind_SocketChannel(asiopal);                //@todo: init, Create (error: call to implicitly-deleted copy constructor)
    bind_SocketHelpers(asiopal);
    bind_Synchronized(asiopal);
    bind_TCPClient(asiopal);
    bind_TCPServer(asiopal);
    bind_TLSConfig(asiopal);
    bind_ThreadPool(asiopal);
    bind_TimeConversions(asiopal);
    bind_Timer(asiopal);
    bind_UTCTimeSource(asiopal);
}
