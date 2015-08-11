/*
  ==============================================================================

    FilmstripMeter.cpp
    Created: 9 Aug 2015 9:04:32pm
    Author:  CTRecordings

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FilmstripMeter.h"

//==============================================================================
FilmstripMeter::FilmstripMeter()
{
	sensitivity = 10;
	peak = 0;
	frameNum = 0;
	setSize(0, 0);
}

FilmstripMeter::~FilmstripMeter()
{
}

void FilmstripMeter::setImage(Image image, int numberOfFrames){
	filmStrip = image;
	numFrames = numberOfFrames;
	frameWidth = filmStrip.getWidth();
	frameHeight = filmStrip.getHeight() / numFrames;
	setSize(frameWidth, frameHeight);
	updateFrame(0);
	repaint();
}

void FilmstripMeter::addToBuffer(float sample){

	peak = 0;
	buffer.push_back(sample);

	if (buffer.size() > sensitivity){

		while (!buffer.empty()){
			if (buffer.back() > peak)
				peak = buffer.back();
			buffer.pop_back();
		}
		peak = sqrt(sqrt(peak));
		updateFrame(peak);

	}
}

void FilmstripMeter::updateFrame(float sample){
	frameNum = roundFloatToInt(sample * numFrames);
	posX = 0;
	if (frameNum == 0){
		posY = 0;
	}
	else{
		posY = (frameNum * frameHeight);
	}
	repaint();
}

void FilmstripMeter::paint (Graphics& g)
{
	setSize(frameWidth, frameHeight);
	g.drawImage(filmStrip, 0, 0, frameWidth, frameHeight, posX, posY, frameWidth, frameHeight);
}

void FilmstripMeter::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
