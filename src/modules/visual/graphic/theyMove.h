#pragma once

#include "ofMain.h"

#include "ofxFrameOcean.h"

#include "paletteCloud.h"

class theyMove {

public:
    void draw(ofRectangle frame_, float time_);
    
    int count_ = 5;
    float term_ = .1;
    bool bVertical_ = false;
    
private:
    paletteCloud myColorCloud;
};
