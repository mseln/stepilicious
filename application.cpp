

#include "application.h"

Application::Application(){
	window = new sf::RenderWindow(sf::VideoMode(1280, 800), "Stepilicious");
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
			menuloop();
			break;
		
		case IN_GAME:
			gameloop();
			break;
		
		case IN_GAME_MENU:
			if (pause_if_in_menu) gameloop();
			ingame_menuloop();
			break;
	}
}

void Application::menuloop(){	
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