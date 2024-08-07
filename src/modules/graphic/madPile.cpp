#include "madPile.h"

//--------------------------------------------------------------
madPile::madPile() {
    
}

//--------------------------------------------------------------
void madPile::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    float width_ = width * unit;
    
    ofPushMatrix();
    ofScale(0);
        
    auto points0 = everLasting.draw(frame_, time_);
    ofPolyline polyline0;
    for (int i = 0; i < points0.size(); i++) {
        polyline0.addVertex(frame_.getCenter() - ofPoint(0 * unit, 0) + points0[i]);
    }
    polyline0.close();
    
    auto points1 = everLasting.draw(frame_, time_ + 120.);
    ofPolyline polyline1;
    for (int i = 0; i < points1.size(); i++) {
        polyline1.addVertex(frame_.getCenter() + ofPoint(0 * unit, 0) + points1[i]);
    }
    polyline1.close();
    
    ofPopMatrix();
    
    vector<ofPolyline> newPoly;
    newPoly.resize(2);
    for (int i = 0; i < polyline0.size(); i++) {
        newPoly[0].addVertex(polyline0.getVertices()[i] * 100);
    }
    /*for (int i = 0; i < polyline1_.size(); i++) {
        newPoly[1].addVertex(polyline1_.getVertices()[i] * 10000);
    }*/
    
    //DRAW
    
    ofPushStyle();
    
    for (int i = 0; i < count_; i++) {
        float index = i + ofWrap(ofGetElapsedTimef() * 3, 0, 1);
        auto polyI = ofx::Clipper::getOffsets(newPoly, width_ * i * 100, ClipperLib::jtRound, ClipperLib::etClosedPolygon);
        auto polyO = ofx::Clipper::getOffsets(newPoly, width_ * (i + .2) * 100, ClipperLib::jtRound, ClipperLib::etClosedPolygon);
        
        ofSetColor(myColorCloud.six[i % 6]);
        
        for (int j = polyI.size() - 1; j >= 0; j--) {
            ofBeginShape();
            for (int k = 0; k < polyO[j].getVertices().size(); k++) {
                ofVertex(polyO[j].getVertices()[k] / 100.);
            }
            ofNextContour(true);
            for (int k = 0; k < polyI[j].getVertices().size(); k++) {
                ofVertex(polyI[j].getVertices()[k] / 100.);
            }
            ofEndShape(true);
        }
    }
    
    ofPopStyle();
}
