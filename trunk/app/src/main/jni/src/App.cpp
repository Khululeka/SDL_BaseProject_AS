//==============================================================================
#include "App.h"
#include "Helpers/Log.h"

App App::Instance;

//==============================================================================
App::App() {
}

//------------------------------------------------------------------------------
//void App::OnEvent(SDL_Event* Event) {
//
//	if (Event->type == SDL_QUIT) Running = false;
//}

//------------------------------------------------------------------------------
bool App::Init() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		Log("Unable to Init SDL: %s", SDL_GetError());
		return false;
	}

	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		Log("Unable to Init hinting: %s", SDL_GetError());
	}


    SDL_Rect gScreenRect = { 0, 0, 320, 240 };

    //Get device display mode
    SDL_DisplayMode displayMode;
    if( SDL_GetCurrentDisplayMode( 0, &displayMode ) == 0 )
    {
        gScreenRect.w = displayMode.w;
        gScreenRect.h = displayMode.h;
    }


	if((Window = SDL_CreateWindow(
		"My SDL Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        gScreenRect.w, gScreenRect.h, SDL_WINDOW_SHOWN)
	) == NULL) {
		Log("Unable to create SDL Window: %s", SDL_GetError());
		return false;
	}

    //does nothing couses "SDL Error: Renderer already associated with window" on android
	//PrimarySurface = SDL_GetWindowSurface(Window);

	if((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
	    Log("Unable to create renderer! SDL Error: %s\n", SDL_GetError() );
	    return false;
	}

	SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	// Initialize image loading for PNGs
	if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		Log("Unable to init SDL_image: %s", IMG_GetError());
		return false;
	}

	// Load all of our Textures (see TextureBank class for expected folder)
	if(TextureBank::Init() == false) {
		Log("Unable to init TextureBank");
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------
void App::Loop() {
}

//------------------------------------------------------------------------------
void App::Render() {
	SDL_RenderClear(Renderer);

	if (TextureBank::Get("Test")) {
		TextureBank::Get("Test")->Render(0, 0); // You should really check your pointers
	}

	SDL_RenderPresent(Renderer);
}
//------------------------------------------------------------------------------
void App::OnExit() {
	Log("Quitting!");
	Running = false;
}


void App::OnKeyDown(SDL_Keysym sym) {
	Log("OnKeyDown!");
}void App::OnKeyUp(SDL_Keysym sym) {
	Log("OnKeyUp!");
}

void App::OnLButtonDown(int mX, int mY) {
	Log("OnLButtonDown: %i,%i", mX, mY);
}
void App::OnLButtonUp(int mX, int mY) {
	OnLButtonDown(mX, mY);
}
void App::OnTouchDown(int mX, int mY) { OnLButtonDown(mX, mY); }
void App::OnTouchUp(int mX, int mY) { OnLButtonUp(mX, mY); }



//------------------------------------------------------------------------------
void App::Cleanup() {
	TextureBank::Cleanup();

	if(Renderer) {
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}

	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}

	IMG_Quit();
	SDL_Quit();
}

//------------------------------------------------------------------------------
int App::Execute(int argc, char* argv[]) {
	if(!Init()) return 0;

	SDL_Event Event;

	while(Running) {
		while(SDL_PollEvent(&Event) != 0) {
			OnEvent(&Event);
		}
	//	SDL_PumpEvents();

//		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
//		if (currentKeyStates[SDL_SCANCODE_UP])
//		{
//			Log("UP");
//		}
//		else if (currentKeyStates[SDL_SCANCODE_DOWN])
//		{
//			Log("DOWN");
//		}
//		else if (currentKeyStates[SDL_SCANCODE_LEFT])
//		{
//			Log("LEFT");
//		}
//		else if (currentKeyStates[SDL_SCANCODE_RIGHT])
//		{
//			Log("RIGHT");
//		}






		Loop();
		Render();

		SDL_Delay(1); // Breath
	}

	Cleanup();

	return 1;
}

//==============================================================================
SDL_Renderer* App::GetRenderer() { return Renderer; }

//==============================================================================
App* App::GetInstance() { return &App::Instance; }

int App::GetWindowWidth()  { return WindowWidth; }
int App::GetWindowHeight() { return WindowHeight; }

//==============================================================================
