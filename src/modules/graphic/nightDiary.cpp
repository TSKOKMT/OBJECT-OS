#include "nightDiary.h"

//--------------------------------------------------------------
void nightDiary::draw(ofRectangle frame_, float time_) {
    
    //UPDATE
    
    float unit = sqrt(frame_.getArea()) / 120.;
    
    //Generate voronoi
    vector<ofPoint> voronoiPoints;
    voronoiPoints.resize(count);
    for (int i = 0; i < voronoiPoints.size(); i++) {
        voronoiPoints[i].x = ofMap(ofNoise(time_ / hour, i * PI * 100), 0, 1, 0, frame_.width);
        voronoiPoints[i].y = ofMap(ofNoise(time_ / hour, (i * PI + PI) * 100), 0, 1, 0, frame_.height);
    }
    voronoi.clear();
    voronoi.setBounds(ofRectangle(0, 0, frame_.width, frame_.height));
    voronoi.setPoints(voronoiPoints);
    voronoi.generate();
    auto cells = voronoi.getCells();

    //Create vertextes
    int resolution = 120;
    vector<vector<ofPoint>> vertexes;
    for (int i = 0; i < cells.size(); i++) {
        //int resolution = (int)cells[i].pts.size();
        vertexes.push_back(vector<ofPoint>());
        for (int j = 0; j < resolution; j++) {
            float tj = ofMap(j, 0, resolution, 0, 1);
            vertexes.back().push_back(ofPoint());
            float devide = 0;
            for (int k = 0; k < cells[i].pts.size(); k++) {
                float tk = ofMap(k, 0, cells[i].pts.size(), 0, 1);
                float weight = abs(ofWrap((tj - tk) * 2, -1, 1));
                weight = pow(weight, power);
                if (bConvex) weight = 1 - weight;
                vertexes.back().back() += cells[i].pts[k] * weight;
                devide += weight;
            }
            vertexes.back().back() /= devide;
        }
    }
    
    //DRAW
    
    ofPushMatrix();
    ofTranslate(frame_.position);
    
    ofPushStyle();
    
    int ii = 0;
    for (int i = 0; i < vertexes.size(); i++) {
        if (i % 3 != 0) continue;
        
        ofSetColor(myColorCloud.six[ii % 6]);
        
        ofBeginShape();
        if (bCurve) {
            for (int j = 0; j < vertexes[i].size() + 3; j++) {
                int jn = ofWrap(j, 0, vertexes[i].size());
                ofCurveVertex(vertexes[i][jn]);
            }
        }
        else {
            for (int j = 0; j < vertexes[i].size(); j++) {
                ofVertex(vertexes[i][j]);
            }
        }
        ofEndShape(true);
        
        ii++;
    }
    
    ofPopStyle();

    /*for (int i = 0; i < points.size(); i++) {
        ofPushStyle();
        ofSetColor(255, 0, 0);
        ofDrawCircle(points[i], 10);
        ofPopStyle();
    }*/
    
    ofPopMatrix();
}
