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
	for(int i = 0; i < N_SLOTS; i++){
		slot[i].set_pos((i%4) * 70 + 100, (i / 4) * 70 + 100);
		slot[i].set_color(i, (i % 8) * 20, (i % 4) * 40, i * 10);
	}
}

void Step_Matrix::draw(sf::RenderWindow * window){
	for(int i = 0; i < N_SLOTS; i++){
		slot[i].draw(window);
	}
}
