#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
    ofBackground(0);
	ofSetVerticalSync(true);
	mySound1.load("sound1.wav");
	mySound1.play();

	bSendSerialMessage = false;
	ofSetLogLevel(OF_LOG_VERBOSE);

	fontSmall.load("DIN.otf", 12);
	font.load("DIN.otf", 32);

	serial.listDevices();
	deviceList = serial.getDeviceList();
	showGui = true;
	int baud = 9600;
	
	if (serialDevicePathToConnectTo != "") {
		serial.setup(serialDevicePathToConnectTo, baud);
	}
	else {
		serial.setup(0, baud); //open the first device
	}

	// we just tried to connect, so store the time
	timeLastTryConnect = ofGetElapsedTimef();
	readTime = 0;
	
		
	//gui
	gui.setup();
	gui.add(freqRX.setup("Freq R X", 1, 0.0, 1.0));
	gui.add(freqRY.setup("Freq R Y", 1, 0.0, 1.0));
	gui.add(freqGX.setup("Freq G X", 1, 0.0, 1.0));
	gui.add(freqGY.setup("Freq G Y", 2, 0.0, 2.0));
	gui.add(freqBX.setup("Freq B X", 2, 0.0, 2.0));
	gui.add(freqBY.setup("Freq B Y", 2, 0.0, 2.0));
	gui.add(speedR.setup("speed R", 1, 0.0, 1.0));
	gui.add(speedG.setup("speed G", 1, 0.0, 1.0));
	gui.add(speedB.setup("speed B", 1, 0.0, 1.0));
	gui.add(mulR.setup("multiple R", 0.5, 0.0, 2.0));
	gui.add(mulG.setup("multiple G", 0.5, 0.0, 2.0));
	gui.add(mulB.setup("multiple B", 0.9, 0.0, 2.0));
	gui.add(addR.setup("add R", 0.2, 0.0, 2.0));
	gui.add(addG.setup("add G", 2, 0.0, 2.0));
	gui.add(addB.setup("add B", 0.2, 0.0, 2.0));
	gui.add(colorRR.setup("color RR", 0.445, 0.0, 1.0));
	gui.add(colorRG.setup("color RG", 0.42, 0.0, 1.0));
	gui.add(colorRB.setup("color RB", 0.36, 0.0, 1.0));
	gui.add(colorGR.setup("color GR", 0.2, 0.0, 1.0));
	gui.add(colorGG.setup("color GG", 0.5, 0.0, 1.0));
	gui.add(colorGB.setup("color GB", 0.6, 0.0, 1.0));
	gui.add(colorBR.setup("color BR", 0.5, 0.0, 1.0));
	gui.add(colorBG.setup("color BG", 0.5, 0.0, 1.0));
    gui.add(colorBB.setup("color BB", 0.4, 0.0, 1.0));
    gui.add(alpha.setup("alpha", 1.0, 0.0, 1.0));

	//gui.loadFromFile("settings.xml");
	
	
}

//--------------------------------------------------------------
void ofApp::update() {
	if (serial.isInitialized()) {
		
		int numBytesToRead = serial.available();
		
		if (numBytesToRead > 5) {


				cout << "reading chars" << numBytesToRead << endl;
				float r1 = ofRandom(0, 3);
				float r2 = ofRandom(0, 4);
				float ran = serial.available();

				noise.freqR.set(freqRX, freqRY);
				noise.freqG.set(freqGX, freqGY);
				noise.freqB.set(freqBX, freqBY);
				noise.speed.set(speedR, speedG, speedB);
				noise.mul.set(mulR, mulG, mulB);
				noise.add.set(addR - r1 * 0.1, addG, addB);
				noise.colorR.set(colorRR + 0.1 / r1, colorRG, colorRB);
				noise.colorG.set(colorGR + r2 * 0.1 / 2, colorGG, colorGB + 0.1);
				noise.colorB.set(colorBR + 0.2 / r1, colorBG, colorBB + 0.02);
				noise.alpha = alpha;

				serialReadBuffer.clear();
				serial.readBytes(serialReadBuffer, numBytesToRead);
				serialReadString += serialReadBuffer.getText();

				string fullMessage = "";
				int eraseIndex = -1;
				if (eraseIndex > -1) {
					// a new message has been received and must be erased
					serialReadString = serialReadString.substr(eraseIndex);
				}
			
			readTime = ofGetElapsedTimef();
		}
	}
	else {
		// serial device is not initialized
		// lets try to connect again
		float etimef = ofGetElapsedTimef();
		if (etimef - timeLastTryConnect > 10.0) {
			// refresh device list
			deviceList = serial.getDeviceList();
			timeLastTryConnect = etimef;
			int baud = 9600;
			if (serialDevicePathToConnectTo != "") {
				ofLogNotice("Attempting to connect to serial device: ") << serialDevicePathToConnectTo;
				serial.setup(serialDevicePathToConnectTo, baud);
			}
			else {
				ofLogNotice("Attempting to connect to serial device: ") << 0;
				serial.setup(0, baud); //open the first device
			}
		}


	}
	if (receivedSerialMessages.size() > 10) {
		receivedSerialMessages.erase(receivedSerialMessages.begin());
	}



}

//--------------------------------------------------------------
void ofApp::draw() {
	noise.draw();
	if (showGui) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'g') {
		if (showGui) {
			showGui = false;
		}
		else {
			showGui = true;
		}
		//cout << "g pressed" << endl;
		
	}
	
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
