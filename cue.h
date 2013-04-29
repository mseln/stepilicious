/*
 *  cue.h
 *  Stepilicious
 *
 *  Created by Magnus Selin on 4/29/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _CUE_H_
#define _CUE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define LENGTH 16

class Cue{
private:
	int pos;
	int bpm;
	
	static sf::Image cue_img;
	int img_pos[LENGTH][2];
	int img_col[LENGTH][3];
	
	sf::Clock clock;
public:
	Cue();
	
	static bool init();
	
	bool update();
	int get_pos();
	void draw(sf::RenderWindow * window);
};

#endif