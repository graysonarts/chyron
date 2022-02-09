#include "ofApp.h"
#include "chyron.h"

#define SOURCE_NAME "Chyron"
const string OFFLINE = "offline";
const string SENDING = "sending";

ofApp* mainApp = nullptr;

void onChyronEvent() {
	if (mainApp) {
		mainApp->chyronSubsystemInitialized = true;
		ofLog() << "onChyronEvent";
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	mainApp = this; // We need this for the rust interop
	strcpy_s(senderName, 256, SOURCE_NAME);
	ofSetWindowTitle(senderName);

	ofLog() << ndiSender.GetNDIversion() << " (ndi.tv)";
	ndiFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	ndiSender.SetFrameRate(29.97);
	ndiSender.CreateSender(senderName, ofGetWidth(), ofGetHeight());
	chyronSubsystemInitialized = false;

	chyron_register_callback(onChyronEvent);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(chyronSubsystemInitialized ? ofColor::white : ofColor::red);
	drawChyron();
	if (ndiSender.SenderCreated()) {
		ndiSender.SendImage(ndiFbo);
		ofDrawBitmapStringHighlight(SENDING, ofGetWidth() / 2, ofGetHeight() / 2);
	}
	else {
		ofDrawBitmapStringHighlight(OFFLINE, ofGetWidth() / 2, ofGetHeight() / 2);
	}
}

void ofApp::drawChyron() {
	ndiFbo.begin();
	ofClear(0);
	ofRotateDeg(ofGetElapsedTimef());
	ofDrawRectangle(10, 10, 300, 300);
	ndiFbo.end();
	ndiFbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	chyron_initialize();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
