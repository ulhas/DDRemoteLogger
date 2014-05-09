//
//  DDRemoteLogger.m
//  DDRemoteLogger
//
//  Created by Ulhas Mandrawadkar on 5/8/14.
//  Copyright (c) 2014 Ulhas Mandrawadkar. All rights reserved.
//

#import <CocoaAsyncSocket/GCDAsyncUdpSocket.h>

#import "DDRemoteLogger.h"

@interface DDRemoteLogger ()

@property (nonatomic, strong) GCDAsyncUdpSocket *udpSocket;

@property (nonatomic, copy, readwrite) NSString *host;
@property (nonatomic, assign, readwrite) uint16_t port;

@end

static DDRemoteLogger *sharedInstance = nil;
static NSString *loggerName = @"com.lumberjack.remotelogger";

@implementation DDRemoteLogger

+ (DDRemoteLogger *)sharedInstance
{
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		sharedInstance = [[DDRemoteLogger alloc] init];
	});
	
	return sharedInstance;
}

+ (DDRemoteLogger *)remoteLoggerWithUDPHost:(NSString *)host andPort:(uint16_t)port
{
    if (!host
        || port < 0)
    {
        return nil;
    }
    
    DDRemoteLogger *sharedInstance = [[self class] sharedInstance];
    
    sharedInstance.host = host;
    sharedInstance.port = port;
    
    return sharedInstance;
}

- (id)init
{
    self = [super init];
    if (self)
    {
        self.udpSocket = [[GCDAsyncUdpSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0)];
        self.port = -1;
    }
    
    return self;
}

- (void)setUDPHost:(NSString *)host andPort:(uint16_t)port
{
    self.host = host;
    self.port = port;
}

- (void)logMessage:(DDLogMessage *)logMessage
{
    NSString *logMsg = logMessage->logMsg;
    
    if (self->formatter)
        logMsg = [self->formatter formatLogMessage:logMessage];
    
    if (logMsg)
    {
        [self logMessageToRemoteLogger:[logMsg dataUsingEncoding:NSUTF8StringEncoding]];
    }
}

- (void)logMessageToRemoteLogger:(NSData *)logData
{
    if (self.host.length > 0)
    {
        [self.udpSocket sendData:logData toHost:self.host port:self.port withTimeout:-1 tag:0];
    }
}

- (NSString *)loggerName
{
    return loggerName;
}

@end
