#pragma once

#include "ofMain.h"

#include "pushGrid.h"
#include "splitGrid.h"

#include "ellipseRoom.h"
#include "imageRoom.h"
#include "crossRoom.h"
#include "triangleRoom.h"
#include "rectangleRoom.h"

#include "paletteCloud.h"

class softGrid {

public:
    void draw(ofRectangle frame_, float time_);
        
private:
    pushGrid pushGrid;
    
    triangleRoom triangleRoom;
    ellipseRoom ellipseRoom;
    
    paletteCloud myColorCloud;
};
