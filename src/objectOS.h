#pragma once

#include "ofMain.h"

#include "tapMachine.h"

#include "interFace.h"

//video
#include "videoCloud.h"

//word
#include "wordCloud.h"

//palette
#include "paletteCloud.h"

//screen
#include "vipGrid.h"
#include "slideGrid.h"
#include "pushGrid.h"
#include "emergeScreen.h"

//visual
//graphic
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
//movie
#include "watchMovie.h"

//chrome
#include "twoTone.h"
#include "colorWorld.h"

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
    
    int frameRate = -1;
    
    int videoIndex = 0;
    int japaneseIndex = 0;
    int englishIndex = 0;
    int paletteIndex = 0;
    int colorIndex = 0;
    int screenIndex = 0;
    int visualIndex = 0;
    int chromeIndex = 0;
    int pixelIndex = 0;
    int coverIndex = 0;
    
    float screenDelay = 0;
    
    float wordShiftTerm = -1;
    
    float paletteShiftTerm = -1;
    
    //screen
    void previousScreen();
    void nextScreen();
    
    //word
    void previousWord();
    void nextWord();
    
    //visual
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
    
    //cover
    void previousCover();
    void nextCover();
    
    tapMachine myTapMachine;
    
    interFace myInterFace;
    
private:
    float previousTime = 0;
    
    //video
    videoCloud myVideoCloud;
    
    //word
    wordCloud myWordCloud;
    
    //palette
    paletteCloud myPaletteCloud;
    
    //screen
    vipGrid myVipGrid;
    slideGrid mySlideGrid;
    pushGrid myPushGrid;
    emergeScreen myEmergeScreen;
    int screenCount = 5;
    
    //visual
    //graphic
    andThen myAndThen;
    badMode myBadMode;
    bigDot myBigDot;
    bigThree myBigThree;
    bluBar myBluBar;
    bluBlu myBluBlu;
    darlingApp myDarlingApp;
    emergeMulti myEmergeMulti;
    everLasting myEverLasting;
    fallFree myFallFree;
    flagCheck myFlagCheck;
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
    softGrid mySoftGrid;
    spanningCole mySpanningCole;
    superFlat mySuperFlat;
    superOrganism mySuperOrganism;
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
    int graphicCount= 44;
    //typography
    alphaDelta myAlphaDelta;
    blueCrown myBlueCrown;
    curvePara myCurvePara;
    deepVibe myDeepVibe;
    diveWave myDiveWave;
    digitalHybe myDigitalHybe;
    echoChamber myEchoChamber;
    fieldWork myFieldWork;
    goingGone myGoingGone;
    graviTas myGraviTas;
    kuruKuri myKuruKuri;
    longLonger myLongLonger;
    merryRound myMerryRound;
    moreGet myMoreGet;
    quickBrown myQuickBrown;
    rectAnd myRectAnd;
    roundFace myRoundFace;
    slideLane mySlideLane;
    spaceBold mySpaceBold;
    squareScape mySquareScape;
    threeStep myThreeStep;
    wipVip myWipVip;
    int typographyCount = 22;
    //movie
    watchMovie myWatchMovie;
    
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
    int pixelCount = 11;
    
    //cover
    flashCover myFlashCover;
    oddCover myOddCover;
    pikaCover myPikaCover;
    blackCover myBlackCover;
    int coverCount = 5;
};
