//
//  MyNode.cpp
//  SoftBody
//
//  Created by 安部 将史 on 13/05/03.
//
//

#include "MyNode.h"

#define PTM_RATIO 32.f
#define NUM_SEGMENTS 12

using namespace cocos2d;

class CCBody : public CCObject {
public:
    
    CCBody(b2Body *body) {
        this->body = body;
    }
    
    ~CCBody(){
        body = NULL;
    }
    
    b2Body* getBody() {
        return body;
    }
    
private:
    b2Body *body;
};

MyNode::MyNode() {}
MyNode::~MyNode() {}

bool MyNode::init() {
    
    if (!CCNode::init()) {
        return false;
    }
    
    return true;
}

void MyNode::createPhysicsObject(b2World *world) {
   
    b2Vec2 center = b2Vec2(240 / PTM_RATIO, 260 / PTM_RATIO);
    
    b2CircleShape circleShape;
    circleShape.m_radius = 0.25f;
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 0.1;
    fixtureDef.restitution = 0.05;
    fixtureDef.friction = 1.0;
    
    float springiness = 4.0;
    float deltaAngle = (2.f * M_PI) / NUM_SEGMENTS;
    float radius =50;
    
    CCArray *bodies = CCArray::create();
    
    for (int i = 0; i < NUM_SEGMENTS; i++) {
        float theta = deltaAngle * i;
        
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        
        b2Vec2 circlePosition = b2Vec2(x / PTM_RATIO, y / PTM_RATIO);
        
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position = (center + circlePosition);
        
        b2Body *body = world->CreateBody(&bodyDef);
        body->CreateFixture(&fixtureDef);
        
        CCBody *ccBody = new CCBody(body);
        bodies->addObject(ccBody);
        ccBody->release();
    }
    
    b2BodyDef innerCircleBodyDef;
    innerCircleBodyDef.type = b2_dynamicBody;
    innerCircleBodyDef.position = center;
    
    b2Body *innerCircleBody = world->CreateBody(&innerCircleBodyDef);
    innerCircleBody->CreateFixture(&fixtureDef);
    
    b2DistanceJointDef jointDef;
    
    for (int i = 0; i < NUM_SEGMENTS; i++) {
        int neighborIndex = (i + 1) % NUM_SEGMENTS;
        
        b2Body *currentBody = ((CCBody*) bodies->objectAtIndex(i))->getBody();
        b2Body *neighborBody = ((CCBody*) bodies->objectAtIndex(neighborIndex))->getBody();
        
        jointDef.Initialize(currentBody,
                            neighborBody,
                            currentBody->GetWorldCenter(),
                            neighborBody->GetWorldCenter());
        jointDef.collideConnected = true;
        jointDef.frequencyHz = springiness;
        jointDef.dampingRatio = 0.5f;
        
        world->CreateJoint(&jointDef);
        
        jointDef.Initialize(currentBody,
                            innerCircleBody,
                            currentBody->GetWorldCenter(),
                            center);
        jointDef.collideConnected = true;
        jointDef.frequencyHz = springiness;
        jointDef.dampingRatio = 0.5f;

        world->CreateJoint(&jointDef);
        
    }

}











