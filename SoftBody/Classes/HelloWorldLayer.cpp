//
//  HelloWorldLayer.cpp
//  SoftBody
//
//  Created by 安部 将史 on 13/05/06.
//
//

#include "HelloWorldLayer.h"

using namespace cocos2d;

HelloWorldLayer::HelloWorldLayer(b2World *world) {
    this->world = world;
}

HelloWorldLayer::~HelloWorldLayer() {
    world = NULL;
    node->release();
}

void HelloWorldLayer::ccTouchesEnded(cocos2d::CCSet *touches, cocos2d::CCEvent *event) {
    node->bounce();
}

bool HelloWorldLayer::init() {
    
    if (!CCLayer::init()) {
        return false;
    }
    
    setTouchEnabled(true);
    
    node = MyNode::create();
    node->retain();
    node->setPosition(ccp(240, 160));
    node->createPhysicsObject(world);
    
    addChild(node);
    
    return true;
}

HelloWorldLayer* HelloWorldLayer::create(b2World *world) {
    
    HelloWorldLayer *layer = new HelloWorldLayer(world);
    
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    
    delete layer;
    layer = NULL;
    
    return NULL;
}