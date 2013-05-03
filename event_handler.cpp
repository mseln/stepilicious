/*
 *  event_handler.cpp
 *  iwanto3d
 *
 *  Created by Magnus Selin on 2012-06-25.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include "event_handler.h"

Event_Handler::Event_Handler(sf::RenderWindow * w){
	window = w;
	
	sp_key.SPACE	=
	sp_key.ESCAPE	=
	sp_key.UP		=
	sp_key.DOWN		=
	sp_key.RIGHT	=
	sp_key.LEFT		=
	sp_key.RSHIFT	=
	sp_key.LSHIFT	= false;
	
	for(int i = 0; i < 128; i++) key[i] = false;	
	
	m_key[0] = m_key[1] = false;
}
void Event_Handler::update(){
	
	for(int i = 0; i < 128; i++) key_once[i] = false;
	
	sf::Event Event;
	while (window->GetEvent(Event)){
		if (Event.Type == sf::Event::Closed){
			window->Close();
			break;
		}
		else if (Event.Type == sf::Event::KeyPressed and Event.Key.Code < 128){ key[Event.Key.Code] = true; key_once[Event.Key.Code] = true; }
		else if (Event.Type == sf::Event::KeyReleased and Event.Key.Code < 128) key[Event.Key.Code] = false;
		
		else if (Event.Type == sf::Event::KeyPressed){
			if (Event.Key.Code == sf::Key::Space)	sp_key.SPACE	= true;
			if (Event.Key.Code == sf::Key::Back)	sp_key.BACK		= false;
			if (Event.Key.Code == sf::Key::Escape)	sp_key.ESCAPE	= true;
			if (Event.Key.Code == sf::Key::Up)		sp_key.UP		= true;
			if (Event.Key.Code == sf::Key::Down)	sp_key.DOWN		= true;
			if (Event.Key.Code == sf::Key::Right)	sp_key.RIGHT	= true;
			if (Event.Key.Code == sf::Key::Left)	sp_key.LEFT		= true;
			if (Event.Key.Code == sf::Key::RShift)	sp_key.RSHIFT	= true;
			if (Event.Key.Code == sf::Key::LShift)	sp_key.LSHIFT	= true;
		}
		else if (Event.Type == sf::Event::KeyReleased){
			if (Event.Key.Code == sf::Key::Space)	sp_key.SPACE	= false;
			if (Event.Key.Code == sf::Key::Back)	sp_key.BACK		= false;
			if (Event.Key.Code == sf::Key::Escape)	sp_key.ESCAPE	= false;
			if (Event.Key.Code == sf::Key::Up)		sp_key.UP		= false;
			if (Event.Key.Code == sf::Key::Down)	sp_key.DOWN		= false;
			if (Event.Key.Code == sf::Key::Right)	sp_key.RIGHT	= false;
			if (Event.Key.Code == sf::Key::Left)	sp_key.LEFT		= false;
			if (Event.Key.Code == sf::Key::RShift)	sp_key.RSHIFT	= false;
			if (Event.Key.Code == sf::Key::LShift)	sp_key.LSHIFT	= false;
		}
		else if (Event.Type == sf::Event::MouseButtonPressed){
			if (Event.MouseButton.Button == sf::Mouse::Left)	m_key[0] = true;
			if (Event.MouseButton.Button == sf::Mouse::Right)	m_key[1] = true;
		}
		else if (Event.Type == sf::Event::MouseButtonReleased){
			if (Event.MouseButton.Button == sf::Mouse::Left)	m_key[0] = false;
			if (Event.MouseButton.Button == sf::Mouse::Right)	m_key[1] = false;
		}
	}

	const sf::Input& Input = window->GetInput();
	m_pos[0] = Input.GetMouseX();
	m_pos[1] = Input.GetMouseY();
}

bool Event_Handler::pollCh(char c){ if (c < '~' and c >= '\n') return key[c]; }
bool Event_Handler::poll_once_ch(char c){ if (c < '~' and c >= '\n') return key_once[c]; }

bool Event_Handler::pollSp(char c){	
	switch (c) {
		case 'l': return sp_key.LEFT;
		case 'r': return sp_key.RIGHT;
		case 'u': return sp_key.UP;	
		case 'd': return sp_key.DOWN;	
		
		case 'B': return sp_key.BACK;
		case 'S': return sp_key.SPACE;
		case 'L': return sp_key.LSHIFT;
		case 'R': return sp_key.RSHIFT;
			
		case 'E': return sp_key.ESCAPE;
			
		default: std::cerr << "Invalid choice!\n";
	}
}

bool Event_Handler::pollMb(char c){
	switch (c) {
		case 'l': return m_key[0];
		case 'r': return m_key[1];
	}
}

int Event_Handler::pollMp(char c){
	switch (c) {
		case 'x': return m_pos[0];
		case 'y': return m_pos[1];
	}
}

bool Event_Handler::any_ch(){
	bool pressed = false;
	for (int i = 0; i < 128; i++) if(key[i]) pressed = true;
	
	return pressed;
}

char Event_Handler::get_ch(){
	for (char c = ' '; c < '~'; c++) if(key_once[c]) return c;
	return '\0';
}