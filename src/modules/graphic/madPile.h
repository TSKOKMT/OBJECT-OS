#pragma once

#include "ofMain.h"

#include "ofxClipper.h"
#include "everLasting.h"

#include "colorCloud.h"

class madPile {

public:
    madPile();
    void draw(ofRectangle frame_, float time_);
    
    float count_ = 5;
    float width = 12;
        
private:
    everLasting everLasting;
    
    colorCloud myColorCloud;
};
