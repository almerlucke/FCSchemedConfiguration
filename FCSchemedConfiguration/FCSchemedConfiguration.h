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


typedef NS_ENUM(NSInteger, FCSchemedConfigurationType)
{
    FCSchemedConfigurationTypeDefault = 0,
    FCSchemedConfigurationTypeDebug = 1,
    FCSchemedConfigurationTypeRelease = 2,
    FCSchemedConfigurationTypeAdHoc = 3,
    FCSchemedConfigurationTypeAcceptance = 4,
    FCSchemedConfigurationTypeAppStore = 5
};


@interface FCSchemedConfiguration : NSObject


+ (void)setConfigurationType:(FCSchemedConfigurationType)configurationType;

+ (id)objectForKey:(NSString *)key;


@end
