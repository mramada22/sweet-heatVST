/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"
#include "UI/OscComponent.h"

//==============================================================================
/**
*/
class SweetHeatAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SweetHeatAudioProcessorEditor (SweetHeatAudioProcessor&);
    ~SweetHeatAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.

    
    SweetHeatAudioProcessor& audioProcessor;
	OscComponent osc;
    AdsrComponent adsr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SweetHeatAudioProcessorEditor)
};
