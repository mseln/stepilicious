/*
 *  slot.h
 *  StepSeq
 *
 *  Created by Magnus Selin on 2012-05-27.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

class Slot{
private:
	int pos[2];
	int col[3];
	static sf::Image button_img;
	static double pitch;
	
public:
	Slot();
	static bool init();
	static void load_sprite();
	static void set_pitch(double val);
	
	void set_color(int r, int g, int b);
	void set_pos(int x, int y);
	
	void switch_state(int n);
	void disable(int n);
	void play();
	
	void draw(sf::RenderWindow * window);
};