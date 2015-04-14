/* 
* PlotlyViewer.cpp
*
* Created: 14.4.2015 22:47:45
* Author: Bhiefer
*/


#include "Constants.h"
#include "PlotlyViewer.h"


// Sign up to plotly here: https://plot.ly
// View your API key and streamtokens here: https://plot.ly/settings

// View your tokens here: https://plot.ly/settings
// Supply as many tokens as data traces
// e.g. if you want to ploty A0 and A1 vs time, supply two tokens

// arguments: username, api key, streaming token, filename

//PlotlyViewer::PlotlyViewer( uint8_t id ) : Viewer(id)


uint8_t PlotlyViewer::onCreate()
{
	Serial.println("... Initializing ethernet");
	if(Ethernet.begin(DEVICE_MAC) == 0){
		Serial.println("... Failed to configure Ethernet using DHCP");
		// no point in carrying on, so do nothing forevermore:
		// try to congifure using IP address instead of DHCP:
		Ethernet.begin(DEVICE_MAC, DEVICE_IP);
	}
	Serial.println("... Done initializing ethernet");
	delay(1000);

	fileopt="overwrite"; // See the "Usage" section in https://github.com/plotly/arduino-api for details
	bool success;
	success = init();
	if(!success){while(true){}}
	openStream();
}

uint8_t PlotlyViewer::onMeasured()
{
	plot(millis(), analogRead(A0), PLOTLY_TOKENS[0]);
}


