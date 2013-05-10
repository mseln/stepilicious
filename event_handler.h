/*
 *  event_handler.h
 *  iwanto3d
 *
 *  Created by Magnus Selin on 2012-06-25.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef _EVENT_HANDLER_
#define _EVENT_HANDLER_

struct Special_Keys{
	bool SPACE, BACK,
	ESCAPE,
	UP, DOWN, RIGHT, LEFT,
	RSHIFT, LSHIFT;
};

class Event_Handler{
private:
	sf::RenderWindow * window;
	
	bool key[128];
	bool key_once[128];
	Special_Keys sp_key;
	
	int m_pos[2];
	bool m_key[2];
public:
	Event_Handler(sf::RenderWindow * w);
	
	void update();
	
	
	bool any_ch();
	
	bool pollCh(char c);
	bool pollSp(char c);
	
	bool poll_once_ch(char c);
	
	bool pollMb(char c);
	int  pollMp(char c);
	
	char get_once_ch();
	char get_ch();
};

#endif