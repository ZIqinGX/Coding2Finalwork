#pragma once

#include<iostream>
#include <cstdlib>
#include <time.h>
#include "ofMain.h"
#include "ofxGLSLSimplexNoise.h"
#include "ofxGui.h"


using namespace std;

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	float r1 = ofRandom(0, 1);
	float r2 = ofRandom(0, 2);

	ofSoundPlayer mySound1;
	ofSoundPlayer mySound2;

	ofxGLSLSimplexNoise noise;
	ofxPanel gui;
	ofxFloatSlider freqRX;
	ofxFloatSlider freqRY;
	ofxFloatSlider freqGX;
	ofxFloatSlider freqGY;
	ofxFloatSlider freqBX;
	ofxFloatSlider freqBY;
	ofxFloatSlider speedR;
	ofxFloatSlider speedG;
	ofxFloatSlider speedB;
	ofxFloatSlider mulR;
	ofxFloatSlider mulG;
	ofxFloatSlider mulB;
	ofxFloatSlider addR;
	ofxFloatSlider addG;
	ofxFloatSlider addB;
	ofxFloatSlider colorRR;
	ofxFloatSlider colorRG;
	ofxFloatSlider colorRB;
	ofxFloatSlider colorGR;
	ofxFloatSlider colorGG;
	ofxFloatSlider colorGB;
	ofxFloatSlider colorBR;
	ofxFloatSlider colorBG;
	ofxFloatSlider colorBB;
    ofxFloatSlider alpha;

	bool showGui;

	ofTrueTypeFont		font;
	ofTrueTypeFont		fontSmall;

	// a flag for sending serial
	bool bSendSerialMessage;
	// when did we last read?
	float readTime;

	ofSerial serial;
	ofBuffer serialReadBuffer;
	// store all of the received messages
	vector<string> receivedSerialMessages;
	// store a message to send
	string messageToSend;
	// if the device is not connected, when is the last time we tried to connect to it
	float timeLastTryConnect = 0.;
	// store the device list so we can print it out in the draw function
	vector <ofSerialDeviceInfo> deviceList;
	// set this to the device path that you would like to connect to
	// the default will be the first device in the list
	string serialDevicePathToConnectTo = "";
	// keep a history of the bytes read from the serial device so we can split it based on a character
	string serialReadString = "";
};
