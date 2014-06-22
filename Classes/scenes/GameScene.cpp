#include "GameScene.h"
#include "MenuItemLabelTint.h"
#include "Global.h"
using namespace cocos2d;

bool Gameplay::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255))) return false;

    return true;
}
