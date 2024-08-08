#pragma once

#include "ofMain.h"

#include "ofxBullet.h"

#include "paletteCloud.h"

class winterRoad {

public:
    winterRoad();
    
    void draw(ofRectangle frame_, float time_);
    
    void create(int id_);
        
private:
    float time;
    float previousTime;
    
    ofCamera camera;
    
    ofxBulletWorldRigid world;
    
    vector<ofPtr<ofxBulletCylinder>> cylinders;
    
    float cameraSpeed = -500;
    
    int previousFrameNum = 0;
    
    paletteCloud myColorCloud;
};
