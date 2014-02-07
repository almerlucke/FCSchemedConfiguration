//
//  FCSchemedConfiguration.m
//  Demo
//
//  Created by Almer Lucke on 07/02/14.
//  Copyright (c) 2014 Almer Lucke. All rights reserved.
//


#import "FCSchemedConfiguration.h"


@interface FCSchemedConfiguration ()
{
    NSDictionary *_configurationDictionary;
    NSString *_configurationSchemeKey;
    FCSchemedConfigurationType _configurationType;
}

@end


@implementation FCSchemedConfiguration

#pragma mark - Initialize

+ (FCSchemedConfiguration *)sharedInstance
{
    static FCSchemedConfiguration *_singleton = nil;
    static dispatch_once_t _once;
    
    dispatch_once(&_once, ^{
        _singleton = [[FCSchemedConfiguration alloc] init];
    });
    
    return _singleton;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        NSString *resourceName = @"FCSchemedConfiguration";
        NSString *resourceType = @"plist";
        NSString *configurationFilePath = [[NSBundle mainBundle] pathForResource:resourceName
                                                                          ofType:resourceType];
        
        // read FCSchemedConfiguration plist into dictionary
        _configurationDictionary = [NSDictionary dictionaryWithContentsOfFile:configurationFilePath];
        
        // initial configuration is default configuration
        _configurationType = FCSchemedConfigurationTypeDefault;
        _configurationSchemeKey = [self configurationSchemeKeyForType:_configurationType];
    }
    
    return self;
}


#pragma mark - Configurations

- (NSString *)configurationSchemeKeyForType:(FCSchemedConfigurationType)configurationType
{
    NSString *key = @"default";
    
    switch (configurationType) {
        case FCSchemedConfigurationTypeDebug:
            key = @"debug";
            break;
        case FCSchemedConfigurationTypeRelease:
            key = @"release";
            break;
        case FCSchemedConfigurationTypeAdHoc:
            key = @"adhoc";
            break;
        case FCSchemedConfigurationTypeAcceptance:
            key = @"accept";
            break;
        case FCSchemedConfigurationTypeAppStore:
            key = @"store";
            break;
        default:
            break;
    }
    
    return key;
}

- (void)setConfigurationType:(FCSchemedConfigurationType)configurationType
{
    _configurationType = configurationType;
    _configurationSchemeKey = [self configurationSchemeKeyForType:configurationType];
}

+ (void)setConfigurationType:(FCSchemedConfigurationType)configurationType
{
    [[self sharedInstance] setConfigurationType:configurationType];
}


#pragma mark - ObjectForKey

- (id)objectForKey:(NSString *)key
{
    // get scheme dictionary for key
    NSDictionary *valueDictionary = [_configurationDictionary objectForKey:key];
    
    // get value for selected scheme
    id value = [valueDictionary objectForKey:_configurationSchemeKey];
    
    if (!value) {
        // fallback to default scheme key and value
        NSString *schemeKey = [self configurationSchemeKeyForType:FCSchemedConfigurationTypeDefault];
        value = [valueDictionary objectForKey:schemeKey];
    }
    
    return value;
}

+ (id)objectForKey:(NSString *)key
{
    return [[self sharedInstance] objectForKey:key];
}

@end
