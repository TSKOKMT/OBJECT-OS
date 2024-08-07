#include "crossRoom.h"

//--------------------------------------------------------------
void crossRoom::draw(ofRectangle frame_) {
    
    ofDrawLine(frame_.getTopLeft(), frame_.getBottomRight());
    ofDrawLine(frame_.getTopRight(), frame_.getBottomLeft());
}
