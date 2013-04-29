/*
 *  step_matrix.cpp
 *  Stepilicious
 *
 *  Created by Magnus Selin on 4/24/13.
 *  Copyright 2013 NR. All rights reserved.
 *
 */

#include "step_matrix.h"

Step_Matrix::Step_Matrix(){
	Slot::init();
	Cue::init();
	
	for(int i = 0; i < N_SLOTS; i++){
		slot[i].set_pos((i%16) * 70 + 50, (i / 16) * 70 + 100);
		slot[i].set_color(100, 100, 100);
	}
		
	sound_h.load_sound(0, "kick 1.wav");
}

void Step_Matrix::draw(sf::RenderWindow * window){
	for(int i = 0; i < N_SLOTS; i++){
		slot[i].draw(window);
	}
	cue.draw(window);
}

void Step_Matrix::update(){
	if(cue.update()){
		sound_h.play(0);
	}
}