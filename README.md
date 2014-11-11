## FCSchemedConfiguration

FCSchemedConfiguration allows you to specify different configuration values for the same key based on the build configuration you select. This allows you for example to specify different API endpoints or app secrets depending on the build you make (debug, release etc..)

You need to add a FCSchemedConfiguration.plist configuration file to your bundle for this to work. In this configuration file you can add a dictionary for each configuration key you need. In this dictionary you can specify a different value based on build configuration. The "default" key defines the fallback value if no other key matches the currently set configuration scheme.

Add a FCSCHEMEDCONFIGURATION preprocessor macro for each configuration, so for an AdHoc configuration you could add 

    FCSCHEMEDCONFIGURATION=\@\"adhoc\" 

as a preprocessor macro.

Then use the following code snippet to set the configuration scheme (for example in your app delegate didFinishLaunchingWithOptions method):

    #ifdef FCSCHEMEDCONFIGURATION
        [FCSchemedConfiguration setConfigurationScheme:FCSCHEMEDCONFIGURATION];
    #endif

Check the demo project for an example of how this works. When you run the demo try to select different build configurations for the Run scheme (Edit scheme menu)

### Installation

The easiest way is to use CocoaPods. If you don't already, here's a [guide](http://guides.cocoapods.org/using/getting-started.html).

    pod 'FCSchemedConfiguration', '~>1.1.0'

### Usage

Use setConfigurationScheme to define the configuration currently in use:

    [FCSchemedConfiguration setConfigurationScheme:FCSCHEMEDCONFIGURATION];

Get the value for a configuration key with:

    [FCSchemedConfiguration objectForKey:@"appSecret"];