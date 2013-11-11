/**     ___           ___           ___                         ___           ___     
 *     /__/\         /  /\         /  /\         _____         /  /\         /__/|    
 *    |  |::\       /  /::\       /  /::|       /  /::\       /  /::\       |  |:|    
 *    |  |:|:\     /  /:/\:\     /  /:/:|      /  /:/\:\     /  /:/\:\      |  |:|    
 *  __|__|:|\:\   /  /:/~/::\   /  /:/|:|__   /  /:/~/::\   /  /:/  \:\   __|__|:|    
 * /__/::::| \:\ /__/:/ /:/\:\ /__/:/ |:| /\ /__/:/ /:/\:| /__/:/ \__\:\ /__/::::\____
 * \  \:\~~\__\/ \  \:\/:/__\/ \__\/  |:|/:/ \  \:\/:/~/:/ \  \:\ /  /:/    ~\~~\::::/
 *  \  \:\        \  \::/          |  |:/:/   \  \::/ /:/   \  \:\  /:/      |~~|:|~~ 
 *   \  \:\        \  \:\          |  |::/     \  \:\/:/     \  \:\/:/       |  |:|   
 *    \  \:\        \  \:\         |  |:/       \  \::/       \  \::/        |  |:|   
 *     \__\/         \__\/         |__|/         \__\/         \__\/         |__|/   
 *
 *  Description: Hides the cursor after a certain amount of inactivity.
 *				 
 *  ofxMouseAutoHider.h, created by Marek Bereza on 01/11/2013.
 */
#include "ofMain.h"

class ofxMouseAutoHider {
public:
	static void enable(float idleDurationBeforeHiding = 3);
	static void disable();
	static bool mouseIsShowing();
private:
	ofxMouseAutoHider();
	float timeout;
	static ofxMouseAutoHider *instance;
	void mouseEvent(ofMouseEventArgs &m);
	void update(ofEventArgs &evt);
	float lastTimeMouseMoved;
	bool cursorShowing;
	bool enabled;
	void setEnabled(bool enabled);
	static ofxMouseAutoHider *getInstance();
};


