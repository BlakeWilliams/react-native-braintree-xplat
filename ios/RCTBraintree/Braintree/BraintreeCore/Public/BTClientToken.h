#import <Foundation/Foundation.h>
#import "BTJSON.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const BTClientTokenKeyVersion;
extern NSString * const BTClientTokenErrorDomain;
extern NSString * const BTClientTokenKeyAuthorizationFingerprint;
extern NSString * const BTClientTokenKeyConfigURL;

typedef NS_ENUM(NSInteger, BTClientTokenError) {
    BTClientTokenErrorUnknown = 0,
    BTClientTokenErrorInvalid,
    BTClientTokenErrorUnsupportedVersion,
};

@interface BTClientToken : NSObject <NSCoding, NSCopying>

/// The client token as a BTJSON object
@property (nonatomic, readonly, strong) BTJSON *json;
/// The extracted authorization fingerprint
@property (nonatomic, readonly, copy) NSString *authorizationFingerprint;
/// The extracted configURL
@property (nonatomic, readonly, strong) NSURL *configURL;
/// The original string used to initialize this instance
@property (nonatomic, readonly, copy) NSString *originalValue;

#pragma mark - Initializers

//// Initialize a client token with a client token string generated by a Braintree Server Library.
- (nullable instancetype)initWithClientToken:(NSString *)clientToken error:(NSError **)error NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)init __attribute__((unavailable("Please use initWithClientToken:error: instead.")));

@end

NS_ASSUME_NONNULL_END
