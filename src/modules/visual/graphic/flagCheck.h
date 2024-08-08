#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class flagCheck {

public:
    void load(string path_);
    void draw(ofRectangle frame_, float time_);
    
    int side_ = 12;
    float interval_ = 1;
        
private:
    paletteCloud myColorCloud;
};
