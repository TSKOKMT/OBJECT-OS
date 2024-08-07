#pragma once

#include "ofMain.h"

#include "ofxVoronoi.h"
#include "ofxTskokmtMath.h"

#include "colorCloud.h"

class nightDiary {

public:
    void draw(ofRectangle frame_, float time_);
    
    int count = 7;
    float hour = 3;
    float power = 3;
    bool bConvex = false;
    bool bCurve = false;
        
private:
    ofxVoronoi voronoi;
    
    colorCloud myColorCloud;
};
