#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class spanningCole {

public:
    void draw(ofRectangle frame_, float time_);
    
    void drawOne(ofPoint center_, float radius_, int count_, float rotation_);
        
private:
    float time;
    
    paletteCloud myColorCloud;
};
