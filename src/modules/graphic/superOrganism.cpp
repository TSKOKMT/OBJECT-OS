#include "superOrganism.h"

//--------------------------------------------------------------
void superOrganism::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    vector<ofPoint> points;
    points.resize(7);
    for (int i = 0; i < points.size(); i++) {
        /*points[i].x = time * ofWrap(i * PI + PI * PI, -1, 1);
        points[i].x += i * i * PI + PI * PI;
        bool bInvert = floor(ofWrap(points[i].x, 0, 2)) == 1;
        points[i].x = ofWrap(points[i].x, 0, 1);
        if (bInvert) points[i].x = 1 - points[i].x;*/
        //points[i].x = ofNormalize(sin(time * TWO_PI * ofWrap(i * PI + PI * PI, -.5, .5)), -1, 1);
        points[i].x = ofNoise(time_ / 3., i * PI * 100);
        points[i].x = ofLerp(frame_.getLeft(), frame_.getRight(), points[i].x);
        
        /*points[i].y = time * ofWrap(i * PI * PI + PI, -1, 1);
        points[i].y += i * i * PI * PI + PI;
        bInvert = floor(ofWrap(points[i].y, 0, 2)) == 1;
        points[i].y = ofWrap(points[i].y, 0, 1);
        if (bInvert) points[i].y = 1 - points[i].y;*/
        //points[i].y = ofNormalize(sin(time * TWO_PI * ofWrap(i * PI * PI + PI, -.5, .5)), -1, 1);
        points[i].y = ofNoise(time_ / 3., (i * PI + PI) * 100);
        points[i].y = ofLerp(frame_.getTop(), frame_.getBottom(), points[i].y);
    }
    
    //DRAW
     
    /*ofSetColor(255);
    ofFill();
    for (int i = 0; i < points.size(); i++) {
        ofDrawCircle(points[i], 10);
    }*/
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    ofPushStyle();
    
    ofSetColor(myColorCloud.six[0]);
    
    //ofNoFill();
    ofBeginShape();
    for (int i = 0; i < 3; i++) {
        //ofSetColor(i % 2 == 0 ? 255 : 0);
        
        auto hullPoints = convexHull.getConvexHull(points);
        
        for (int i = 0; i < hullPoints.size(); i++) {
            //ofDrawCircle(points[i], 10);
            ofVertex(hullPoints[i]);
        }
        ofNextContour(true);
        
        fourthFilter::process(points);
    }
    ofEndShape(true);
    
    ofPopStyle();
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}
