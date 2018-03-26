/* 
 * Licensed Materials - Property of IBM 
 * 
 * 5725E28, 5725I03 
 * 
 * © Copyright IBM Corp. 2014, 2018
 * US Government Users Restricted Rights - Use, duplication or disclosure restricted by GSA ADP Schedule Contract with IBM Corp. 
 */


#import "DisplayWebViewPlugin.h"
#import "WebViewController.h"

@implementation DisplayWebViewPlugin

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

-(void)performAction:(NSDictionary*)action
{
    WebViewController * viewController = [[WebViewController alloc] initWithURL:[NSURL URLWithString:action[@"value"]]];
    UIViewController * controller = MCESdk.sharedInstance.findCurrentViewController;
    [controller presentViewController:viewController animated:TRUE completion:nil];
}

+(void)registerPlugin
{
    MCEActionRegistry * registry = [MCEActionRegistry sharedInstance];

    [registry registerTarget: [self sharedInstance] withSelector:@selector(performAction:) forAction: @"displayWebView"];
}

@end
