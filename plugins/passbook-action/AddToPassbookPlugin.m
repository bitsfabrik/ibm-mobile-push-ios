/*
 * Licensed Materials - Property of IBM
 *
 * 5725E28, 5725I03
 *
 * © Copyright IBM Corp. 2015, 2017
 * US Government Users Restricted Rights - Use, duplication or disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#if __has_feature(modules)
@import PassKit;
#else
#import <PassKit/PassKit.h>
#endif

#import <objc/runtime.h>
#import "AddToPassbookPlugin.h"

@implementation AddToPassbookPlugin

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

- (void)addPassesViewControllerDidFinish:(PKAddPassesViewController *)controller
{
    if(![PKPassLibrary isPassLibraryAvailable])
    {
        NSLog(@"Could not determine if the pass was added to the library, it is not available.");
        return;
    }
    
    PKPass * pass = (PKPass*) objc_getAssociatedObject(controller, @"pass");
    PKPassLibrary * library = [[PKPassLibrary alloc]init];
    if([library containsPass: pass])
    {
        NSLog(@"Pass added to user's library");
    }
    else
    {
        NSLog(@"Pass NOT added to user's library");
    }
    [controller dismissViewControllerAnimated:true completion:^(void){}];
}

-(void)performAction:(NSDictionary*)action
{
    NSURL * url = [NSURL URLWithString: action[@"value"]];
    [self.client getPassFrom:url withCompletion:^(PKPass * pass, NSError * error){
        dispatch_async(dispatch_get_main_queue(), ^{
            if(error)
            {
                NSLog(@"Pass error %@", [error localizedDescription]);
                [[[MCESdk.sharedInstance.alertViewClass alloc] initWithTitle:@"Pass Verifcation Failed" message:[error localizedDescription] delegate:nil cancelButtonTitle:@"ok" otherButtonTitles: nil] show];
                return;
            }
        
            NSLog(@"Pass downloaded");
            PKAddPassesViewController * passVC = [[PKAddPassesViewController alloc] initWithPass:pass];
            passVC.delegate=self;
            
            UIViewController * controller = MCESdk.sharedInstance.findCurrentViewController;
            [controller presentViewController:passVC animated:TRUE completion:^(void){
                NSLog(@"Pass presented to user");
            }];
        });
    }];
}

+(void)registerPlugin
{
    MCEActionRegistry * registry = [MCEActionRegistry sharedInstance];
    [[self sharedInstance] setClient: [[AddToPassbookClient alloc] init]];
    [registry registerTarget: [self sharedInstance] withSelector:@selector(performAction:) forAction: @"passbook"];
}

@end
