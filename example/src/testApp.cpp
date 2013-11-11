#include "testApp.h"
#include "ofxMouseAutoHider.h"
//--------------------------------------------------------------
void testApp::setup(){
	ofSetWindowShape(300, 300);
	ofBackground(0);
	ofxMouseAutoHider::enable();
}


void testApp::draw() {
	ofSetColor(255);
	string tada = "";
	if(!ofxMouseAutoHider::mouseIsShowing()) {
		tada = "\n\nTADAAAA!\n";
	}
	ofDrawBitmapString("The mouse will disappear\nif you don't use it."+tada, 20, 30);
	
}