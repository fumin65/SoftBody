//
//  SofBodyScene.h
//  SoftBody
//
//  Created by 安部 将史 on 13/05/02.
//
//

#ifndef __SoftBody__SofBodyScene__
#define __SoftBody__SofBodyScene__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Box2DDebugLayer.h"

class SofBodyScene : public cocos2d::CCScene {
public:
    SofBodyScene();
    virtual ~SofBodyScene();
    bool init();
    CREATE_FUNC(SofBodyScene);
    void update(float dt);
private:
    b2World *world;
    Box2DDebugLayer *debugLayer;
};

#endif /* defined(__SoftBody__SofBodyScene__) */
