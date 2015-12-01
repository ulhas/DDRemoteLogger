//
//  DDRemoteLogger.h
//  DDRemoteLogger
//
//  Created by Ulhas Mandrawadkar on 5/8/14.
//  Copyright (c) 2014 Ulhas Mandrawadkar. All rights reserved.
//

#import <CocoaLumberjack/CocoaLumberjack.h>

@interface DDRemoteLogger : DDAbstractLogger <DDLogger>

@property (nonatomic, copy, readonly) NSString *host;
@property (nonatomic, assign, readonly) uint16_t port;

+ (DDRemoteLogger *)sharedInstance;
+ (DDRemoteLogger *)remoteLoggerWithUDPHost:(NSString *)host andPort:(uint16_t)port;

- (void)setUDPHost:(NSString *)host andPort:(uint16_t)port;

@end
