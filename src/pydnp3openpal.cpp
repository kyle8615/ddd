#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>

#include <pybind11/pybind11.h>

#include "openpal/AllHeaders.h"

namespace py = pybind11;

void init_openpal(py::module& openpal)
{
  // -------------------- PYDNP3.OPENPAL --------------------
  bind_Configure(openpal);
  bind_Comparisons(openpal);
  bind_Uncopyable(openpal);
  bind_Finally(openpal);
  bind_Limits(openpal);
  bind_SequenceNum(openpal);
  bind_ToHex(openpal);
  bind_HasSize(openpal);
  bind_ArrayView(openpal);
  bind_Array(openpal);
  bind_RSlice(openpal);
  bind_WSlice(openpal);
  bind_Buffer(openpal);
  bind_Pair(openpal);
  bind_Settable(openpal);
  bind_StaticBuffer(openpal);
  //bind_IPhysicalLayer(openpal);             //@todo: can't include "ChannelStatistics.h"
  bind_IPhysicalLayerCallbacks(openpal);
  bind_TimeDuration(openpal);
  bind_MonotonicTimestamp(openpal);
  bind_ITimer(openpal);
  bind_IMonotonicTimeSource(openpal);
  bind_IExecutor(openpal);
  bind_UTCTimestamp(openpal);
  bind_IUTCTimeSource(openpal);
  bind_TimerRef(openpal);
  bind_LogFilters(openpal);
  bind_LogEntry(openpal);
  bind_ILogHandler(openpal);
  bind_OpenpalLogLevels(openpal);
  bind_Logger(openpal);
  bind_StringFormatting(openpal);
  bind_DoubleFloat(openpal);
  bind_FloatByteOrder(openpal);
  bind_Format(openpal);
  bind_Parse(openpal);
  bind_SerializationTemplatesLE(openpal); //already defined: Int16, UInt16, Int32, UInt32 (bind_Serialization)
  bind_SingleFloat(openpal);
  bind_Serialization(openpal);
  bind_Serializer(openpal);
}
