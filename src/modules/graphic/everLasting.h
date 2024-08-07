#pragma once

#include "ofMain.h"

#include "ofxVoronoi.h"
#include "ofxConvexHull.h"
#include "fourthParty.h"

#include "colorCloud.h"

class everLasting {
    
public:
    vector<ofPoint> draw(ofRectangle frame_, float time_);
    
    ofParameter<float> targetSize_ = 45;
    
private:
    ofxVoronoi voronoi;
    ofxConvexHull convexHull;
    
    colorCloud myColorCloud;
};
