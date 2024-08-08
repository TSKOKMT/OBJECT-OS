#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class unbalanceLance {

public:
    void draw(ofRectangle frame_, float time_);
    
    float side = 30;
        
private:
    paletteCloud myColorCloud;
};
