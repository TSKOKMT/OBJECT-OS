#include "triangleRoom.h"

//--------------------------------------------------------------
void triangleRoom::draw(ofRectangle frame_) {
    
    ofDrawTriangle(frame_.getTopLeft(), frame_.getBottomLeft(), ofPoint(frame_.getCenter().x, frame_.getBottom()));
    ofDrawTriangle(frame_.getTopRight(), frame_.getBottomRight(), ofPoint(frame_.getCenter().x, frame_.getTop()));
}
