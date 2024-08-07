#include "tapMachine.h"

//--------------------------------------------------------------
void tapMachine::tap() {
    
    float time = ofGetElapsedTimef();
    
    if (!tappedTimes.empty()) bTapping = time - tappedTimes.back() < 2;

    //Clear if there is enough break
    if (!bTapping) tappedTimes.clear();
    
    //Add time
    tappedTimes.push_back(time);
    
    //Keep size 8
    while (tappedTimes.size() > 8) tappedTimes.erase(tappedTimes.begin());
    
    //Calculate new BPM
    if (tappedTimes.size() >= 2) {
        float mean = 0;
        for (int i = 0; i < tappedTimes.size() - 1; i++) {
            mean += (tappedTimes[i + 1] - tappedTimes[i]);
        }
        mean /= (float)(tappedTimes.size() - 1);
        
        bpm = 60 / mean;
    }
}
