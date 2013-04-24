/*
 *  menu.h
 *  iwanto3d
 *
 *  Created by Magnus Selin on 2012-06-25.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

#include "application_states.h"
#include "event_handler.h"

#ifndef _MENU_H_
#define _MENU_H_

class Button{
private:
	int pos[2];
	int size[2];
	int col[3];
	
	bool is_down;
	
	//std::string text;
	sf::String text;
	sf::Shape button;
public:
	void set_size(int x, int y)			{ size[0] = x; size[1] = y; }
	void set_pos (int x, int y)			{ pos[0]  = x; pos[1]  = y; }
	void set_col (int r, int g, int b)	{ col[0]  = r; col[1]  = g; col[2] = b; }
	void set_text(std::string t)		{ text.SetText(t); }
	
	void init();
	
	void draw(sf::RenderWindow * window){ window->Draw(button); window->Draw(text);}
	bool check(int x, int y, bool l_mouse_key); // Returns true when released
};

class Menu{
private:
	Button start_b;
	Button quit_b;
	
public:
	Menu();
	
	void init();
	void update(Application_States * state, Event_Handler * event_h, sf::RenderWindow * window);
	void draw(sf::RenderWindow * window);
};

class InGame_Menu{
private:
	Button back_b;
	Button exit_b;
	
public:
	InGame_Menu();
	
	void init();
	void update(Application_States * state, Event_Handler * event_h, sf::RenderWindow * window);
	void draw(sf::RenderWindow * window);
};

#endif