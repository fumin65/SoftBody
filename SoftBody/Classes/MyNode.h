//
//  MyNode.h
//  SoftBody
//
//  Created by 安部 将史 on 13/05/03.
//
//

#ifndef __SoftBody__MyNode__
#define __SoftBody__MyNode__

#include "cocos2d.h"
#include "Box2D.h"

typedef struct {
    GLfloat x;
    GLfloat y;
} Vertex2D;

class MyNode : public cocos2d::CCNode {
public:
    MyNode();
    virtual ~MyNode();
    bool init();
    void createPhysicsObject(b2World *world);
    
    CREATE_FUNC(MyNode);
};

#endif /* defined(__SoftBody__MyNode__) */
