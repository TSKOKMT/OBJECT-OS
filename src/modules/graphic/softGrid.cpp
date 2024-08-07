#include "softGrid.h"

//--------------------------------------------------------------
void softGrid::draw(ofRectangle frame_, float time_) {
    
    auto rooms = pushGrid.get(frame_, time_);
    
    for (int i = 0; i < rooms.size(); i++) {
        ofSetColor(myColorCloud.six[i % 6]);
        
        //triangleRoom.draw(rooms[i]);
        ellipseRoom.draw(rooms[i]);
    }
}
