## FCPostOffice

FCPostOffice makes it possible for remote parts of your application to communicate in a structured way. Usually you would not need something like FCPostOffice, but if your app is really complex with a lot of view controllers that sometimes need to be talking to each other, FCPostOffice offers a nice solution. Ofcourse there is NSNotificationCenter, but notifications are not very specific. 

FCPostOffice is the opposite of NSNotificationCenter. With FCPostOffice you can send messages to specific addresses. For instance, if one view controller is registered at address "viewcontroller1", another view controller can target only that specific view controller by sending a message to "viewcontroller1". 

Because FCPostOffice uses a URL type scheme you can do sub-addressing when you send a message to a registered address. For example if an object is registered at "object1" and we send a message to it with address "object1/level1/part1", the message is delivered to the registered handler at "object1", but the message passed to the receiver will have it's addressee property set to "level1/part1". In this way the receiver can do further dispatching based on the addressee part.

### Installation

The easiest way is to use CocoaPods. If you don't already, here's a [guide](http://guides.cocoapods.org/using/getting-started.html).

	pod 'FCPostOffice', '~>1.0.0'

### Usage

You can register a handler with a FCPostOfficeMessageHandler protocol compliant object:

    [FCPostOffice registerHandler:self forAddress:@"appDelegate"];

The FCPostOfficeMessageHandler protocol contains only one method which must be implemented by any compliant object:

    - (void)handlePostOfficeMessage:(FCPostOfficeMessage *)message
	{
   	 	NSString *redirect = [NSString stringWithFormat:@"%@/Test", message.from];
    	id obj = [FCPostOffice registeredHandlerForAddress:message.from];
    
    	NSLog(@"message received from %@", obj);
    
    	[FCPostOffice post:@"Hello viewcontroller" 
    		   contentType:@"string" 
    		   		  from:@"appDelegate" 
    		   		  	to:@[redirect]];
	}

But you can also register a handler with a block:

	[FCPostOffice registerHandlerBlock:^(FCPostOfficeMessage *message) {
        NSLog(@"message \"%@\" from \"%@\" addressee \"%@\"", message.content, 
        													  message.from, 
        													  message.addressee);
    } forAddress:@"appDelegate"];

It is wise to unregister when the object registered to an address is not able to handle any incoming messages any more (for instance when it is deallocated):

    [FCPostOffice unregisterHandlerForAddress:@"appDelegate"];

To post a message to one or more addresses you can use:

	[FCPostOffice post:@"Hello viewcontrollers" 
		   contentType:@"string" 
		   		  from:@"appDelegate" 
		   		  	to:@[@"viewcontroller1", @"viewcontroller2"]];

You can get the object that is registered at an address. Keep in mind that this will return nil if there is no one registered or if the registration was done with a block:

	[FCPostOffice registeredHandlerForAddress:@"appDelegate"];


