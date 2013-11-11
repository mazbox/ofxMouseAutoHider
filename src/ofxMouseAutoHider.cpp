/**
 *  ofxMouseAutoHider.cpp
 *
 *  Created by Marek Bereza on 01/11/2013.
 */

#include "ofxMouseAutoHider.h"

ofxMouseAutoHider *ofxMouseAutoHider::instance = NULL;

void ofxMouseAutoHider::enable(float idleDurationBeforeHiding) {
	getInstance()->timeout = idleDurationBeforeHiding;
	getInstance()->setEnabled(true);
}
void ofxMouseAutoHider::disable() {
	getInstance()->setEnabled(false);
}


bool ofxMouseAutoHider::mouseIsShowing() {
	return getInstance()->cursorShowing;
}

void ofxMouseAutoHider::mouseEvent(ofMouseEventArgs &m) {
	lastTimeMouseMoved = ofGetElapsedTimef();
}

void ofxMouseAutoHider::update(ofEventArgs &evt) {
	float timeSinceLastMouse = ofGetElapsedTimef() - lastTimeMouseMoved;
//	printf("time since last mouse moved: %f\n", timeSinceLastMouse);
	if(cursorShowing && timeSinceLastMouse>timeout) {
		cursorShowing = false;
		ofHideCursor();
	}
	
	if(!cursorShowing && timeSinceLastMouse<timeout) {
		cursorShowing = true;
		ofShowCursor();
	}
}


void ofxMouseAutoHider::setEnabled(bool enabled) {
	if(this->enabled == enabled) {
		return;
	}
	
	this->enabled = enabled;
	ofShowCursor();
	printf("----------------------Setting enabled\n");
	cursorShowing = true;
	lastTimeMouseMoved = ofGetElapsedTimef();
	
	if(enabled) {
		ofAddListener(ofEvents().update, this, &ofxMouseAutoHider::update);
		ofAddListener(ofEvents().mouseMoved, this, &ofxMouseAutoHider::mouseEvent);
		ofAddListener(ofEvents().mousePressed, this, &ofxMouseAutoHider::mouseEvent);
		ofAddListener(ofEvents().mouseDragged, this, &ofxMouseAutoHider::mouseEvent);
		ofAddListener(ofEvents().mouseReleased, this, &ofxMouseAutoHider::mouseEvent);
	} else {
		ofRemoveListener(ofEvents().update, this, &ofxMouseAutoHider::update);
		ofRemoveListener(ofEvents().mouseMoved, this, &ofxMouseAutoHider::mouseEvent);
		ofRemoveListener(ofEvents().mousePressed, this, &ofxMouseAutoHider::mouseEvent);
		ofRemoveListener(ofEvents().mouseDragged, this, &ofxMouseAutoHider::mouseEvent);
		ofRemoveListener(ofEvents().mouseReleased, this, &ofxMouseAutoHider::mouseEvent);
	}
}
ofxMouseAutoHider::ofxMouseAutoHider() {
	enabled = false;
	cursorShowing = true;
}


ofxMouseAutoHider *ofxMouseAutoHider::getInstance() {
	if(instance==NULL) {
		instance = new ofxMouseAutoHider();
	}
	return instance;
}


