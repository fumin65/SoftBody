//
//  HelloWorldLayer.h
//  SoftBody
//
//  Created by 安部 将史 on 13/05/06.
//
//

#ifndef __SoftBody__HelloWorldLayer__
#define __SoftBody__HelloWorldLayer__

#include "cocos2d.h"
#include "Box2D.h"
#include "MyNode.h"

class HelloWorldLayer : public cocos2d::CCLayer {
public:
    HelloWorldLayer(b2World *world);
    virtual ~HelloWorldLayer();
    bool init();
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    static HelloWorldLayer* create(b2World *world);
private:
    b2World *world; // weak ref
    MyNode *node;
};

#endif /* defined(__SoftBody__HelloWorldLayer__) */
