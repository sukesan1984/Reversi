#import <UIKit/UIKit.h>
extern "C"{
#import <GoogleMobileAds/GADBannerView.h>
};


@class RootViewController;

@interface AppController : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    GADBannerView *bannerView_;
}

@property (nonatomic, retain) UIWindow *window;
@property(nonatomic, readonly) RootViewController* viewController;

@end

