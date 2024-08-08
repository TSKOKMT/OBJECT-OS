#include "fourthParty.h"

//--------------------------------------------------------------
void fourthParty::get(ofPoint point01_, ofPoint point02_, ofPoint point03_, ofPoint &center_, float &radius_) {
    
    ofPoint mid01 = (point01_ + point02_) / 2.;
    ofPoint mid02 = (point02_ + point03_) / 2.;

    float slope01 = -1 / ((point02_.y - point01_.y) / (point02_.x - point01_.x));
    float slope02 = -1 / ((point03_.y - point02_.y) / (point03_.x - point02_.x));
    
    center_.x = (slope01 * mid01.x - slope02 * mid02.x + mid02.y - mid01.y) / (slope01 - slope02);
    center_.y = slope01 * (center_.x - mid01.x) + mid01.y;
    
    radius_ = ofDist(center_.x, center_.y, point01_.x, point01_.y);
}

//--------------------------------------------------------------
void fourthParty::get(vector<ofPoint> points_, ofPoint &center_, float &radius_) {
    
    get(points_[0], points_[1], points_[2], center_, radius_);
}
