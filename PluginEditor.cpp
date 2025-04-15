/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SynthSound.h"
#include "SynthVoice.h"

//==============================================================================
SweetHeatAudioProcessorEditor::SweetHeatAudioProcessorEditor (SweetHeatAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),osc (audioProcessor.apvts, "OSC1WAVETYPE"), adsr (audioProcessor.apvts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    setSize (800, 600);

	addAndMakeVisible(adsr);
	addAndMakeVisible(osc);

   

}

SweetHeatAudioProcessorEditor::~SweetHeatAudioProcessorEditor()
{
}

//==============================================================================
void SweetHeatAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
   

    
}

void SweetHeatAudioProcessorEditor::resized()
{

	//set osc bounds
	osc.setBounds(10, 10, 100, 30);
   //set adsr bounds
	adsr.setBounds(getWidth()/2, 0 ,getWidth()/2, getHeight());
}


