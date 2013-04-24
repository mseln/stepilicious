/*
 *  step_matrix.h
 *  Stepilicious
 *
 *  Created by Magnus Selin on 4/24/13.
 *  Copyright 2013 NR. All rights reserved.
 *
 */

#include "slot.h"
#define N_SLOTS 16

class Step_Matrix{
private:
	Slot slot[N_SLOTS];
	
public:
	Step_Matrix();
	void draw(sf::RenderWindow * window);
};