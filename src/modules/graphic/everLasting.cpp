#include "everLasting.h"

//--------------------------------------------------------------
vector<ofPoint> everLasting::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    ofRectangle frame = frame_;
    
    float time = time_;
    
    float unit = sqrt(frame.width * frame.height) / 120.;
    
    //Generate voronoi
    vector<ofPoint> points;
    points.resize(12);
    for (int i = 0; i < points.size(); i++) {
        points[i].x = ofMap(ofNoise(time / 12., i * PI * 100), 0, 1, frame.getLeft(), frame.getRight());
        points[i].y = ofMap(ofNoise(time / 12., (i * PI + PI) * 100), 0, 1, frame.getTop(), frame.getBottom());
    }
    voronoi.setBounds(frame);
    voronoi.setPoints(points);
    voronoi.generate();
    
    //Make poly
    vector<ofPoint> thePoints = voronoi.getCells()[0].pts;
    ofPolyline poly;
    for (int i = 0; i < thePoints.size(); i++) poly.addVertex(thePoints[i]);
    poly.close();
    for (int i = 0; i < thePoints.size(); i++) {
        thePoints[i] -= poly.getCentroid2D();
        thePoints[i] *= (targetSize_ * unit) / sqrt(poly.getArea());
    }
    
    //DRAW
    
    //Draw shape
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    
    ofPushStyle();
    
    ofSetColor(myColorCloud.six[0]);
    
    ofBeginShape();
    for (int i = 0; i < thePoints.size(); i++) {
        ofVertex(thePoints[i]);
    }
    ofEndShape();
    
    ofPopStyle();
    
    ofPopMatrix();
    
    //Return points;
    vector<ofPoint> newPoints;
    for (int i = 0; i < thePoints.size(); i++) {
        newPoints.push_back(thePoints[i]);
        int index0 = ofWrap(i, 0, thePoints.size());
        int index1 = ofWrap(i + 1, 0, thePoints.size());
        float weight = ofNormalize(thePoints[index0].distance(thePoints[index1]), 0, targetSize_ * unit);
        weight = pow(weight, 7);
        weight = ofLerp(2, 12, weight);
        newPoints.push_back((thePoints[index0] + thePoints[index1]) / weight);
    }
    
    return newPoints;
}
