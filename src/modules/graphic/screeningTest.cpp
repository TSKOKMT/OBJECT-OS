#include "screeningTest.h"

//--------------------------------------------------------------
void screeningTest::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    previousTime = time;
    time = time_;
    
    float unit = sqrt(frame_.width * frame_.height) / 120.;
    
    //Set angle
    float angle = PI / 4.;
    
    ofRectangle bigFrame = ofRectangle(0, 0, abs(cos(angle)) * frame_.width + abs(sin(angle)) * frame_.height, abs(sin(angle)) * frame_.width + abs(cos(angle)) * frame_.height);
    
    //Set width
    float width = ofMap(sin(time / 15. * TWO_PI), -1, 1, 1, 24) * unit;
    
    //Set position
    float speed = ofMap(sin(time / 12. * TWO_PI), -1, 1, 12, 240);
    position += speed * unit * (time - previousTime);
    position = ofWrap(position, bigFrame.getLeft() - width * 2, bigFrame.getLeft());
    
    //Generate voronoi
    vector<ofPoint> voronoiPoints;
    voronoiPoints.resize(4);
    for (int i = 0; i < voronoiPoints.size(); i++) {
        voronoiPoints[i].x = ofMap(ofNoise(time / 12., i * PI * 100), 0, 1, 0, frame_.width);
        voronoiPoints[i].y = ofMap(ofNoise(time / 12., (i * PI + PI) * 100), 0, 1, 0, frame_.height);
    }
    voronoi.clear();
    voronoi.setBounds(ofRectangle(0, 0, frame_.width, frame_.height));
    voronoi.setPoints(voronoiPoints);
    voronoi.generate();
    
    //DRAW
    
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    fbo.begin();
    ofClear(0);
    ofPushMatrix();
    ofTranslate(-frame_.position);
    
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    ofRotateRad(angle);
    ofTranslate(-bigFrame.getCenter());
    
    ofPushStyle();
    
    ofSetColor(myColorCloud.six[0]);
    
    for (float x = position; x < bigFrame.getRight(); x += width * 2) {
        ofDrawRectangle(x, bigFrame.y, width * .95, bigFrame.height);
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    
    /*ofFbo mask;
    mask.allocate(frame_.width, frame_.height, GL_RGBA, 4);
    mask.begin();
    
    for (int i = 0; i < voronoi.getCells().size(); i++) {
        if (i % 2 == 1) continue;
        ofBeginShape();
        for (int j = 0; j < voronoi.getCells()[i].pts.size(); j++) {
            ofVertex(voronoi.getCells()[i].pts[j]);
        }
        ofEndShape(true);
    }
    
    mask.end();
    
    ofFbo fbo1;
    fbo1.allocate(frame_.width, frame_.height, GL_RGB, 4);
    fbo1.begin();
    
    ofPushMatrix();
    ofTranslate(frame_.getCenter());
    ofRotateRad(-angle);
    ofTranslate(-bigFrame.getCenter());
    
    for (float x = position; x < bigFrame.getRight(); x += width * 2) {
        ofDrawRectangle(x, bigFrame.y, width * .95, bigFrame.height);
    }
    
    ofPopMatrix();
    
    fbo1.end();
    
    fbo1.getTexture().setAlphaMask(mask.getTexture());
    
    fbo1.draw(frame_.position);*/
    
    ofPopMatrix();
    fbo.end();
    fbo.draw(frame_.position);
}
