#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
    popsong.loadSound("sounds/popsong.mp3");
    ofBackground(255,255,255);
    ofEnableAlphaBlending();
	camWidth  = 640;
	camHeight = 480;
    captureSwitch = false;
    drawSwitch = false;
    drawCount = 0;
    secondCount = 0;
    //ofRandom() > 40;
    
    
	vector<ofVideoDevice> devices = grabber.listDevices();
	
    for(int i = 0; i < devices.size(); i++){
		cout << devices[i].id << ": " << devices[i].deviceName; 
        if( devices[i].bAvailable ){
            cout << endl;
        }else{
            cout << " - unavailable " << endl; 
        }
	}
    
	grabber.setDeviceID(0);
	grabber.setDesiredFrameRate(60);
	grabber.initGrabber(camWidth,camHeight);
	
    pixels_a = new unsigned char[camWidth*camHeight*3];
    pixels_b = new unsigned char[camWidth*camHeight*3];
    for(int i = 0; i < camWidth*camHeight*3; i++){
        pixels_a[i] = 0;
        pixels_b[i] = 0;
    }
	videoTexture.allocate(camWidth,camHeight, GL_RGB);
	ofSetVerticalSync(true);
    
    
    int bufferSize = 256;
    }


//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    grabber.update();
    if (!grabber.isFrameNew())
    return;
    drawCount += 1;
    if(drawCount < 4) return;
    drawCount = 0;
    //if(drawCount > 2) captureWithSwitch();
    
   // secondCount += 1;
   // if(secondCount >= 4)return;
   // secondCount = 0;
   // if (secondCount = 10) captureWithSwitch();
   
    drawSwitch = !drawSwitch;
    ofLog() << " drawCount: " " drawswitch: "<< drawCount; drawSwitch;
    if(drawSwitch) videoTexture.loadData(pixels_a, camWidth,camHeight, GL_RGB);
    else videoTexture.loadData(pixels_b, camWidth,camHeight, GL_RGB);

}

//--------------------------------------------------------------
void ofApp::draw(){
    grabber.draw(camWidth,0,-camWidth,camHeight);
    videoTexture.draw(camWidth,0,-camWidth,camHeight);
    ofSetColor(255, 255, 255, 120);
}

void ofApp::captureWithSwitch(){
    //captureWithSwitch(); = ofRandom();
    ofLog() << "capture!! " << captureSwitch;
    //ofLog() << " drawCount: " << drawCount;

    
    unsigned char * pixels_to;
    pixels_to = captureSwitch ? pixels_a : pixels_b;
    for(int i = 0; i < camWidth*camHeight*3; i++){
        pixels_to[i] = grabber.getPixels()[i]; // copy pixel
    }
    captureSwitch = !captureSwitch;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key){
    if (key == ' ')captureWithSwitch();
    if (key == 'p')popsong.play();
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

