//
//  FCSchemedConfiguration.h
//  Demo
//
//  Created by Almer Lucke on 07/02/14.
//  Copyright (c) 2014 Almer Lucke. All rights reserved.
//


#import <Foundation/Foundation.h>

// Shortcut to set the configuration type based on FCSCHEMEDCONFIGURATION preprocessor macro.
// This only works if the FCSCHEMEDCONFIGURATION preprocessor macro is actually added to the build configuration,
// otherwise this will raise a compiler error stating that FCSCHEMEDCONFIGURATION is unknown
#define FCSCHEMEDCONFIGURATION_INIT() [FCSchemedConfiguration setConfigurationType:FCSCHEMEDCONFIGURATION]


/**
 *  Configuration types, set the FCSCHEMEDCONFIGURATION preprocessor macro to one
 *  of these values
 */
typedef NS_ENUM(NSInteger, FCSchemedConfigurationType)
{
    /**
     *  The fallback configuration (key "default")
     */
    FCSchemedConfigurationTypeDefault = 0,
    /**
     *  Debug configuration (key "debug")
     */
    FCSchemedConfigurationTypeDebug = 1,
    /**
     *  Release configuration (key "release")
     */
    FCSchemedConfigurationTypeRelease = 2,
    /**
     *  AdHoc configuration (key "adhoc")
     */
    FCSchemedConfigurationTypeAdHoc = 3,
    /**
     *  Acceptance configuration (key "accept")
     */
    FCSchemedConfigurationTypeAcceptance = 4,
    /**
     *  Store configuration (key "store")
     */
    FCSchemedConfigurationTypeAppStore = 5
};


/**
 *  Interface to set the configuration type and get an object from the configation file
 *  by key
 */
@interface FCSchemedConfiguration : NSObject

/**
 *  Set the configuration type used
 *
 *  @param configurationType FCSchemedConfigurationType
 */
+ (void)setConfigurationType:(FCSchemedConfigurationType)configurationType;

/**
 *  Get an object from the configuration file by key
 *
 *  @param key The key
 *
 *  @return An object if the key is found, else nil
 */
+ (id)objectForKey:(NSString *)key;


@end
