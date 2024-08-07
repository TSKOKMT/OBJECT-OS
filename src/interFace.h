#pragma once

#include "ofMain.h"

#include "ofxOscReceiver.h"

class interFace {

public:
    interFace();
    
    vector<vector<float>> getPads();
    vector<vector<float>> getControls();

private:
    ofxOscReceiver receiverP;
    ofxOscReceiver receiverC;
    
    vector<vector<float>> pads;
    vector<vector<float>> controls;
    
    void check();
};
