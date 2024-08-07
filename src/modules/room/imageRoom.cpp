#include "imageRoom.h"

//--------------------------------------------------------------
void imageRoom::load(string path_) {
    
    image.load(path_);
}

//--------------------------------------------------------------
void imageRoom::draw(ofRectangle frame_) {
    
    image.draw(frame_);
}
