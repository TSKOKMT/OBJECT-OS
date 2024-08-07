#pragma once

#include "ofMain.h"

#include "ofxVoronoi.h"

#include "colorCloud.h"

class screeningTest {

public:
    void draw(ofRectangle frame_, float time_);
    
private:
    float time;
    float previousTime;
    
    float position;
    
    ofxVoronoi voronoi;
    
    colorCloud myColorCloud;
};
