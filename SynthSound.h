/*
  ==============================================================================

    SynthSound.h
    Author:  Marlo

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
   
    public:  

        //Returns true if this sound should be played when a given midi note is pressed.
        bool appliesToNote(int midiNoteNumber) override { return true; }
        //Returns true if the sound should be triggered by midi events on a given channel.
        bool appliesToChannel(int midiChannel) override { return true; }
};