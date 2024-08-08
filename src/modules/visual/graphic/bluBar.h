#pragma once

#include "ofMain.h"

#include "paletteCloud.h"

class bluBar {

public:
    void draw(ofRectangle frame_, float time_);
    
    int count = 7;
        
private:
    static void drawOne(ofPoint position_, float width_, float ratio_, int count_ = 12);
    
    paletteCloud myColorCloud;
};
