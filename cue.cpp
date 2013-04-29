/*
 *  cue.cpp
 *  Stepilicious
 *
 *  Created by Magnus Selin on 4/29/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "cue.h"

Cue::Cue(){
	clock.Reset();
	bpm = 120;
}

bool Cue::update(){
	float min_ela;
	min_ela = clock.GetElapsedTime() / 60;
	
	if(min_ela * bpm > 1){
		clock.Reset();
		
		pos++;
		pos = pos % LENGTH;
		return true;
	}
	
	return false;
}

int Cue::get_pos(){ return pos; }