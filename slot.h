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
	static sf::Image button_img;
	static double pitch;
	
public:
	Slot();
	static void load_sprite();
	static void setPitch(double val);
	
	void setColor(int slot, int r, int g, int b);
	void switchState(int n);
	void disable(int n);
	
	void play();
	
	
	void setPos(int x, int y) {pos[0] = x; pos[1] = y;}
	void draw(int n, sf::RenderWindow * window);
};