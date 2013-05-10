/*
 *  step_matrix.h
 *  Stepilicious
 *
 *  Created by Magnus Selin on 4/24/13.
 *  Copyright 2013 NR. All rights reserved.
 *
 */

#ifndef _STEP_MATRIX_H_
#define _STEP_MATRIX_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "event_handler.h"
#include "system_entries.h"

#include "slot.h"
#include "sound.h"
#include "cue.h"


#define N_SLOTS 64

class Step_Matrix{
private:
	Slot slot[N_SLOTS];
	Cue cue;
	
	Text_Field path_to_dir_field;
	Choice_Field file_list;	
	
	Sound_Handler sound_h;
	
	void update_text_fields(Event_Handler * event_h);
	void update_choice_fields(Event_Handler * event_h);
	void update_cue();
	void update_slots(Event_Handler * event_h);
	
public:
	Step_Matrix();
	void draw(sf::RenderWindow * window);
	void update(Event_Handler * event_h);
};

#endif