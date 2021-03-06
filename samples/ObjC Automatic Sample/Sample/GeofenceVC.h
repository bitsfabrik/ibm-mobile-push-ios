/*
 * Licensed Materials - Property of IBM
 *
 * 5725E28, 5725I03
 *
 * © Copyright IBM Corp. 2016, 2017
 * US Government Users Restricted Rights - Use, duplication or disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#if __has_feature(modules)
@import UIKit;
@import CoreLocation;
@import MapKit;
#else
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>
#endif

@interface GeofenceVC : UIViewController <CLLocationManagerDelegate, MKMapViewDelegate, UIGestureRecognizerDelegate>
@property IBOutlet MKMapView * mapView;
@property IBOutlet UIBarButtonItem * gpsButton;
@property IBOutlet UIButton * status;
-(IBAction)clickGpsButton:(id)sender;
-(IBAction)refresh:(id)sender;
-(IBAction)enable:(id)sender;
@end
