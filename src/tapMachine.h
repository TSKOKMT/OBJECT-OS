#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class tapMachine {

public:
    void tap();
    
    int bpm = 125;
    
    bool bTapping = false;
        
private:
    vector<float> tappedTimes;
};
