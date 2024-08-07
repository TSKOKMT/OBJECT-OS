#pragma once

#include "ofMain.h"

class fourthParty {

public:
    static void get(ofPoint point01_, ofPoint point02_, ofPoint point03_, ofPoint& center_, float& radius_);
    static void get(vector<ofPoint> points_, ofPoint& center_, float& radius_);
        
private:
};
