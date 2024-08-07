#include "ellipseRoom.h"

//--------------------------------------------------------------
void ellipseRoom::draw(ofRectangle frame_) {
    
    ofDrawEllipse(frame_.getCenter().x, frame_.getCenter().y, frame_.width, frame_.height);
}
