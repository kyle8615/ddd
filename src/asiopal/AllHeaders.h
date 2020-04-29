#ifndef PYDNP3_ASIOPAL_ALLHEADERS_H
#define PYDNP3_ASIOPAL_ALLHEADERS_H

// For this compilation unit, include the header file
// related to asiopal
#define PYDNP3_ASIOPAL

// ---------- ASIOPAL HEADERS ----------
#include "ASIOSerialHelpers.h"
#include "ChannelRetry.h"
#include "Executor.h"
#include "IAsyncChannel.h"
#include "IChannelCallbacks.h"
#include "IListener.h"
#include "IO.h"
#include "IOpenDelayStrategy.h"
#include "IPEndpoint.h"
#include "IResourceManager.h"
#include "LoggingConnectionCondition.h"
#include "ResourceManager.h"
#include "SerialChannel.h"
#include "SerialTypes.h"
#include "SocketChannel.h"
#include "SocketHelpers.h"
#include "SteadyClock.h"
#include "Synchronized.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "TLSConfig.h"
#include "ThreadPool.h"
#include "TimeConversions.h"
#include "Timer.h"
#include "UTCTimeSource.h"

#endif
