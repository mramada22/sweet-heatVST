/*
  ==============================================================================

    AdsrData.h
    Created: 12 Feb 2025 7:34:39am
    Author:  Marlo

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AdsrData : public juce::ADSR {

public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);

private:
    juce::ADSR::Parameters adsrParams;
};