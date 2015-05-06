/* 
* PlotlyViewer.cpp
*
* Created: 14.4.2015 22:47:45
* Author: Bhiefer
*/


#include "Constants.h"
#include "PlotlyViewer.h"
#include "Configuration.h"
#include "Timer.h"

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
	Ethernet.begin(DEVICE_MAC, DEVICE_IP);
// 	if(Ethernet.begin(DEVICE_MAC) == 0){
// 		Serial.println("... Failed to configure Ethernet using DHCP");
// 		// no point in carrying on, so do nothing forevermore:
// 		// try to congifure using IP address instead of DHCP:
// 		Ethernet.begin(DEVICE_MAC, DEVICE_IP);
// 	}
	Serial.println("... Done initializing ethernet");
	delay(1000);

//	log_level = 0;
	convertTimestamp = true;
	timezone = "Europe/Prague";
	maxpoints = PLOTLY_PLOT_SIZE * 3600 / PLOTLY_INTERVAL;
//	fileopt="overwrite";
	fileopt="extend";
	bool success;
	success = init();
	if(!success)
	{
		return RC_FATAL_FAILURE;
	}
	openStream();
	
	mLastTimeSent = 0;
}

uint8_t PlotlyViewer::onMeasured()
{
	if(timer.checkElapsed(mLastTimeSent, PLOTLY_INTERVAL))
	{
		mLastTimeSent = timer.current();
		
		
//		unsigned long now = static_cast<unsigned long>(timer.current());
		
// 		Serial.print("NOW:");
// 		Serial.println(now);
// 		Serial.println(sizeof(unsigned long));
		
		int i = 0;
		int token = 0;
		for(i = 0; i < sensorsSize && token < PLOTLY_TOKENS_SIZE; i++)
		{
			//plot(year(mLastTimeSent), month(mLastTimeSent), day(mLastTimeSent), hour(mLastTimeSent), minute(mLastTimeSent), second(mLastTimeSent), sensors[i]->getMeasuredValue(), PLOTLY_TOKENS[token++]);
			plot(millis(), sensors[i]->getMeasuredValue(), PLOTLY_TOKENS[token++]);
		}
		
		for(i = 0; i < outputsSize && token < PLOTLY_TOKENS_SIZE; i++)
		{
			//plot(year(mLastTimeSent), month(mLastTimeSent), day(mLastTimeSent), hour(mLastTimeSent), minute(mLastTimeSent), second(mLastTimeSent), outputs[i]->getStateValue(), PLOTLY_TOKENS[token++]);
			plot(millis(), sensors[i]->getMeasuredValue(), PLOTLY_TOKENS[token++]);
		}
	}
}


