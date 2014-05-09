//
//  DDRemoteLog.h
//  DDRemoteLogger
//
//  Created by Ulhas Mandrawadkar on 5/8/14.
//  Copyright (c) 2014 Ulhas Mandrawadkar. All rights reserved.
//

#ifndef DDRemoteLogger_DDRemoteLog_h
#define DDRemoteLogger_DDRemoteLog_h

#import <CocoaLumberjack/DDLog.h>

//Define Custom Log Level

#define LOG_FLAG_REMOTE     (1 << 5)  // 0...100000

#define LOG_LEVEL_REMOTE    (LOG_FLAG_ERROR | LOG_FLAG_WARN | LOG_FLAG_INFO | LOG_FLAG_DEBUG | LOG_FLAG_VERBOSE | LOG_FLAG_REMOTE) //111111

#define LOG_REMOTE          (LOG_LEVEL_DEF & LOG_FLAG_REMOTE)

#define LOG_ASYNC_REMOTE    (YES && LOG_ASYNC_ENABLED)

#define DDLogRemote(frmt, ...) LOG_OBJC_MAYBE(LOG_ASYNC_REMOTE, LOG_LEVEL_DEF, LOG_FLAG_REMOTE, 0, frmt, ##__VA_ARGS__)

#define DDLogCRemote(frmt, ...) LOG_C_MAYBE(LOG_ASYNC_REMOTE, LOG_LEVEL_DEF, LOG_FLAG_REMOTE, 0, frmt, ##__VA_ARGS__)

#endif
