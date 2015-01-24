#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	
	public:
		
	void setup();
	void update();
	void draw();
    void captureWithSwitch();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
    ofSoundPlayer  popsong;
	ofVideoGrabber grabber;
    unsigned char *pixels_a;
    unsigned char *pixels_b;
    int drawCount;
    int secondCount;
    bool captureSwitch;
    bool drawSwitch;
	ofTexture videoTexture;
	int camWidth;
	int camHeight;
    
    float ofRandom();
    
    };
