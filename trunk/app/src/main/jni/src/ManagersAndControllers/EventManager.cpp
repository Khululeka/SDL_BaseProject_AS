#include "EventManager.h"
#include "Helpers/Log.h"
#include <Helpers/Stringify.h>

EventManager::EventManager() {
}

EventManager::~EventManager() {
	//Do nothing
}

void EventManager::OnEvent(SDL_Event* Event) {
	switch (Event->type) {
//	case SDL_ACTIVEEVENT: {
//		switch (Event->active.state) {
//		case SDL_APPMOUSEFOCUS: {
//			if (Event->active.gain)    OnMouseFocus();
//			else                OnMouseBlur();
//
//			break;
//		}
//		case SDL_APPINPUTFOCUS: {
//			if (Event->active.gain)    OnInputFocus();
//			else                OnInputBlur();
//
//			break;
//		}
//		case SDL_APPACTIVE: {
//			if (Event->active.gain)    OnRestore();
//			else                OnMinimize();
//
//			break;
//		}
//		}
//		break;
//	}

	case SDL_KEYDOWN: {
		if (!keys[Event->key.keysym.scancode]) {
			//Log( "%i",  Event->key.keysym.scancode );
			OnKeyDown(Event->key.keysym);
			keys[Event->key.keysym.scancode] = true;

		}
		break;
	}

	case SDL_KEYUP: {
		keys[Event->key.keysym.scancode] = false;
		OnKeyUp(Event->key.keysym);
		break;
	}

	case SDL_MOUSEMOTION: {
		OnMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
		break;
	}

	case SDL_MOUSEBUTTONDOWN: {
		switch (Event->button.button) {
		case SDL_BUTTON_LEFT: {
			OnLButtonDown(Event->button.x, Event->button.y);
			break;
		}
		case SDL_BUTTON_RIGHT: {
			OnRButtonDown(Event->button.x, Event->button.y);
			break;
		}
		case SDL_BUTTON_MIDDLE: {
			OnMButtonDown(Event->button.x, Event->button.y);
			break;
		}
		}
		break;
	}

	case SDL_MOUSEBUTTONUP: {
		switch (Event->button.button) {
		case SDL_BUTTON_LEFT: {
			OnLButtonUp(Event->button.x, Event->button.y);
			break;
		}
		case SDL_BUTTON_RIGHT: {
			OnRButtonUp(Event->button.x, Event->button.y);
			break;
		}
		case SDL_BUTTON_MIDDLE: {
			OnMButtonUp(Event->button.x, Event->button.y);
			break;
		}
		}
		break;
	}


	case SDL_FINGERDOWN: {
		OnTouchUp(Event->button.x, Event->button.y);
		break;
	}

	case SDL_FINGERUP: {
		OnTouchUp(Event->button.x, Event->button.y);
		break;
	}




	case SDL_JOYAXISMOTION: {
		OnJoyAxis(Event->jaxis.which, Event->jaxis.axis, Event->jaxis.value);
		break;
	}

	case SDL_JOYBALLMOTION: {
		OnJoyBall(Event->jball.which, Event->jball.ball, Event->jball.xrel, Event->jball.yrel);
		break;
	}

	case SDL_JOYHATMOTION: {
		OnJoyHat(Event->jhat.which, Event->jhat.hat, Event->jhat.value);
		break;
	}
	case SDL_JOYBUTTONDOWN: {
		OnJoyButtonDown(Event->jbutton.which, Event->jbutton.button);
		break;
	}

	case SDL_JOYBUTTONUP: {
		OnJoyButtonUp(Event->jbutton.which, Event->jbutton.button);
		break;
	}

	case SDL_QUIT: {
		OnExit();
		break;
	}

	case SDL_SYSWMEVENT: {
		//Ignore
		break;
	}

//	case SDL_VIDEORESIZE: {
//		OnResize(Event->resize.w, Event->resize.h);
//		break;
//	}
//
//	case SDL_VIDEOEXPOSE: {
//		OnExpose();
//		break;
//	}

	default: {
		OnUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2);
		break;
	}
	}
}

//Pure virtuals, do nothing
void EventManager::OnInputFocus() {}
void EventManager::OnInputBlur() {}
void EventManager::OnKeyDown(SDL_Keysym sym) {}
void EventManager::OnKeyUp(SDL_Keysym sym) {}
void EventManager::OnMouseFocus() {}
void EventManager::OnMouseBlur() {}
void EventManager::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {}
void EventManager::OnMouseWheel(bool Up, bool Down) {}
void EventManager::OnLButtonDown(int mX, int mY) {}
void EventManager::OnLButtonUp(int mX, int mY) {}
void EventManager::OnRButtonDown(int mX, int mY) {}
void EventManager::OnRButtonUp(int mX, int mY) {}
void EventManager::OnMButtonDown(int mX, int mY) {}
void EventManager::OnMButtonUp(int mX, int mY) {}
void EventManager::OnTouchDown(int mX, int mY) {}
void EventManager::OnTouchUp(int mX, int mY) {}
void EventManager::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value) {}
void EventManager::OnJoyButtonDown(Uint8 which, Uint8 button) {}
void EventManager::OnJoyButtonUp(Uint8 which, Uint8 button) {}
void EventManager::OnJoyHat(Uint8 which, Uint8 hat, Uint8 value) {}
void EventManager::OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel) {}
void EventManager::OnMinimize() {}
void EventManager::OnRestore() {}
void EventManager::OnResize(int w, int h) {}
void EventManager::OnExpose() {}
void EventManager::OnExit() {}
void EventManager::OnUser(Uint8 type, int code, void* data1, void* data2) {}