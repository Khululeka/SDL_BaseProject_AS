//==============================================================================
/*
	Basic macro for logging (can be extended for other target builds; i.e, using
	NSLog for OS X / iOS). Could also be modified to log to a file instead of
	console.

	3/11/2014
    SDLTutorials.com
    Tim Jones
*/
//==============================================================================
#include <SDL2/SDL.h>
#ifndef __LOG_H__
	#define __LOG_H__

	#include <stdio.h>

	#define DEBUG 1

	#ifdef DEBUG
	   // #define Log(...) printf(__VA_ARGS__); printf("\n");
	#define Log(...) SDL_Log(__VA_ARGS__);
	#else
	    #define Log(...) ;
	#endif

#endif
