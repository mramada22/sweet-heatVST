/*
  ==============================================================================

    AdsrData.cpp
    Created: 12 Feb 2025 7:34:39am
    Author:  Marlo

  ==============================================================================
*/

#include "AdsrData.h"
#include <JuceHeader.h>

void AdsrData::updateADSR(const float attack, const float decay, const float sustain, const float release) {

    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;

    setParameters(adsrParams);
}
