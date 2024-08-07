#include "objectOS.h"

//--------------------------------------------------------------
objectOS::objectOS() {
    
    setColorMono();
}

//--------------------------------------------------------------
void objectOS::draw(ofRectangle frame_, float time_) {
    
    newTime_ += (time_ - previousTime) * (myTapMachine.bpm / 60.);
    if (frameRate > 0) newTime_ = floor(newTime_ * frameRate) / (float)frameRate;
    
    previousTime = time_;
    
    if (paletteShiftTerm > 0) paletteShift = floor(newTime_ / paletteShiftTerm);
    
    if (wordShiftTerm > 0) {
        japaneseIndex = ofWrap(floor(newTime_ / wordShiftTerm), 0, myWordCloud.japanesePathes.size());
        englishIndex = ofWrap(floor(newTime_ / wordShiftTerm), 0, myWordCloud.englishes.size());
    }
    
    //Set screens
    vector<ofRectangle> screens;
    if (screenIndex == 0) screens.push_back(frame_);
    else if (screenIndex == 1) screens = myVipGrid.get(frame_, newTime_);
    else if (screenIndex == 2) screens = mySlideGrid.get(frame_, newTime_);
    else if (screenIndex == 3) screens = myPushGrid.get(frame_, newTime_);
    else screens = myEmergeScreen.get(frame_, newTime_);
    
    //Set video
    if (moduleIndex == 44) myVideoPlayer.load(myVideoCloud.pathes[videoIndex]);
    
    //Set japanese
    /*string japanesePath = myWordCloud.japanesePathes[japaneseIndex];
    if (moduleIndex == 45) myAlphaDelta.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 46) myBlueCrown.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 48) myDeepVibe.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 50) myDiveWave.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 51) myEchoChamber.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 53) myGoingGone.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 57) myMerryRound.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 58) myMoreGet.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 59) myQuickBrown.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 61) myRoundFace.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 62) mySlideLane.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 64) mySquareScape.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 65) myThreeStep.myPressRoom.setImage(japanesePath);
    if (moduleIndex == 66) myWipVip.myPressRoom.setImage(japanesePath);*/
    
    //Set english
    string englishWord = myWordCloud.englishes[englishIndex];
    if (moduleIndex == 45) myAlphaDelta.text_ = englishWord;
    if (moduleIndex == 46) myBlueCrown.text_ = englishWord;
    if (moduleIndex == 47) myCurvePara.text_ = englishWord;
    if (moduleIndex == 48) myDeepVibe.text_ = englishWord;
    if (moduleIndex == 49) myDigitalHybe.text_ = englishWord;
    if (moduleIndex == 50) myDiveWave.text_ = englishWord;
    if (moduleIndex == 51) myEchoChamber.text_ = englishWord;
    if (moduleIndex == 52) myFieldWork.text_ = englishWord;
    if (moduleIndex == 53) myGoingGone.text_ = englishWord;
    if (moduleIndex == 54) myGraviTas.text_ = englishWord;
    if (moduleIndex == 55) myKuruKuri.text_ = englishWord;
    if (moduleIndex == 56) myLongLonger.text_ = englishWord;
    if (moduleIndex == 56) myLongLonger.text_ = englishWord;
    if (moduleIndex == 57) myMerryRound.text_ = englishWord;
    if (moduleIndex == 58) myMoreGet.text_ = englishWord;
    if (moduleIndex == 59) myQuickBrown.text_ = englishWord;
    if (moduleIndex == 61) myRoundFace.text_ = englishWord;
    if (moduleIndex == 62) mySlideLane.text_ = englishWord;
    if (moduleIndex == 63) mySpaceBold.text_ = englishWord + " " + myWordCloud.englishes[(englishIndex + 1) % (int)myWordCloud.englishes.size()] + " " + myWordCloud.englishes[(englishIndex + 2) % (int)myWordCloud.englishes.size()];
    if (moduleIndex == 64) mySquareScape.text_ = englishWord;
    if (moduleIndex == 65) myThreeStep.text_ = englishWord;
    if (moduleIndex == 66) myWipVip.text_ = englishWord;
    
    //Create & begin fbo
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    
    //Draw module
    for (int i = 0; i < screens.size(); i++) {
        auto screen = screens[i];
        
        float newTime = newTime_ - i * screenDelay;
     
        //module
        if (moduleIndex == 0) myBadMode.draw(screen, newTime);
        if (moduleIndex == 1) myAndThen.draw(screen, newTime);
        if (moduleIndex == 2) myBigDot.draw(screen, newTime);
        if (moduleIndex == 3) myBigThree.draw(screen, newTime); //Update change
        if (moduleIndex == 4) myBluBar.draw(screen, newTime);
        if (moduleIndex == 5) myBluBlu.draw(screen, newTime);
        if (moduleIndex == 6) myDarlingApp.draw(screen, newTime); //heavy
        if (moduleIndex == 7) myEmergeMulti.draw(screen, newTime);
        if (moduleIndex == 8) myEverLasting.draw(screen, newTime);
        if (moduleIndex == 9) myFallFree.draw(screen, newTime);
        if (moduleIndex == 10) myFlagCheck.draw(screen, newTime);
        if (moduleIndex == 11) mySuperOrganism.draw(screen, newTime); //Crop or not
        if (moduleIndex == 12) myFragMent.draw(screen, newTime); //Too Update Frames
        if (moduleIndex == 13) myGoldenDisc.draw(screen, newTime);
        if (moduleIndex == 14) myHuntRabbit.draw(screen, newTime);
        if (moduleIndex == 15) myIcoIcon.draw(screen, newTime);
        if (moduleIndex == 16) myKeenPublic.draw(screen, newTime);
        if (moduleIndex == 17) myKeepDistance.draw(screen, newTime);
        if (moduleIndex == 18) myKickBack.draw(screen, newTime);
        if (moduleIndex == 19) myLongDistance.draw(screen, newTime); //On demand please
        if (moduleIndex == 20) myMadPile.draw(screen, newTime); //fall off when push grid
        if (moduleIndex == 21) myMoonShot.draw(screen, newTime);
        if (moduleIndex == 22) myNightDiary.draw(screen, newTime);
        if (moduleIndex == 23) myNotionTation.draw(screen, newTime); //Update change
        if (moduleIndex == 24) myNuWit.draw(screen, newTime);
        if (moduleIndex == 25) myPointShoot.draw(screen, newTime);
        if (moduleIndex == 26) myPolyPoli.draw(screen, newTime);
        if (moduleIndex == 27) myReCenter.draw(screen, newTime);
        if (moduleIndex == 28) myScreeningTest.draw(screen, newTime);
        if (moduleIndex == 29) myShiftCycle.draw(screen, newTime); //Change update
        if (moduleIndex == 30) myShopBot.draw(screen, newTime);
        if (moduleIndex == 31) mySpanningCole.draw(screen, newTime);
        if (moduleIndex == 32) mySuperFlat.draw(screen, newTime);
        if (moduleIndex == 33) myTheyMove.draw(screen, newTime);
        if (moduleIndex == 34) myTogeToge.draw(screen, newTime);
        if (moduleIndex == 35) myTransScale.draw(screen, newTime);
        if (moduleIndex == 36) myTrickMe.draw(screen, newTime); //too update
        if (moduleIndex == 37) myTryAngle.draw(screen, newTime);
        if (moduleIndex == 38) myTwoBall.draw(screen, newTime);
        if (moduleIndex == 39) myUnbalanceLance.draw(screen, newTime);
        if (moduleIndex == 40) myWinterRoad.draw(screen, newTime);
        if (moduleIndex == 41) myYoGreek.draw(screen, newTime);
        if (moduleIndex == 42) myZoomZoom.draw(screen, newTime);
        if (moduleIndex == 43) mySoftGrid.draw(screen, newTime);
        
        //video
        if (moduleIndex == 44) myVideoPlayer.draw(screen, newTime);
        
        //typography
        if (moduleIndex == 45) myAlphaDelta.draw(screen, newTime);
        if (moduleIndex == 46) myBlueCrown.draw(screen, newTime);
        if (moduleIndex == 47) myCurvePara.draw(screen, newTime);
        if (moduleIndex == 48) myDeepVibe.draw(screen, newTime); //Little heavy
        if (moduleIndex == 49) myDigitalHybe.draw(screen, newTime); //Change begin algo
        if (moduleIndex == 50) myDiveWave.draw(screen, newTime);
        if (moduleIndex == 51) myEchoChamber.draw(screen, newTime);
        if (moduleIndex == 52) myFieldWork.draw(screen, newTime); //Heavy. maybe this is screen?
        if (moduleIndex == 53) myGoingGone.draw(screen, newTime); //Heavy
        if (moduleIndex == 54) myGraviTas.draw(screen, newTime);
        if (moduleIndex == 55) myKuruKuri.draw(screen, newTime);
        if (moduleIndex == 56) myLongLonger.draw(screen, newTime);
        if (moduleIndex == 57) myMerryRound.draw(screen, newTime);
        if (moduleIndex == 58) myMoreGet.draw(screen, newTime); //Crop or not?
        if (moduleIndex == 59) myQuickBrown.draw(screen, newTime);
        if (moduleIndex == 60) myRectAnd.draw(screen, newTime); //What is this
        if (moduleIndex == 61) myRoundFace.draw(screen, newTime);
        if (moduleIndex == 62) mySlideLane.draw(screen, newTime); //maybe this is screen?
        if (moduleIndex == 63) mySpaceBold.draw(screen, newTime);
        if (moduleIndex == 64) mySquareScape.draw(screen, newTime);
        if (moduleIndex == 65) myThreeStep.draw(screen, newTime);
        if (moduleIndex == 66) myWipVip.draw(screen, newTime);
    }
    
    fbo.end();
    
    //palette
    vector<ofColor> palette;
    if (paletteIndex == 0) palette = myColorCloud.mono;
    else if (paletteIndex == 1) palette = myColorCloud.rgb;
    else if (paletteIndex == 2) palette = myColorCloud.six;
    else if (paletteIndex == 3) palette = myColorCloud.sakamoto;
    else palette = myColorCloud.ikko;
    
    auto paletteShelter = palette;
    for (int i = 0; i < palette.size(); i++) {
        palette[i] = paletteShelter[ofWrap(i + paletteShift, 0, (int)palette.size())];
    }

    //chrome
    ofFbo fboC;
    fboC.allocate(frame_.width, frame_.height, GL_RGB, 4);
    fboC.begin();
    ofClear(0);
    if (chromeIndex == 0) {
        fbo.draw(0, 0);
    }
    else if (chromeIndex == 1) {
        myTwoTone.color0 = palette[0];
        myTwoTone.color1 = palette[1];
        myTwoTone.draw(fbo.getTexture());
    }
    else {
        myColorWorld.palette = palette;
        myColorWorld.draw(fbo.getTexture());
    }
    fboC.end();
    
    //pixel
    if (pixelIndex == 0) fboC.draw(0, 0);
    else if (pixelIndex == 1) myBoredomWindow.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 2) myCriticalWindow.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 3) myFromDip.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 4) myRadioWindow.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 5) myNoizArc.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 6) myRapFlee.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 7) myRollingRoll.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 8) mySlitShut.draw(fboC.getTexture(), newTime_);
    else if (pixelIndex == 9) mySynMeme.draw(fboC.getTexture(), newTime_);
    else myZigZig.draw(fboC.getTexture(), newTime_);
    
    //cover
    if (coverIndex == 0) {}
    else if (coverIndex == 1) myFlashCover.draw(frame_, newTime_);
    else if (coverIndex == 2) myOddCover.draw(frame_, newTime_);
    else if (coverIndex == 3) myPikaCover.draw(frame_, newTime_);
    else if (coverIndex == 4) myBlackCover.draw(frame_, newTime_);
}

//--------------------------------------------------------------
void objectOS::previousWord() {
    
    japaneseIndex = ofWrap(japaneseIndex - 1, 0, myWordCloud.japanesePathes.size());
    englishIndex = ofWrap(englishIndex - 1, 0, myWordCloud.englishes.size());
}
//--------------------------------------------------------------
void objectOS::nextWord() {
    
    japaneseIndex = ofWrap(japaneseIndex + 1, 0, myWordCloud.japanesePathes.size());
    englishIndex = ofWrap(englishIndex + 1, 0, myWordCloud.englishes.size());
}

//--------------------------------------------------------------
void objectOS::previousGraphic() {
    
    if (0 <= moduleIndex && moduleIndex < 44) moduleIndex = ofWrap(moduleIndex - 1, 0, 44);
    else moduleIndex = 43;
}
//--------------------------------------------------------------
void objectOS::nextGraphic() {
    
    if (0 <= moduleIndex && moduleIndex < 44) moduleIndex = ofWrap(moduleIndex + 1, 0, 44);
    else moduleIndex = 0;
}
//--------------------------------------------------------------
void objectOS::previousTypography() {
    
    if (45 <= moduleIndex && moduleIndex < 67) moduleIndex = ofWrap(moduleIndex - 1, 45, 67);
    else moduleIndex = 66;
}
//--------------------------------------------------------------
void objectOS::nextTypography() {
    
    if (45 <= moduleIndex && moduleIndex < 67) moduleIndex = ofWrap(moduleIndex + 1, 45, 67);
    else moduleIndex = 45;
}
//--------------------------------------------------------------
void objectOS::previousVideo() {
    
    moduleIndex = 44;
    videoIndex = ofWrap(videoIndex - 1, 0, myVideoCloud.pathes.size());
}
//--------------------------------------------------------------
void objectOS::nextVideo() {
    
    moduleIndex = 44;
    videoIndex = ofWrap(videoIndex + 1, 0, myVideoCloud.pathes.size());
}

//--------------------------------------------------------------
void objectOS::setColorNothing() {
    
    paletteIndex = 0;
    chromeIndex = 0;
}
//--------------------------------------------------------------
void objectOS::setColorMono() {
    
    paletteIndex = 0;
    chromeIndex = 1;
}
//--------------------------------------------------------------
void objectOS::setColorRGBTwo() {
    
    paletteIndex = 1;
    chromeIndex = 1;
}
//--------------------------------------------------------------
void objectOS::setColorRGBWorld() {
    
    paletteIndex = 1;
    chromeIndex = 2;
}
//--------------------------------------------------------------
void objectOS::setColorSakamotoTwo() {
    
    paletteIndex = 3;
    chromeIndex = 1;
}
//--------------------------------------------------------------
void objectOS::setColorSakamotoWorld() {
    
    paletteIndex = 3;
    chromeIndex = 2;
}
//--------------------------------------------------------------
void objectOS::setColorIkkoTwo() {
    
    paletteIndex = 4;
    chromeIndex = 1;
}
//--------------------------------------------------------------
void objectOS::setColorIkkoWorld() {
    
    paletteIndex = 4;
    chromeIndex = 2;
}

//--------------------------------------------------------------
void objectOS::previousPixel() {
    
    cout << ofGetFrameNum() << " : " << ofGetElapsedTimef() << endl;
    
    pixelIndex = ofWrap(pixelIndex - 1, 1, 11);
}
//--------------------------------------------------------------
void objectOS::nextPixel() {
    
    pixelIndex = ofWrap(pixelIndex + 1, 1, 11);
}
