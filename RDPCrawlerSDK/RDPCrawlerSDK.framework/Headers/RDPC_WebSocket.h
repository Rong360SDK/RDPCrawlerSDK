//
//   Copyright 2012 Square Inc.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#import <Foundation/Foundation.h>
#import <Security/SecCertificate.h>

typedef NS_ENUM(NSInteger, RDPCReadyState) {
    RDPC_CONNECTING   = 0,
    RDPC_OPEN         = 1,
    RDPC_CLOSING      = 2,
    RDPC_CLOSED       = 3,
};

typedef enum RDPCStatusCode : NSInteger {
    // 0–999: Reserved and not used.
    RDPCStatusCodeNormal = 1000,
    RDPCStatusCodeGoingAway = 1001,
    RDPCStatusCodeProtocolError = 1002,
    RDPCStatusCodeUnhandledType = 1003,
    // 1004 reserved.
    RDPCStatusNoStatusReceived = 1005,
    RDPCStatusCodeAbnormal = 1006,
    RDPCStatusCodeInvalidUTF8 = 1007,
    RDPCStatusCodePolicyViolated = 1008,
    RDPCStatusCodeMessageTooBig = 1009,
    RDPCStatusCodeMissingExtension = 1010,
    RDPCStatusCodeInternalError = 1011,
    RDPCStatusCodeServiceRestart = 1012,
    RDPCStatusCodeTryAgainLater = 1013,
    // 1014: Reserved for future use by the WebSocket standard.
    RDPCStatusCodeTLSHandshake = 1015,
    // 1016–1999: Reserved for future use by the WebSocket standard.
    // 2000–2999: Reserved for use by WebSocket extensions.
    // 3000–3999: Available for use by libraries and frameworks. May not be used by applications. Available for registration at the IANA via first-come, first-serve.
    // 4000–4999: Available for use by applications.
} RDPCStatusCode;

@class RDPC_WebSocket;

extern NSString *const RDPCWebSocketErrorDomain;
extern NSString *const RDPCHTTPResponseErrorKey;

#pragma mark - RDPCWebSocketDelegate

@protocol RDPCWebSocketDelegate;

#pragma mark - RDPCWebSocket

@interface RDPC_WebSocket : NSObject <NSStreamDelegate>

@property (nonatomic, weak) id <RDPCWebSocketDelegate> delegate;


@property (nonatomic, readonly) RDPCReadyState readyState;
@property (nonatomic, readonly, retain) NSURL *url;


@property (nonatomic, readonly) CFHTTPMessageRef receivedHTTPHeaders;

// Optional array of cookies (NSHTTPCookie objects) to apply to the connections
@property (nonatomic, readwrite) NSArray * requestCookies;

// This returns the negotiated protocol.
// It will be nil until after the handshake completes.
@property (nonatomic, readonly, copy) NSString *protocol;

// Protocols should be an array of strings that turn into Sec-WebSocket-Protocol.
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols;
- (id)initWithURLRequest:(NSURLRequest *)request;

// Some helper constructors.
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols;
- (id)initWithURL:(NSURL *)url;

// Delegate queue will be dispatch_main_queue by default.
// You cannot set both OperationQueue and dispatch_queue.
- (void)setDelegateOperationQueue:(NSOperationQueue*) queue;
- (void)setDelegateDispatchQueue:(dispatch_queue_t) queue;

// By default, it will schedule itself on +[NSRunLoop SR_networkRunLoop] using defaultModes.
- (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;
- (void)unscheduleFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;

// SRWebSockets are intended for one-time-use only.  Open should be called once and only once.
- (void)open;

- (void)close;
- (void)closeWithCode:(NSInteger)code reason:(NSString *)reason;

// Send a UTF8 String or Data.
- (void)send:(id)data;

// Send Data (can be nil) in a ping message.
- (void)sendPing:(NSData *)data;

@end

#pragma mark - SRWebSocketDelegate

@protocol RDPCWebSocketDelegate <NSObject>

// message will either be an NSString if the server is using text
// or NSData if the server is using binary.
- (void)webSocket:(RDPC_WebSocket *)webSocket didReceiveMessage:(id)message;

@optional

- (void)webSocketDidOpen:(RDPC_WebSocket *)webSocket;
- (void)webSocket:(RDPC_WebSocket *)webSocket didFailWithError:(NSError *)error;
- (void)webSocket:(RDPC_WebSocket *)webSocket didCloseWithCode:(NSInteger)code reason:(NSString *)reason wasClean:(BOOL)wasClean;
- (void)webSocket:(RDPC_WebSocket *)webSocket didReceivePong:(NSData *)pongPayload;

// Return YES to convert messages sent as Text to an NSString. Return NO to skip NSData -> NSString conversion for Text messages. Defaults to YES.
- (BOOL)webSocketShouldConvertTextFrameToString:(RDPC_WebSocket *)webSocket;

@end

#pragma mark - NSURLRequest (RDPCCertificateAdditions)

@interface NSURLRequest (RDPCCertificateAdditions)

@property (nonatomic, retain, readonly) NSArray *RDPC_SSLPinnedCertificates;

@end

#pragma mark - NSMutableURLRequest (RDPCCertificateAdditions)

@interface NSMutableURLRequest (RDPCCertificateAdditions)

@property (nonatomic, retain) NSArray *RDPC_SSLPinnedCertificates;

@end

#pragma mark - NSRunLoop (RDPCWebSocket)

@interface NSRunLoop (RDPCWebSocket)

+ (NSRunLoop *)RDPC_networkRunLoop;

@end
