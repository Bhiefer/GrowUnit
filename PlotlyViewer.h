/* 
* PlotlyViewer.h
*
* Created: 14.4.2015 22:47:45
* Author: Bhiefer
*/


#ifndef __PLOTLYVIEWER_H__
#define __PLOTLYVIEWER_H__

#include "Viewer.h"
#include "plotly_streaming_ethernet.h"

class PlotlyViewer : public Viewer, public plotly
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
	PlotlyViewer(uint8_t id) : Viewer(id), plotly(PLOTLY_USERNAME, PLOTLY_API_KEY, PLOTLY_TOKENS, PLOTLY_FILENAME, PLOTLY_TOKENS_SIZE)
	{
	}
	
	virtual uint8_t onCreate();
	virtual uint8_t onMeasured();
	
	protected:
	private:

}; //PlotlyViewer

#endif //__PLOTLYVIEWER_H__
