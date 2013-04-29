/*
 *  step_matrix.h
 *  Stepilicious
 *
 *  Created by Magnus Selin on 4/24/13.
 *  Copyright 2013 NR. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "slot.h"
#include "sound.h"
#include "cue.h"

#define N_SLOTS 16

class Step_Matrix{
private:
	Slot slot[N_SLOTS];
	Sound_Handler sound_h;
	Cue cue;
	
public:
	Step_Matrix();
	void draw(sf::RenderWindow * window);
	void update();
};