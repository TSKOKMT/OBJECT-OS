#include "objectOS.h"

//--------------------------------------------------------------
objectOS::objectOS() {
    
    setColorMono();
}

//--------------------------------------------------------------
void objectOS::draw(ofRectangle frame_, float time_) {
    
    //Update time
    newTime_ += (time_ - previousTime) * (myTapMachine.bpm / 60.);
    if (frameRate > 0) newTime_ = floor(newTime_ * frameRate) / (float)frameRate;
    previousTime = time_;
    
    //Update video
    if (visualIndex == graphicCount + typographyCount) myWatchMovie.load(myVideoCloud.pathes[videoIndex]);
    
    //Update word
    if (wordShiftTerm > 0) {
        japaneseIndex = ofWrap(floor(newTime_ / wordShiftTerm), 0, myWordCloud.japanesePathes.size());
        englishIndex = ofWrap(floor(newTime_ / wordShiftTerm), 0, myWordCloud.englishes.size());
    }
    
    //Update palette
    //Get
    vector<ofColor> palette;
    if (paletteIndex == 0) palette = myPaletteCloud.mono;
    else if (paletteIndex == 1) palette = myPaletteCloud.rgb;
    else if (paletteIndex == 2) palette = myPaletteCloud.six;
    else if (paletteIndex == 3) palette = myPaletteCloud.sakamoto;
    else palette = myPaletteCloud.ikko;
    //Shift
    if (paletteShiftTerm > 0) colorIndex = floor(newTime_ / paletteShiftTerm);
    auto paletteShelter = palette;
    for (int i = 0; i < palette.size(); i++) palette[i] = paletteShelter[ofWrap(i + colorIndex, 0, (int)palette.size())];
    
    //Set screens
    vector<ofRectangle> screens;
    if (screenIndex == 0) screens.push_back(frame_);
    else if (screenIndex == 1) screens = myVipGrid.get(frame_, newTime_);
    else if (screenIndex == 2) screens = mySlideGrid.get(frame_, newTime_);
    else if (screenIndex == 3) screens = myPushGrid.get(frame_, newTime_);
    else screens = myEmergeScreen.get(frame_, newTime_);
    
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
    string englishWord2 = myWordCloud.englishes[(englishIndex + 1) % (int)myWordCloud.englishes.size()];
    string englishWord3 = myWordCloud.englishes[(englishIndex + 2) % (int)myWordCloud.englishes.size()];
    if (visualIndex == graphicCount + 0) myAlphaDelta.text_ = englishWord;
    if (visualIndex == graphicCount + 1) myBlueCrown.text_ = englishWord;
    if (visualIndex == graphicCount + 2) myCurvePara.text_ = englishWord;
    if (visualIndex == graphicCount + 3) myDeepVibe.text_ = englishWord;
    if (visualIndex == graphicCount + 4) myDiveWave.text_ = englishWord;
    if (visualIndex == graphicCount + 5) myDigitalHybe.text_ = englishWord;
    if (visualIndex == graphicCount + 6) myEchoChamber.text_ = englishWord;
    if (visualIndex == graphicCount + 7) myFieldWork.text_ = englishWord;
    if (visualIndex == graphicCount + 8) myGoingGone.text_ = englishWord;
    if (visualIndex == graphicCount + 9) myGraviTas.text_ = englishWord;
    if (visualIndex == graphicCount + 10) myKuruKuri.text_ = englishWord;
    if (visualIndex == graphicCount + 11) myLongLonger.text_ = englishWord;
    if (visualIndex == graphicCount + 12) myMerryRound.text_ = englishWord;
    if (visualIndex == graphicCount + 13) myMoreGet.text_ = englishWord;
    if (visualIndex == graphicCount + 14) myQuickBrown.text_ = englishWord;
    if (visualIndex == graphicCount + 15) myRectAnd.text_ = englishWord;
    if (visualIndex == graphicCount + 16) myRoundFace.text_ = englishWord;
    if (visualIndex == graphicCount + 17) mySlideLane.text_ = englishWord;
    if (visualIndex == graphicCount + 18) mySpaceBold.text_ = englishWord + " " + englishWord2 + " " + englishWord3;;
    if (visualIndex == graphicCount + 19) mySquareScape.text_ = englishWord;
    if (visualIndex == graphicCount + 20) myThreeStep.text_ = englishWord;
    if (visualIndex == graphicCount + 21) myWipVip.text_ = englishWord;
    
    //Create & begin fbo
    ofFbo fbo;
    fbo.allocate(frame_.width, frame_.height, GL_RGB, 4);
    fbo.begin();
    ofClear(0);
    
    //Draw module
    for (int i = 0; i < screens.size(); i++) {
        auto screen = screens[i];
        
        float newTime = newTime_ - i * screenDelay;
     
        //visual
        //graphic
        if (visualIndex == 0) myAndThen.draw(screen, newTime);
        if (visualIndex == 1) myBadMode.draw(screen, newTime);
        if (visualIndex == 2) myBigDot.draw(screen, newTime);
        if (visualIndex == 3) myBigThree.draw(screen, newTime); //Update change
        if (visualIndex == 4) myBluBar.draw(screen, newTime);
        if (visualIndex == 5) myBluBlu.draw(screen, newTime);
        if (visualIndex == 6) myDarlingApp.draw(screen, newTime); //heavy
        if (visualIndex == 7) myEmergeMulti.draw(screen, newTime);
        if (visualIndex == 8) myEverLasting.draw(screen, newTime);
        if (visualIndex == 9) myFallFree.draw(screen, newTime);
        if (visualIndex == 10) myFlagCheck.draw(screen, newTime);
        if (visualIndex == 11) myFragMent.draw(screen, newTime); //Too Update Frames
        if (visualIndex == 12) myGoldenDisc.draw(screen, newTime);
        if (visualIndex == 13) myHuntRabbit.draw(screen, newTime);
        if (visualIndex == 14) myIcoIcon.draw(screen, newTime);
        if (visualIndex == 15) myKeenPublic.draw(screen, newTime);
        if (visualIndex == 16) myKeepDistance.draw(screen, newTime);
        if (visualIndex == 17) myKickBack.draw(screen, newTime);
        if (visualIndex == 18) myLongDistance.draw(screen, newTime); //On demand please
        if (visualIndex == 19) myMadPile.draw(screen, newTime);
        if (visualIndex == 20) myMoonShot.draw(screen, newTime); //fall off when push grid
        if (visualIndex == 21) myNightDiary.draw(screen, newTime);
        if (visualIndex == 22) myNotionTation.draw(screen, newTime); //Update change
        if (visualIndex == 23) myNuWit.draw(screen, newTime);
        if (visualIndex == 24) myPointShoot.draw(screen, newTime);
        if (visualIndex == 25) myPolyPoli.draw(screen, newTime);
        if (visualIndex == 26) myReCenter.draw(screen, newTime);
        if (visualIndex == 27) myScreeningTest.draw(screen, newTime);
        if (visualIndex == 28) myShiftCycle.draw(screen, newTime); //Change update
        if (visualIndex == 29) myShopBot.draw(screen, newTime);
        if (visualIndex == 30) mySoftGrid.draw(screen, newTime);
        if (visualIndex == 31) mySpanningCole.draw(screen, newTime);
        if (visualIndex == 32) mySuperFlat.draw(screen, newTime);
        if (visualIndex == 33) mySuperOrganism.draw(screen, newTime); //Crop or not
        if (visualIndex == 34) myTheyMove.draw(screen, newTime);
        if (visualIndex == 35) myTogeToge.draw(screen, newTime);
        if (visualIndex == 36) myTransScale.draw(screen, newTime);
        if (visualIndex == 37) myTrickMe.draw(screen, newTime); //too update
        if (visualIndex == 38) myTryAngle.draw(screen, newTime);
        if (visualIndex == 39) myTwoBall.draw(screen, newTime);
        if (visualIndex == 40) myUnbalanceLance.draw(screen, newTime);
        if (visualIndex == 41) myWinterRoad.draw(screen, newTime);
        if (visualIndex == 42) myYoGreek.draw(screen, newTime);
        if (visualIndex == 43) myZoomZoom.draw(screen, newTime);
        //typography
        if (visualIndex == graphicCount + 0) myAlphaDelta.draw(screen, newTime);
        if (visualIndex == graphicCount + 1) myBlueCrown.draw(screen, newTime);
        if (visualIndex == graphicCount + 2) myCurvePara.draw(screen, newTime);
        if (visualIndex == graphicCount + 3) myDeepVibe.draw(screen, newTime); //Little heavy
        if (visualIndex == graphicCount + 4) myDigitalHybe.draw(screen, newTime); //Change begin algo
        if (visualIndex == graphicCount + 5) myDiveWave.draw(screen, newTime);
        if (visualIndex == graphicCount + 6) myEchoChamber.draw(screen, newTime);
        if (visualIndex == graphicCount + 7) myFieldWork.draw(screen, newTime); //Heavy. maybe this is screen?
        if (visualIndex == graphicCount + 8) myGoingGone.draw(screen, newTime); //Heavy
        if (visualIndex == graphicCount + 9) myGraviTas.draw(screen, newTime);
        if (visualIndex == graphicCount + 10) myKuruKuri.draw(screen, newTime);
        if (visualIndex == graphicCount + 11) myLongLonger.draw(screen, newTime);
        if (visualIndex == graphicCount + 12) myMerryRound.draw(screen, newTime);
        if (visualIndex == graphicCount + 13) myMoreGet.draw(screen, newTime); //Crop or not?
        if (visualIndex == graphicCount + 14) myQuickBrown.draw(screen, newTime);
        if (visualIndex == graphicCount + 15) myRectAnd.draw(screen, newTime); //What is this
        if (visualIndex == graphicCount + 16) myRoundFace.draw(screen, newTime);
        if (visualIndex == graphicCount + 17) mySlideLane.draw(screen, newTime); //maybe this is screen?
        if (visualIndex == graphicCount + 18) mySpaceBold.draw(screen, newTime);
        if (visualIndex == graphicCount + 19) mySquareScape.draw(screen, newTime);
        if (visualIndex == graphicCount + 20) myThreeStep.draw(screen, newTime);
        if (visualIndex == graphicCount + 21) myWipVip.draw(screen, newTime);
        //video
        if (visualIndex == graphicCount + typographyCount) myWatchMovie.draw(screen, newTime);
    }
    
    fbo.end();

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
void objectOS::previousScreen() {
    
    screenIndex = ofWrap(screenIndex - 1, 0, screenCount);
}
//--------------------------------------------------------------
void objectOS::nextScreen() {
    
    screenIndex = ofWrap(screenIndex + 1, 0, screenCount);
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
    
    if (0 <= visualIndex && visualIndex < graphicCount) visualIndex = ofWrap(visualIndex - 1, 0, graphicCount);
    else visualIndex = graphicCount - 1;
}
//--------------------------------------------------------------
void objectOS::nextGraphic() {
    
    if (0 <= visualIndex && visualIndex < graphicCount) visualIndex = ofWrap(visualIndex + 1, 0, graphicCount);
    else visualIndex = 0;
}
//--------------------------------------------------------------
void objectOS::previousTypography() {
    
    if (graphicCount <= visualIndex && visualIndex < graphicCount + typographyCount) visualIndex = ofWrap(visualIndex - 1, graphicCount, graphicCount + typographyCount);
    else visualIndex = graphicCount + typographyCount - 1;
}
//--------------------------------------------------------------
void objectOS::nextTypography() {
    
    if (graphicCount <= visualIndex && visualIndex < graphicCount + typographyCount) visualIndex = ofWrap(visualIndex + 1, graphicCount, graphicCount + typographyCount);
    else visualIndex = graphicCount;
}
//--------------------------------------------------------------
void objectOS::previousVideo() {
    
    visualIndex = graphicCount + typographyCount;
    videoIndex = ofWrap(videoIndex - 1, 0, myVideoCloud.pathes.size());
}
//--------------------------------------------------------------
void objectOS::nextVideo() {
    
    visualIndex = graphicCount + typographyCount;
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
    
    pixelIndex = ofWrap(pixelIndex - 1, 0, pixelCount);
}
//--------------------------------------------------------------
void objectOS::nextPixel() {
    
    pixelIndex = ofWrap(pixelIndex + 1, 0, pixelCount);
}

//--------------------------------------------------------------
void objectOS::previousCover() {
    
    coverIndex = ofWrap(coverIndex - 1, 0, coverCount);
}
//--------------------------------------------------------------
void objectOS::nextCover() {
    
    coverIndex = ofWrap(coverIndex + 1, 0, coverCount);
}
