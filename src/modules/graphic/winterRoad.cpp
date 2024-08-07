#include "winterRoad.h"

//--------------------------------------------------------------
winterRoad::winterRoad() {
    
    world.setup();
    world.enableGrabbing();
    world.enableDebugDraw();
    world.setCamera(&camera);
    world.setGravity(ofPoint(0, 5000, 0));
    
    /*for (int i = 0; i < 10; i++) {
        cylinders.push_back(ofPtr<ofxBulletCylinder>(new ofxBulletCylinder));
        cylinders.back()->create(world.world, ofVec3f(ofRandom(-4000, 4000), -5000, ofRandom(-4000, 4000)), .8, 10, 1000);
        cylinders.back()->add();
    }*/
    
    camera.setVFlip(true);
    camera.setFarClip(100000);
    camera.setNearClip(.01);
    camera.setFov(90);
    //camera.enableOrtho();
}

//--------------------------------------------------------------
void winterRoad::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    previousTime = time;
    time = time_;
    
    if (previousFrameNum != ofGetFrameNum()) {
        if (ofGetFrameNum() % 120 == 0) create(ofRandom(3));
        
        //Keep cylinder count
        while (cylinders.size() >= 200) cylinders.erase(cylinders.begin());
        
        //camera.setPosition(ofSignedNoise(time_ / 12.) * 5000, -400, ofSignedNoise(time_ / 12., PI * 100) * 5000);
        //camera.lookAt(ofPoint(0, -400, 0));
        camera.setPosition(0, -400, time * cameraSpeed);
        
        camera.setFov(atan2(frame_.height, sqrt(frame_.width * frame_.height)) * 2 * 1.25 * RAD_TO_DEG);
        
        ofxBulletBox ground;
        ground.create(world.world, ofPoint(camera.getPosition().x, 1000, camera.getPosition().z), 0., 10000, 1000, 20000);
        ground.setProperties(1, .95);
        ground.add();
        
        /*float interval = 1;
        if (ofWrap(time, 0, interval) < ofWrap(previousTime, 0, interval)) {
            for (int i = 0; i < 10; i++) {
                cylinders.push_back(ofPtr<ofxBulletCylinder>(new ofxBulletCylinder));
                cylinders.back()->create(world.world, ofVec3f(ofRandom(-4000, 4000), -5000, ofRandom(-4000, 4000)), .8, 25, 400);
                cylinders.back()->add();
            }
        }*/
        /*float interval = 1;
        if (ofWrap(time, 0, interval) < ofWrap(previousTime, 0, interval)) {
            for (int i = 0; i < 10; i++) {
                cylinders.push_back(ofPtr<ofxBulletCylinder>(new ofxBulletCylinder));
                cylinders.back()->create(world.world, camera.getPosition() + ofVec3f(ofRandom(-4000, 4000), -5000, ofRandom(-8000, 0)), .8, 10, 1000);
                cylinders.back()->add();
            }
        }*/
        
        world.update();
        
        previousFrameNum = ofGetFrameNum();
    }
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    camera.begin();
    
    ofPushStyle();
    
    for (int i = 0; i < cylinders.size(); i++) {
        ofSetColor(myColorCloud.six[i % 6]);
        cylinders[i]->draw();
    }
    
    ofPopStyle();
    
    //ground.draw();
    
    camera.end();
    
    ofPopMatrix();
    fbo.end();
    
    fbo.draw(frame_.position);
}

//--------------------------------------------------------------
void winterRoad::create(int id_) {
    
    if (id_ == 0) {
        for (int i = 0; i < 10; i++) {
            cylinders.push_back(ofPtr<ofxBulletCylinder>(new ofxBulletCylinder));
            cylinders.back()->create(world.world, camera.getPosition() + ofVec3f(ofRandom(-5000, 5000), -10000, ofRandom(-10000, 0)), .8, 20, 1200);
            cylinders.back()->add();
        }
    }
    if (id_ == 1) {
        for (int i = 0; i < 10; i++) {
            cylinders.push_back(ofPtr<ofxBulletCylinder>(new ofxBulletCylinder));
            cylinders.back()->create(world.world, camera.getPosition() + ofVec3f(ofRandom(-5000, 5000), -10000, ofRandom(-10000, 0)), .8, 1200, 20);
            cylinders.back()->add();
        }
    }
    if (id_ == 2) {
        for (int i = 0; i < 10; i++) {
            cylinders.push_back(ofPtr<ofxBulletCylinder>(new ofxBulletCylinder));
            cylinders.back()->create(world.world, camera.getPosition() + ofVec3f(ofRandom(-5000, 5000), -10000, ofRandom(-10000, 0)), .8, 300, 600);
            cylinders.back()->add();
        }
    }
}
