//
//  Box2DDebugLayer.cpp
//  SoftBody
//
//  Created by 安部 将史 on 13/05/03.
//
//

#include "Box2DDebugLayer.h"

#define PTM_RATIO 32.0f

using namespace cocos2d;

Box2DDebugLayer::Box2DDebugLayer(b2World *world) {
    this->world = world;
}

Box2DDebugLayer::~Box2DDebugLayer() {
    
    delete debugDraw;
    debugDraw = NULL;
    world = NULL;
}

bool Box2DDebugLayer::init() {
    
    if (!CCLayer::init()) {
        return false;
    }
    
    debugDraw = new GLESDebugDraw(PTM_RATIO);
    
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    
    debugDraw->SetFlags(flags);
    world->SetDebugDraw(debugDraw);
    
    return true;
}

Box2DDebugLayer* Box2DDebugLayer::create(b2World *world) {
    
    Box2DDebugLayer *layer = new Box2DDebugLayer(world);
    
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    
    delete layer;
    layer = NULL;
    
    return NULL;
}

void Box2DDebugLayer::draw() {
    ccGLEnableVertexAttribs(kCCVertexAttribFlag_Position);
    kmGLPushMatrix();
    world->DrawDebugData();
    kmGLPopMatrix();
}