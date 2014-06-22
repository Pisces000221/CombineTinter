#include "StartupScene.h"
#include "MenuItemLabelTint.h"
#include "Global.h"
using namespace cocos2d;

bool Startup::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255))) return false;

    // The title/banner label
    auto titleLabel = ctinter::label("COMBINETINTER", 60, false);
    titleLabel->setNormalizedPosition(Vec2(0.5, 0.8));
    this->addChild(titleLabel);
    titleLabel->runAction(Sequence::create(
        DelayTime::create(1),
        TintTo::create(0.5, 0, 0, 0),
        CallFunc::create([titleLabel]() {
            // Tint 'TINTER'
            auto letterTintAction = TintTo::create(1, rand() % 256, rand() % 256, rand() % 256);
            for (int i = 7; i < 13; i++) {
                titleLabel->getLetter(i)->setColor(Color3B::BLACK);
                titleLabel->getLetter(i)->runAction(letterTintAction->clone());
            }
        }), nullptr));

    auto newGameMenu = MenuItemLabelTint::create(
        ctinter::label("New game", 36, false, Color3B::BLACK), CC_CALLBACK_1(Startup::newGame, this));
    newGameMenu->setNormalizedPosition(Vec2(0.5, 0.618));
    newGameMenu->setOpacity(0);
    auto menu = Menu::create(newGameMenu, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    newGameMenu->runAction(Sequence::create(
        DelayTime::create(3),
        FadeIn::create(0.6), nullptr));

    return true;
}

void Startup::newGame(Ref *sender)
{
    CCLOG("New game");
}
