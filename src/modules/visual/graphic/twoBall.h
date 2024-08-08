#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

#include "paletteCloud.h"

class twoBall {

public:
    void draw(ofRectangle frame_, float time_);
    
    float term_ = 1;
        
private:
    paletteCloud myColorCloud;
};
