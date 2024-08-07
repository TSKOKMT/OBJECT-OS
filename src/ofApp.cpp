#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //ofSetWindowShape(ofGetScreenWidth() * (16 / 18.), ofGetScreenWidth() / 2.);
    ofSetWindowShape(1920, 1080);
    ofSetWindowPosition((ofGetScreenWidth() - ofGetWidth()) / 2., (ofGetScreenHeight() - ofGetHeight()) / 2.);
    ofBackground(0);
    ofSetCircleResolution(60);
    ofSetLineWidth(4);
    ofSetCylinderResolution(30, 1);
    
    server.setName("OBJECT OS Server");
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetWindowTitle("OBJECT OS | FPS " + ofToString(round(ofGetFrameRate())) + " | BPM " + ofToString(myObjectOS.myTapMachine.bpm) + " | newTime " + ofToString(myObjectOS.newTime_));
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    auto frame = ofGetWindowRect();
    
    auto time = ofGetElapsedTimef();
    
    auto unit = sqrt(frame.width * frame.height) / 120.;
    
    myObjectOS.draw(frame, time);
    
    server.publishScreen();
    
    auto pads = myObjectOS.myInterFace.getPads();
    
    //pad
    
    //screen
    if (pads[0][0] > 0) myObjectOS.screenIndex = 0;
    if (pads[0][1] > 0) myObjectOS.screenIndex = 1;
    if (pads[0][2] > 0) myObjectOS.screenIndex = 2;
    if (pads[0][3] > 0) myObjectOS.screenIndex = 3;
    if (pads[0][4] > 0) myObjectOS.screenIndex = 4;
    
    //word
    if (pads[1][0] > 0) myObjectOS.previousWord();
    if (pads[1][1] > 0) myObjectOS.nextWord();
    if (pads[1][2] > 0) myObjectOS.wordShiftTerm = -1;
    if (pads[1][3] > 0) myObjectOS.wordShiftTerm = 1 / 8.;
    if (pads[1][4] > 0) myObjectOS.wordShiftTerm = 1;
    if (pads[1][5] > 0) myObjectOS.wordShiftTerm = 4;
    
    //module
    if (pads[2][0] > 0) myObjectOS.previousGraphic();
    if (pads[2][1] > 0) myObjectOS.nextGraphic();
    if (pads[2][2] > 0) myObjectOS.previousTypography();
    if (pads[2][3] > 0) myObjectOS.nextTypography();
    if (pads[2][4] > 0) myObjectOS.previousVideo();
    if (pads[2][5] > 0) myObjectOS.nextVideo();
    
    //color
    if (pads[3][0] > 0) myObjectOS.setColorNothing();
    if (pads[3][1] > 0) myObjectOS.setColorMono();
    if (pads[3][2] > 0) myObjectOS.setColorRGBTwo();
    if (pads[3][3] > 0) myObjectOS.setColorRGBWorld();
    if (pads[3][4] > 0) myObjectOS.setColorSakamotoTwo();
    if (pads[3][5] > 0) myObjectOS.setColorSakamotoWorld();
    if (pads[3][6] > 0) myObjectOS.setColorIkkoTwo();
    if (pads[3][7] > 0) myObjectOS.setColorIkkoWorld();
    if (pads[4][3] > 0) myObjectOS.paletteShift++;
    if (pads[4][4] > 0) myObjectOS.paletteShiftTerm = -1;
    if (pads[4][5] > 0) myObjectOS.paletteShiftTerm = 1 / 8.;
    if (pads[4][6] > 0) myObjectOS.paletteShiftTerm = 1;
    if (pads[4][7] > 0) myObjectOS.paletteShiftTerm = 4;
    
    //pixel
    if (pads[5][0] > 0) myObjectOS.pixelIndex = 0;
    if (pads[5][1] > 0) myObjectOS.previousPixel();
    if (pads[5][2] > 0) myObjectOS.nextPixel();
    
    //cover
    if (pads[6][0] > 0) myObjectOS.coverIndex = 0;
    if (pads[6][1] > 0) myObjectOS.coverIndex = 1;
    if (pads[6][2] > 0) myObjectOS.coverIndex = 2;
    if (pads[6][3] > 0) myObjectOS.coverIndex = 3;
    if (pads[6][4] > 0) myObjectOS.coverIndex = 4;
    
    //tap
    if (pads[7][7] > 0) {
        if (!myObjectOS.myTapMachine.bTapping) myObjectOS.newTime_ = 0;
        myObjectOS.myTapMachine.tap();
    }
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ') {
        myObjectOS.newTime_ = 0;
        myObjectOS.myTapMachine.tap();
    }
    
    if (key == OF_KEY_RIGHT) myObjectOS.moduleIndex = ofWrap(myObjectOS.moduleIndex + 1, 0, 67);
    if (key == OF_KEY_LEFT) myObjectOS.moduleIndex = ofWrap(myObjectOS.moduleIndex - 1, 0, 67);
    
    if (key == OF_KEY_UP) myObjectOS.screenIndex = ofWrap(myObjectOS.screenIndex + 1, 0, 5);
    if (key == OF_KEY_DOWN) myObjectOS.screenIndex = ofWrap(myObjectOS.screenIndex - 1, 0, 5);
    
    if (key == 'a') myObjectOS.chromeIndex = ofWrap(myObjectOS.chromeIndex + 1, 0, 3);
    if (key == 'd') myObjectOS.chromeIndex = ofWrap(myObjectOS.chromeIndex - 1, 0, 3);
    
    if (key == 's') myObjectOS.pixelIndex = ofWrap(myObjectOS.pixelIndex + 1, 0, 12);
    if (key == 'w') myObjectOS.pixelIndex = ofWrap(myObjectOS.pixelIndex - 1, 0, 12);
    
    if (key == 'l') myObjectOS.paletteIndex = ofWrap(myObjectOS.paletteIndex + 1, 0, 5);
    if (key == 'k') myObjectOS.paletteIndex = ofWrap(myObjectOS.paletteIndex - 1, 0, 5);
    
    if (key == 'p') myObjectOS.paletteShift++;
    if (key == 'o') myObjectOS.paletteShift--;
    
    if (key == 'm') myObjectOS.coverIndex = ofWrap(myObjectOS.coverIndex + 1, 0, 4);
    if (key == 'n') myObjectOS.coverIndex = ofWrap(myObjectOS.coverIndex - 1, 0, 4);
    
    if (key == 'x') myObjectOS.nextWord();
    if (key == 'z') myObjectOS.previousWord();
    
    if (key == '.') myObjectOS.videoIndex = ofWrap(myObjectOS.videoIndex + 1, 0, 21);
    if (key == ',') myObjectOS.videoIndex = ofWrap(myObjectOS.videoIndex - 1, 0, 21);
    
    if (key == '1') myObjectOS.setColorMono();
    if (key == '2') myObjectOS.setColorRGBTwo();
    if (key == '3') myObjectOS.setColorRGBWorld();
    if (key == '4') myObjectOS.setColorSakamotoTwo();
    if (key == '5') myObjectOS.setColorSakamotoWorld();
    if (key == '6') myObjectOS.setColorIkkoTwo();
    if (key == '7') myObjectOS.setColorIkkoWorld();
    
    if (key == '9') myObjectOS.paletteShiftTerm = 1;
    if (key == '0') myObjectOS.paletteShiftTerm = -1;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
