#pragma once

#include "ofMain.h"

#include "tapMachine.h"

#include "interFace.h"

//screen
#include "vipGrid.h"
#include "slideGrid.h"
#include "pushGrid.h"
#include "emergeScreen.h"

//module
#include "badMode.h"
#include "andThen.h"
#include "bigDot.h"
#include "bigThree.h"
#include "bluBar.h"
#include "bluBlu.h"
#include "darlingApp.h"
#include "emergeMulti.h"
#include "everLasting.h"
#include "fallFree.h"
#include "flagCheck.h"
#include "superOrganism.h"
#include "objectOS.h"
#include "fragMent.h"
#include "goldenDisc.h"
#include "huntRabbit.h"
#include "icoIcon.h"
#include "keenPublic.h"
#include "keepDistance.h"
#include "kickBack.h"
#include "longDistance.h"
#include "madPile.h"
#include "moonShot.h"
#include "nightDiary.h"
#include "notionTation.h"
#include "nuWit.h"
#include "pointShoot.h"
#include "polyPoli.h"
#include "reCenter.h"
#include "screeningTest.h"
#include "shiftCycle.h"
#include "shopBot.h"
#include "spanningCole.h"
#include "superFlat.h"
#include "theyMove.h"
#include "togeToge.h"
#include "transScale.h"
#include "trickMe.h"
#include "tryAngle.h"
#include "twoBall.h"
#include "unbalanceLance.h"
#include "winterRoad.h"
#include "yoGreek.h"
#include "zoomZoom.h"
#include "softGrid.h"
#include "videoPlayer.h"

//typography
#include "alphaDelta.h"
#include "curvePara.h"
#include "deepVibe.h"
#include "digitalHybe.h"
#include "fieldWork.h"
#include "echoChamber.h"
#include "goingGone.h"
#include "graviTas.h"
#include "kuruKuri.h"
#include "longLonger.h"
#include "merryRound.h"
#include "moreGet.h"
#include "squareScape.h"
#include "quickBrown.h"
#include "rectAnd.h"
#include "slideLane.h"
#include "spaceBold.h"
#include "threeStep.h"
#include "wipVip.h"
#include "roundFace.h"
#include "blueCrown.h"
#include "diveWave.h"

//video
#include "videoCloud.h"

//word
#include "wordCloud.h"

//pixel
#include "boredomWindow.h"
#include "criticalWindow.h"
#include "fromDip.h"
#include "radioWindow.h"
#include "noizArc.h"
#include "rapFlee.h"
#include "rollingRoll.h"
#include "slitShut.h"
#include "synMeme.h"
#include "zigZig.h"

//palette
#include "colorCloud.h"

//chrome
#include "twoTone.h"
#include "colorWorld.h"

//cover
#include "flashCover.h"
#include "oddCover.h"
#include "pikaCover.h"
#include "blackCover.h"

class objectOS {

public:
    objectOS();
    
    void draw(ofRectangle frame_, float time_);
    
    float newTime_ = 0;
    
    int screenIndex = 0;
    int videoIndex = 0;
    int japaneseIndex = 0;
    int englishIndex = 0;
    int moduleIndex = 46;
    int paletteIndex = 0;
    int chromeIndex = 0;
    int pixelIndex = 0;
    int coverIndex = 0;
    
    int frameRate = -1;
    int paletteShift = 0;
    float screenDelay = 0;
    float paletteShiftTerm = -1;
    float wordShiftTerm = -1;
    
    tapMachine myTapMachine;
    
    interFace myInterFace;
    
    //word
    void previousWord();
    void nextWord();
    
    //module
    void previousGraphic();
    void nextGraphic();
    void previousTypography();
    void nextTypography();
    void previousVideo();
    void nextVideo();
    
    //color
    void setColorNothing();
    void setColorMono();
    void setColorRGBTwo();
    void setColorRGBWorld();
    void setColorSakamotoTwo();
    void setColorSakamotoWorld();
    void setColorIkkoTwo();
    void setColorIkkoWorld();
    
    //pixel
    void previousPixel();
    void nextPixel();
    
private:
    float previousTime = 0;
    
    //screen
    vipGrid myVipGrid;
    slideGrid mySlideGrid;
    pushGrid myPushGrid;
    emergeScreen myEmergeScreen;
    
    //module
    badMode myBadMode;
    andThen myAndThen;
    bigDot myBigDot;
    bigThree myBigThree;
    bluBar myBluBar;
    bluBlu myBluBlu;
    darlingApp myDarlingApp;
    emergeMulti myEmergeMulti;
    everLasting myEverLasting;
    fallFree myFallFree;
    flagCheck myFlagCheck;
    superOrganism mySuperOrganism;
    fragMent myFragMent;
    goldenDisc myGoldenDisc;
    huntRabbit myHuntRabbit;
    icoIcon myIcoIcon;
    keenPublic myKeenPublic;
    keepDistance myKeepDistance;
    kickBack myKickBack;
    longDistance myLongDistance;
    madPile myMadPile;
    moonShot myMoonShot;
    nightDiary myNightDiary;
    notionTation myNotionTation;
    nuWit myNuWit;
    pointShoot myPointShoot;
    polyPoli myPolyPoli;
    reCenter myReCenter;
    screeningTest myScreeningTest;
    shiftCycle myShiftCycle;
    shopBot myShopBot;
    spanningCole mySpanningCole;
    superFlat mySuperFlat;
    theyMove myTheyMove;
    togeToge myTogeToge;
    transScale myTransScale;
    trickMe myTrickMe;
    tryAngle myTryAngle;
    twoBall myTwoBall;
    unbalanceLance myUnbalanceLance;
    winterRoad myWinterRoad;
    yoGreek myYoGreek;
    zoomZoom myZoomZoom;
    softGrid mySoftGrid;
    videoPlayer myVideoPlayer;
    
    //typography
    alphaDelta myAlphaDelta;
    curvePara myCurvePara;
    deepVibe myDeepVibe;
    digitalHybe myDigitalHybe;
    fieldWork myFieldWork;
    echoChamber myEchoChamber;
    goingGone myGoingGone;
    graviTas myGraviTas;
    kuruKuri myKuruKuri;
    longLonger myLongLonger;
    merryRound myMerryRound;
    moreGet myMoreGet;
    squareScape mySquareScape;
    quickBrown myQuickBrown;
    rectAnd myRectAnd;
    slideLane mySlideLane;
    spaceBold mySpaceBold;
    threeStep myThreeStep;
    wipVip myWipVip;
    roundFace myRoundFace;
    blueCrown myBlueCrown;
    diveWave myDiveWave;
    
    //video
    videoCloud myVideoCloud;
    
    //word
    wordCloud myWordCloud;
    
    //palette
    colorCloud myColorCloud;
    
    //chrome
    twoTone myTwoTone;
    colorWorld myColorWorld;
    
    //pixel
    boredomWindow myBoredomWindow;
    criticalWindow myCriticalWindow;
    fromDip myFromDip;
    radioWindow myRadioWindow;
    noizArc myNoizArc;
    rapFlee myRapFlee;
    rollingRoll myRollingRoll;
    slitShut mySlitShut;
    synMeme mySynMeme;
    zigZig myZigZig;
    
    //cover
    flashCover myFlashCover;
    oddCover myOddCover;
    pikaCover myPikaCover;
    blackCover myBlackCover;
};
