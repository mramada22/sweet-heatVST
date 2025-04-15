/*
  ==============================================================================

    OscData.cpp
    Created: 11 Mar 2025 10:56:32am
    Author:  Marlo

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec) {
    fmOsc.prepare(spec);
    prepare(spec);
}

void OscData::setWaveType(const int choice){
    //return std::sin(x) - Sine wave
    //return x / juce::MathConstants<float>::pi - Saw wave
    //return x < 0.0f ? -1.0f : 1.0f; - Square wave

    switch (choice)
    {
        case 0: //Sin Wave
			initialise([](float x) {return std::sin(x);});
                break; 

		case 1: //Saw Wave
			initialise([](float x) {return x / juce::MathConstants<float>::pi;});
			break;

		case 2: //Square Wave
            initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f;});
            break;

        default:
            jassertfalse; //Error
            break; 
    }
}

void OscData::setWaveFrequency(const int midiNoteNumber) {
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber) + fmMod);
    lastMidiNote = midiNoteNumber;
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block) {

	for (int channel = 0; channel < block.getNumChannels(); ++channel) {
        for (int sample; sample < block.getNumSamples(); ++sample){
			fmMod = fmOsc.processSample(block.getSample(channel, sample)) * fmDepth;
        }
	}
    process(juce::dsp::ProcessContextReplacing<float>(block));
}

void OscData::setFmParams(const float depth, const float freq) {
    fmOsc.setFrequency(freq);
    fmDepth = depth;
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(lastMidiNote) + fmMod);
}