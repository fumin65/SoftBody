//
//  Box2DDebugLayer.h
//  SoftBody
//
//  Created by 安部 将史 on 13/05/03.
//
//

#ifndef __SoftBody__Box2DDebugLayer__
#define __SoftBody__Box2DDebugLayer__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"

class Box2DDebugLayer : public cocos2d::CCLayer {
public:
    Box2DDebugLayer(b2World *world);
    virtual ~Box2DDebugLayer();
    bool init();
    void draw();
    
    static Box2DDebugLayer* create(b2World *world);
private:
    b2World *world; // weak ref
    GLESDebugDraw *debugDraw;
};


#endif /* defined(__SoftBody__Box2DDebugLayer__) */
