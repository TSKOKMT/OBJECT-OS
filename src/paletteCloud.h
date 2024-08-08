#pragma once

#include "ofMain.h"

class paletteCloud {

public:
    paletteCloud();
    
    vector<ofColor> six;
    vector<ofColor> mono;
    vector<ofColor> rgb;
    vector<ofColor> sakamoto;
    vector<ofColor> ikko;
        
private:
    vector<ofColor> load(string path_);
};
