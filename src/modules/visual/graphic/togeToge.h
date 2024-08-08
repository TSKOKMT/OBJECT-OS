#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class togeToge {

public:
    void draw(ofRectangle frame_, float time_);
    
    void drawOne(ofRectangle frame_, float time_, int count_, bool bLeft_);
    
    int count = 13;
        
private:
    paletteCloud myColorCloud;
};
