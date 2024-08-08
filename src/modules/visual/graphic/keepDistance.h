#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class keepDistance {

public:
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<int> count_;
    ofParameter<float> position_;
        
private:
    paletteCloud myColorCloud;
};
