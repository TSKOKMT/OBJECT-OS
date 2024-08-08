#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class superFlat {

public:
    superFlat();
    
    void draw(ofRectangle frame_, float time_);
    
    void drawBoxes(ofPoint center_, float clock_, ofPoint rotation_, float side_);
    
    paletteCloud myColorCloud;
};