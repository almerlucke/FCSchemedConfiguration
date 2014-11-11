//
//  FCSchemedConfiguration.h
//  Demo
//
//  Created by Almer Lucke on 07/02/14.
//  Copyright (c) 2014 Almer Lucke. All rights reserved.
//


#import <Foundation/Foundation.h>

// Shortcut to set the configuration based on FCSCHEMEDCONFIGURATION preprocessor macro.
// This only works if the FCSCHEMEDCONFIGURATION preprocessor macro is actually added to the build configuration,
// otherwise this will raise a compiler error stating that FCSCHEMEDCONFIGURATION is unknown
#define FCSCHEMEDCONFIGURATION_INIT() [FCSchemedConfiguration setConfigurationScheme:FCSCHEMEDCONFIGURATION]


/**
 *  Interface to set the configuration type and get an object from the configation file
 *  by key
 */
@interface FCSchemedConfiguration : NSObject

/**
 *  Set the configuration scheme used
 *
 *  @param configurationScheme NSString
 */
+ (void)setConfigurationScheme:(NSString *)configurationScheme;

/**
 *  Get an object from the configuration file by key
 *
 *  @param key The key
 *
 *  @return An object if the key is found, else nil
 */
+ (id)objectForKey:(NSString *)key;


@end
