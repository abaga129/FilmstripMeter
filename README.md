*********************************
#Filmstrip Meter
*********************************

This is a JUCE class that creates a meter from a filmstrip image.
The filmstrip must be vertical. (I created a tool that will assist
in making these filmstrips called "FilmstripMaker") 

###How To Use:

- Inherit Timer in the pluginEditor

- create a new pointer of the FilmstripMeter class.

- assign the pointer to a new FilmstripMeter.

- call FilmstripMeter->setImage(Image to be set, number of frame);

- In the onTimerCallback() method of the pluginEditor, call FilmstripMeter->addToBuffer(float sample)

