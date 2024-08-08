#include "fourthFilter.h"

//--------------------------------------------------------------
void fourthFilter::process(vector<ofPoint>& points_) {
    
    vector<ofPoint> newPoints;
    for (int i = 0; i < points_.size(); i++) {
        ofPoint point01 = points_[i];
        ofPoint point02 = points_[(i + 1) % (int)points_.size()];
        ofPoint point03 = points_[(i + 2) % (int)points_.size()];
        
        ofPoint center;
        float radius;
        
        fourthParty::get(point01, point02, point03, center, radius);
        
        newPoints.push_back(center);
    }
    
    points_ = newPoints;
}
