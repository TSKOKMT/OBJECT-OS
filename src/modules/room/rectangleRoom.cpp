#include "rectangleRoom.h"

//--------------------------------------------------------------
void rectangleRoom::begin(int term_, bool b_) {
    
    beginTime = ofGetElapsedTimef();
    term = term_ / 1000.;
    
    bInvert = b_;
    
    count++;
}

//--------------------------------------------------------------
void rectangleRoom::draw(ofRectangle frame_) {
    
    float ratio = (ofGetElapsedTimef() - beginTime) / term;
    ratio = ofClamp(ratio, 0, 1);
    ratio = ofxTskokmtMath::cubicBezierByX(ofPoint(.25, 0), ofPoint(0, 1), ratio);
    if (bInvert) ratio = 1 - ratio;
    
    ofNoFill();
    
    if (count % 2) {
        ofBeginShape();
        ofVertex(frame_.getLeft() + ratio * frame_.width, frame_.getTop());
        ofVertex(frame_.getRight() - ratio * frame_.width, frame_.getBottom());
        ofEndShape();
    }
    else {
        ofBeginShape();
        ofVertex(frame_.getRight(), frame_.getTop() + ratio * frame_.height);
        ofVertex(frame_.getLeft(), frame_.getBottom() - ratio * frame_.height);
        ofEndShape();
    }
}
