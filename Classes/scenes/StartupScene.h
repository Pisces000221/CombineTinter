#ifndef __CombineTinter__StartupScene_h__
#define __CombineTinter__StartupScene_h__

#include "cocos2d.h"
#include "Global.h"

class Startup : public cocos2d::LayerColor
{
public:
    virtual bool init();  
    CREATE_FUNC(Startup);
    SCENE_FUNC(Startup);

    void newGame(Ref *sender);
};

#endif
