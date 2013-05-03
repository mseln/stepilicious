/*
 *  slot.h
 *  StepSeq
 *
 *  Created by Magnus Selin on 2012-05-27.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#ifndef _SLOT_H_
#define _SLOT_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "sound.h"


class Slot{
private:
	int pos[2];
	int col[3];
	
	bool active;
	
	static sf::Image button_img;
	static double pitch;
	static Sound_Handler * sound_list;
	
public:
	Slot();
	static bool init(Sound_Handler * s);
	static void load_sprite();
	static void set_pitch(double val);
	
	bool is_active();
	
	void set_color(int r, int g, int b);
	void set_pos(int x, int y);
	
	void switch_state();
	void disable(int n);
	void play();
	
	void draw(sf::RenderWindow * window);
};

#endif