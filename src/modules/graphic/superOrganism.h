#pragma once

#include "ofMain.h"
 
#include "fourthFilter.h"
#include "ofxConvexHull.h"

#include "colorCloud.h"

class superOrganism {

public:
    void draw(ofRectangle frame_, float time_);
        
private:
    ofxConvexHull convexHull;
    
    colorCloud myColorCloud;
};
