#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class rectangleRoom {
    
public:
    void begin(int term_, bool b_);
    void draw(ofRectangle frame_);
    
private:
    float beginTime;
    float term;
    
    bool bInvert;
    
    int count = 0;
};
