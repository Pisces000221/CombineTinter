#include "AppDelegate.h"
#include "SplashScene.h"
#include "Global.h"
using namespace cocos2d;

#define USE_BG_MUSIC 0

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLView::createWithRect("Combine Tinter PC", Rect(0, 0, 480, 320));
        director->setOpenGLView(glview);
    }
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);
    Device::setAccelerometerEnabled(true);
    ctinter::init();
    // Everything ready, let's go!
    auto scene = Splash::createScene();
    director->runWithScene(scene);
    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
#if USE_BG_MUSIC
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
#endif
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
#if USE_BG_MUSIC
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
#endif
}
