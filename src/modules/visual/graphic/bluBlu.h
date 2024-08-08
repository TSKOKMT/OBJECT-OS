#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class bluBlu {

public:
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<float> term = 4;
    ofParameter<float> radius = 60;
    ofParameter<int> count_ = 5;
    ofParameter<float> delay_ = TWO_PI;
    
private:
    paletteCloud myColorCloud;
};
