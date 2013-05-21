/*
 *  menu.cpp
 *  iwanto3d
 *
 *  Created by Magnus Selin on 2012-06-25.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include "menu.h"

//*************************** -- Menu_Button -- ************************************

void Menu_Button::init(){
	button = sf::Shape::Rectangle(pos[0], pos[1], pos[0]+size[0], pos[1]+size[1], sf::Color(col[0], col[1], col[2], 200));
	text.SetPosition(pos[0]+20, pos[1]-5);
	text.Move(text.GetCenter());
	text.SetSize(40);
	
	is_down = false;
}

bool Menu_Button::check(int x, int y, bool l_mouse_key){
	if(x > pos[0] and y > pos[1] and x < pos[0]+size[0] and y < pos[1]+size[1] and l_mouse_key){
		this->set_col(255, 200, 100); 
		this->init();
		
		is_down = true;
	}
	else {
		if(is_down and !l_mouse_key) {
			is_down = false;
			return true;
		}
		
		is_down = false;
		this->set_col(100, 100, 100); 
		this->init();
	}
	
	if(x > pos[0] and y > pos[1] and x < pos[0]+size[0] and y < pos[1]+size[1] and !l_mouse_key){
		this->set_col(150, 150, 200); 
		this->init();
	}
	
	return false;
}



//**************************** -- Menu -- *************************************

Menu::Menu(){
	
}

void Menu::init(){
	start_b.set_col(100, 100, 100);
	start_b.set_pos(100, 200);
	start_b.set_size(200, 40);
	start_b.set_text("Start!");
	start_b.init();
	
	quit_b.set_col(100, 100, 100);
	quit_b.set_pos(100, 260);
	quit_b.set_size(200, 40);
	quit_b.set_text("Quit!");
	quit_b.init();
}

void Menu::draw(sf::RenderWindow * window){
	start_b.draw(window);
	quit_b.draw(window);
}

void Menu::update(Application_States * state, Event_Handler * event_h, sf::RenderWindow * window){

	if( start_b.check(event_h->pollMp('x'), event_h->pollMp('y'), event_h->pollMb('l')) ) *state = IN_GAME;
	if( quit_b.check(event_h->pollMp('x'), event_h->pollMp('y'), event_h->pollMb('l')) ) window->Close();
}



//************************ -- In Game Menu -- *********************************

InGame_Menu::InGame_Menu(){
	
}

void InGame_Menu::init(){
	back_b.set_col(100, 100, 100);
	back_b.set_pos(100, 200);
	back_b.set_size(200, 40);
	back_b.set_text("Back!");
	back_b.init();
	
	exit_b.set_col(100, 100, 100);
	exit_b.set_pos(100, 260);
	exit_b.set_size(200, 40);
	exit_b.set_text("Exit!");
	exit_b.init();
}

void InGame_Menu::draw(sf::RenderWindow * window){
	back_b.draw(window);
	exit_b.draw(window);
}

void InGame_Menu::update(Application_States * state, Event_Handler * event_h, sf::RenderWindow * window){
	if( back_b.check(event_h->pollMp('x'), event_h->pollMp('y'), event_h->pollMb('l')) ) *state = IN_GAME;
	if( exit_b.check(event_h->pollMp('x'), event_h->pollMp('y'), event_h->pollMb('l')) ) *state = MENU;
}