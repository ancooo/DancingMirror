#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	camWidth  = 320;
	camHeight = 240;
    captureSwitch = false;
    drawSwitch = false;
    drawCount = 0;
    
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

}


//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(100,100,100);
    grabber.update();
    if (!grabber.isFrameNew()) return;
    
    drawCount += 1;
    if(drawCount < 5) return;
    drawCount = 0;
    
    drawSwitch = !drawSwitch;
    ofLog() << "drawSwitch: " << drawSwitch;
    if(drawSwitch) videoTexture.loadData(pixels_a, camWidth,camHeight, GL_RGB);
    else videoTexture.loadData(pixels_b, camWidth,camHeight, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetHexColor(0xffffff);
	grabber.draw(20,20);
    videoTexture.draw(20+camWidth,20,camWidth,camHeight);
}

void ofApp::captureWithSwitch(){
    ofLog() << "capture!! " << captureSwitch;
    
    unsigned char * pixels_to;
    pixels_to = captureSwitch ? pixels_a : pixels_b;
    for(int i = 0; i < camWidth*camHeight*3; i++){
        pixels_to[i] = grabber.getPixels()[i]; // copy pixel
    }
    captureSwitch = !captureSwitch;
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key){
    if (key == ' ') captureWithSwitch();
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
