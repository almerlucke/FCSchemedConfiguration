//
//  ViewController.m
//  Demo
//
//  Created by Almer Lucke on 07/02/14.
//  Copyright (c) 2014 Almer Lucke. All rights reserved.
//


#import "ViewController.h"
#import "FCSchemedConfiguration.h"


@interface ViewController ()
@property (nonatomic, strong) IBOutlet UILabel *label1;
@property (nonatomic, strong) IBOutlet UILabel *label2;
@end


@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    // the value of this keys will change based on the build configuration selected
    self.label1.text = [FCSchemedConfiguration objectForKey:@"appKey"];
    self.label2.text = [FCSchemedConfiguration objectForKey:@"appSecret"];
}

@end
