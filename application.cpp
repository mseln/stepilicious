

#include "application.h"

Application::Application(){
	window = new sf::RenderWindow(sf::VideoMode(1200, 800), "TCoCD");
	window->SetFramerateLimit(60);
	
	event_h = new Event_Handler(window);
	app_state = new Application_States(MENU);
	
	menu.init();
	ingame_menu.init();
	
	*app_state = MENU;
	
	pause_if_in_menu = true;
}

void Application::run(){
	while (window->IsOpened()){
		event_h->update();
		
		window->Clear();
		update();
		window->Display();
	}
}

void Application::update(){
	switch (*app_state) {
		case MENU:
			//std::cout << "in menuloop\n";
			menuloop();
			break;
		
		case IN_GAME:
			//std::cout << "in gameloop\n";
			gameloop();
			break;
		
		case IN_GAME_MENU:
			//std::cout << "in ingame menuloop\n";
			if (pause_if_in_menu) gameloop();
			ingame_menuloop();
			break;
	}
}

void Application::menuloop(){
	//if(event_h->pollCh('a')) *game_state = IN_GAME;
	
	menu.update(app_state, event_h, window);
	menu.draw(window);
	
	if(*app_state == IN_GAME) session = new Session(window, event_h);
}

void Application::gameloop(){
	if(event_h->pollSp('E')){
		*app_state = IN_GAME_MENU;
	}
	
	session->update();
	session->draw();
}

void Application::ingame_menuloop(){
	ingame_menu.update(app_state, event_h, window);
	ingame_menu.draw(window);
	
	if(*app_state == MENU) delete session;
}