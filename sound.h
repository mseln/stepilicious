/*
 *  sound.h
 *  StepSeq
 *
 *  Created by Magnus Selin on 2012-05-30.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#ifndef _SOUND_H_
#define _SOUND_H_

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <map>
#include <cmath>

struct Sound_Holder {
	std::string name;
	sf::Music sound;
};

class Sound_Handler{
private:
	Sound_Holder sound_buffer[32];
	
public:
	bool load_sound(int n, std::string f_name);
	void play(int n);
	void pause(int n);
};

#endif