#pragma once

#include "ofMain.h"

class imageRoom {
    
public:
    void load(string path_);
    void draw(ofRectangle frame_);
    
private:
    ofImage image;
};
