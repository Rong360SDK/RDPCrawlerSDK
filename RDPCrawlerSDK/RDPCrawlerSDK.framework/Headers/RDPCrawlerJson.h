//
//  RDPCrawlerJson.h
//  Pods
//
//  Created by whj on 16/10/21.
//
//

#import <Foundation/Foundation.h>

@interface NSArray (RDPCrawler_JSONString)

/// Returns a autorelease string containing the receiver encoded in JSON.
- (NSString *)rdpc_JSONRepresentation;

- (NSData *)rdpc_jsonData;

@end


/// Adds JSON generation to NSDictionary
@interface NSDictionary (RDPCrawler_JSONString)

/// Returns a autorelease string containing the receiver encoded in JSON.
- (NSString *)rdpc_JSONRepresentation;

- (NSData *)rdpc_jsonData;

@end


/// Adds JSON parsing methods to NSString
@interface NSString (RDPCrawler_JSONObject)

/// Returns the autorelease NSDictionary or NSArray represented by the receiver's JSON representation, or nil on error
- (id)rdpc_JSONValue;

@end


/// Adds JSON parsing methods to NSData
@interface NSData (RDPCrawler_JSONObject)

/// Returns the autorelease NSDictionary or NSArray represented by the receiver's JSON representation, or nil on error
- (id)rdpc_JSONValue;

@end
