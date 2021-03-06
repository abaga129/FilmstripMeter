/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
FilmstripMeterAudioProcessorEditor::FilmstripMeterAudioProcessorEditor (FilmstripMeterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{

	meterImage = ImageCache::getFromMemory(Images::filmstrip_jpg, Images::filmstrip_jpgSize);

	meter = new FilmstripMeter();
	meter->setImage(meterImage, 20);
	addAndMakeVisible(meter);

    setSize (meter->getWidth(),meter->getHeight());

	startTimer(10);
}

FilmstripMeterAudioProcessorEditor::~FilmstripMeterAudioProcessorEditor()
{
}

//==============================================================================
void FilmstripMeterAudioProcessorEditor::paint (Graphics& g)
{
	meter->setBounds(0, 0, meter->getWidth(), meter->getHeight());

}

void FilmstripMeterAudioProcessorEditor::resized()
{

}

void FilmstripMeterAudioProcessorEditor::timerCallback(){
	meter->addToBuffer(processor.x);//x is the current sample being played
}
