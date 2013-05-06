//
//  SofBodyScene.cpp
//  SoftBody
//
//  Created by 安部 将史 on 13/05/02.
//
//

#include "SofBodyScene.h"

using namespace cocos2d;

SofBodyScene::SofBodyScene() {
    
}

SofBodyScene::~SofBodyScene() {

    delete world;
    debugLayer->release();
    
    world = NULL;
    debugLayer = NULL;
}

bool SofBodyScene::init() {
    
    if (!CCScene::init()) {
        return false;
    }
    
    
    b2Vec2 gravity;
    gravity.Set(0.0f, -10.0f);
    world = new b2World(gravity);
    world->SetAllowSleeping(true);
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    b2EdgeShape groundBox;
    
    // top
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);

    // left
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(0,0));
    groundBody->CreateFixture(&groundBox,0);

    // right
    groundBox.Set(b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
    
    // bottom ground
    groundBox.Set(b2Vec2(0,0), b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
    
    debugLayer = Box2DDebugLayer::create(world);
    debugLayer->retain();
    
    
    CCLayer *layer = HelloWorldLayer::create(world);

    addChild(debugLayer);
    addChild(layer);
//    addChild(debugLayer, 9999);
    
    scheduleUpdate();
    
    return true;
}

void SofBodyScene::update(float dt) {
    CCScene::update(dt);
    world->Step(dt, 8, 1);
}

