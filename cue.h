/*
 *  cue.h
 *  Stepilicious
 *
 *  Created by Magnus Selin on 4/29/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define LENGTH 4

class Cue{
private:
	int pos;
	int bpm;
	
	sf::Clock clock;
public:
	Cue();
	
	bool update();
	int get_pos();
};