#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class icoIcon {

public:
    icoIcon();
    void draw(ofRectangle frame_, float time_);
    
    float side = 45;
    float term = 12;
        
private:
    paletteCloud myColorCloud;
    int colorOffset = 0;
    
    int previousFrameNum;
};
