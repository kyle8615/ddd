#ifndef PYDNP3_OPENPAL_ALLHEADERS_H
#define PYDNP3_OPENPAL_ALLHEADERS_H

#define PYDNP3_OPENPAL

namespace openpal {
class UInt48Type;
}

namespace opendnp3 {
typedef openpal::UInt48Type DNPTime;
}

// ---------- OPENPAL HEADERS ----------
//#include "channel/IPhysicalLayer.h"                   //missing "ChannelStatistics.h" file
#include "Configure.h"
#include "channel/IPhysicalLayerCallbacks.h"
#include "container/Array.h"
#include "container/ArrayView.h"
#include "container/Buffer.h"
#include "container/HasSize.h"
#include "container/Pair.h"
#include "container/RSlice.h"
#include "container/Settable.h"
#include "container/StaticBuffer.h"
#include "container/WSlice.h"
#include "executor/IExecutor.h"
#include "executor/IMonotonicTimeSource.h"
#include "executor/ITimer.h"
#include "executor/IUTCTimeSource.h"
#include "executor/MonotonicTimestamp.h"
#include "executor/TimeDuration.h"
#include "executor/TimerRef.h"
#include "executor/UTCTimestamp.h"
#include "logging/ILogHandler.h"
#include "logging/LogEntry.h"
#include "logging/LogFilters.h"
#include "logging/LogLevels.h"
#include "logging/Logger.h"
#include "logging/StringFormatting.h"
#include "serialization/DoubleFloat.h"
#include "serialization/FloatByteOrder.h"
#include "serialization/Format.h"
#include "serialization/Parse.h"
#include "serialization/Serialization.h"
#include "serialization/SerializationTemplatesLE.h"
#include "serialization/Serializer.h"
#include "serialization/SingleFloat.h"
#include "util/Comparisons.h"
#include "util/Finally.h"
#include "util/Limits.h"
#include "util/SequenceNum.h"
#include "util/ToHex.h"
#include "util/Uncopyable.h"

#endif
