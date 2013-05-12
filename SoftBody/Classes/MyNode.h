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
#include "CCGL.h"

#define PTM_RATIO 32.f
#define NUM_SEGMENTS 12
#define RADIUS 0.25f

typedef struct {
    GLfloat x;
    GLfloat y;
} Vertex2D;

static inline Vertex2D Vertex2DMake(GLfloat x, GLfloat y) {
    Vertex2D vertex;
    vertex.x = x;
    vertex.y = y;
    return vertex;
}

class MyNode : public cocos2d::CCNode {
public:
    MyNode();
    virtual ~MyNode();
    bool init();
    void createPhysicsObject(b2World *world);
    virtual void draw(void);
    void bounce();
    CREATE_FUNC(MyNode);
private:
    cocos2d::CCArray *bodies;
    b2Body *innerCircleBody;
    cocos2d::CCPoint triangleFanPos[NUM_SEGMENTS + 2];
};

// For part3
class TextureMappedNode : public cocos2d::CCNode {
private:
    cocos2d::CCPoint vertices[4];
    cocos2d::CCPoint textCoords[4];
    cocos2d::CCTexture2D *texture;
public:
    TextureMappedNode();
    virtual ~TextureMappedNode();
    bool init();
    virtual void draw(void);
};

#endif /* defined(__SoftBody__MyNode__) */
