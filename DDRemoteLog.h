//
//  DDRemoteLog.h
//  DDRemoteLogger
//
//  Created by Ulhas Mandrawadkar on 5/8/14.
//  Copyright (c) 2014 Ulhas Mandrawadkar. All rights reserved.
//

#ifndef DDRemoteLogger_DDRemoteLog_h
#define DDRemoteLogger_DDRemoteLog_h

#import <CocoaLumberjack/CocoaLumberjack.h>

//Define Custom Log Level

#define LOG_FLAG_REMOTE     (1 << 6)  // 0...1000000

#define LOG_LEVEL_REMOTE    (LOG_FLAG_REMOTE | LOG_LEVEL_DEBUG)

#define LOG_REMOTE          (ddLogLevel & LOG_FLAG_REMOTE)

#define DDLogRemote(frmt, ...)   ASYNC_LOG_OBJC_MAYBE(ddLogLevel, LOG_FLAG_REMOTE,  0, frmt, ##__VA_ARGS__)

#define DDLogRemote(frmt, ...)  ASYNC_LOG_C_MAYBE(ddLogLevel, LOG_FLAG_REMOTE,  0, frmt, ##__VA_ARGS__)

#endif
