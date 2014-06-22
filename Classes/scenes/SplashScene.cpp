#include "SplashScene.h"
#include "StartupScene.h"
#include "Global.h"
using namespace cocos2d;

bool Splash::init()
{
    CCLOG("0x%x (%d x %d)", &ctinter::vsize, ctinter::vsize.width, ctinter::vsize.height);
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255))) return false;

    auto sprite = Sprite::create("images/cocos2dx_portrait.png");
    sprite->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    sprite->setPosition(Vec2(-24, ctinter::vsize.height + 48));
    sprite->setOpacity(144);
    sprite->setScale(ctinter::vsize.height * 0.9 / sprite->getTextureRect().size.width);
    this->addChild(sprite);

    auto label_1 = ctinter::label("Powered by", 70, false);
    label_1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    label_1->setPosition(Vec2(ctinter::vsize.width * 0.65, 108));
    label_1->setColor(Color3B(0, 0, 0));
    this->addChild(label_1);

    auto label_2 = ctinter::label("Cocos2d-x", 105, true);
    label_2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    label_2->setPosition(Vec2(ctinter::vsize.width * 0.65, 3));
    label_2->setColor(Color3B(0, 0, 0));
    this->addChild(label_2);

    this->scheduleOnce(schedule_selector(Splash::goOn), 2);

    return true;
}

void Splash::goOn(float dt)
{
    auto nextScene = Startup::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.8, nextScene, Color3B::WHITE));
}
