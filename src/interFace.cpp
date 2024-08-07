#include "interFace.h"

//--------------------------------------------------------------
interFace::interFace() {
    
    receiverP.setup(1000);
    receiverC.setup(1001);
    
    pads.resize(8);
    for (int i = 0; i < pads.size(); i++) pads[i].resize(8);
    
    controls.resize(4);
    for (int i = 0; i < controls.size(); i++) controls[i].resize(8);
}

//--------------------------------------------------------------
vector<vector<float>> interFace::getPads() {
    
    check();
    
    return pads;
}

//--------------------------------------------------------------
vector<vector<float>> interFace::getControls() {
    
    check();
    
    return controls;
}

//--------------------------------------------------------------
void interFace::check() {
    
    for (int y = 0; y < pads.size(); y++) {
        for (int x = 0; x < pads[y].size(); x++) {
            pads[y][x] = 0;
        }
    }
    while (receiverP.hasWaitingMessages()) {
        ofxOscMessage message;
        receiverP.getNextMessage(message);
        if (message.getAddress() == "pad") {
            int i = 0;
            for (int y = 0; y < pads.size(); y++) {
                for (int x = 0; x < pads[y].size(); x++) {
                    float newValue = message.getArgAsFloat(i);
                    if (newValue > 0) pads[y][x] = newValue;
                    i++;
                }
            }
        }
    }
    
    while (receiverC.hasWaitingMessages()) {
        ofxOscMessage message;
        receiverC.getNextMessage(message);
        if (message.getAddress() == "control") {
            int i = 0;
            for (int y = 0; y < controls.size(); y++) {
                for (int x = 0; x < controls[y].size(); x++) {
                    controls[y][x] = message.getArgAsFloat(i);
                    i++;
                }
            }
        }
    }
}
