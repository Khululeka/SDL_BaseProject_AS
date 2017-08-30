//==============================================================================
/*
	Primary application class

	3/11/2014
	SDLTutorials.com
	Tim Jones
*/
//==============================================================================
#ifndef __APP_H__
	#define __APP_H__

#include <SDL2/SDL.h>
#include "ManagersAndControllers/TextureBank.h"
#include "ManagersAndControllers/EventManager.h"

class App : public EventManager {  //TODO why public?
	private:
		static App Instance;
		EventManager eventMan;  //TODO should be static?  getting unresolved externals

		bool Running = true;

		SDL_Window* Window = NULL;
		SDL_Renderer* Renderer = NULL;
		SDL_Surface* PrimarySurface = NULL;

		static const int WindowWidth = 1024;
		static const int WindowHeight = 768;

		Texture* TestTexture;

	private:
		App();

		// Capture SDL Events
		//void OnEvent(SDL_Event* Event);
		//void OnEvent(SDL_Event Event);

		// Initialize our SDL game / app
		bool Init();

		// Logic loop
		void Loop();

		// Render loop (draw)
		void Render();

		// Free up resources
		void Cleanup();

	public:
		int Execute(int argc, char* argv[]);

	public:
		SDL_Renderer* GetRenderer();

	public:
		static App* GetInstance();

		static int GetWindowWidth();
		static int GetWindowHeight();

		void OnExit();  //TOSO static??	
		
		virtual void OnKeyDown(SDL_Keysym sym);
		virtual void OnKeyUp(SDL_Keysym sym);


		virtual void OnLButtonDown(int mX, int mY);
		virtual void OnLButtonUp(int mX, int mY);
		virtual void OnTouchDown(int mX, int mY);
		virtual void OnTouchUp(int mX, int mY);
};

#endif
