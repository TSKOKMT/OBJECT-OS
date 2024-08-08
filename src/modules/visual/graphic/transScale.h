#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class transScale {

public:
    void draw(ofRectangle frame_, float time_);
    
    ofParameter<int> side = 12;
        
private:
    vector<float> balancesX;
    vector<float> balancesY;
    
    paletteCloud myColorCloud;
};
