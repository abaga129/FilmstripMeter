/*
  ==============================================================================

    FilmstripMeter.h
    Created: 9 Aug 2015 9:04:32pm
    Author:  CTRecordings

  ==============================================================================
*/

#ifndef FILMSTRIPMETER_H_INCLUDED
#define FILMSTRIPMETER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>

//==============================================================================
/*
*/
class FilmstripMeter    : public Component
{
public:
    FilmstripMeter();
    ~FilmstripMeter();

    void paint (Graphics&);
    void resized();

	/*
	Must be called after the constructor.
	This method set's the Image as well as other important initial values that can't
	be set in the constructor.
	It sets the frameWidth, frameHeight, and the editor's size.
	*/
	void setImage(Image image, int numberOfFrames);

	/*
	The editor must inherit the Timer class. In onTimerCallback() pass a sample
	from the Audio Processor  to this method. The sample will be stored in the buffer.
	Once the buffer's size is the same as "sensitivity", a loop finds the largest value
	in the buffer and stores it in "peak". The 4th root of the peak value is taken and
	then passed to updateFrame();
	*/
	void addToBuffer(float sample);

	/*
	Calculates which frame to paint based on the float value passed to it.
	Then calls repaint()
	*/
	void updateFrame(float sample);

	/*
	Sets how often the meter changes frames.
	Sensitivity is what controls how many samples the buffer will store before
	updating to a new frame
	(The sensitivy is also dependent on the Timer in the plugin editor.)
	*/
	void setSensitivity(int newSensitivity){ sensitivity = newSensitivity; }

	int getWidth(){ return frameWidth; }

	int getHeight(){ return frameHeight; }

private:

	
	std::vector<float> buffer; //simple buffer to store samples
	
	int sensitivity; //Affects how often the meter changes frames
	
	

	int frameNum; //Current frame to be displayed
	int numFrames; //number of frames in the filmstrip

	int posX; 
	int posY;
	
	int frameHeight; 
	int frameWidth;

	float peak;

	Image filmStrip;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilmstripMeter)
};


#endif  // FILMSTRIPMETER_H_INCLUDED
