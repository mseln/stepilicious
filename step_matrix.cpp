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
	Slot::init(&sound_h);
	Cue::init();
		
	for(int i = 0; i < N_SLOTS; i++){
		slot[i].set_pos((i%16) * 70 + 50, (i / 16) * 70 + 100);
		slot[i].set_color(100, 100, 100);
	}
	
	path_to_dir_field.set_pos(20, 20);
	path_to_dir_field.set_size(200, 20);
	path_to_dir_field.set_col(100, 100, 100, 200);
	
	sound_h.load_sound(0, "kick 1.wav");
}

void Step_Matrix::draw(sf::RenderWindow * window){
	for(int i = 0; i < N_SLOTS; i++){
		slot[i].draw(window);
	}
	cue.draw(window);
	path_to_dir_field.draw(window);
}

void Step_Matrix::update(Event_Handler * event_h){
	if(path_to_dir_field.has_focus()){
		path_to_dir_field.text_append(event_h->get_ch());
		path_to_dir_field.text_remove(event_h->pollSp('B'));
	}
	if(path_to_dir_field.check(event_h->pollMp('x'), event_h->pollMp('y'), event_h->pollMb('l'))){
		path_to_dir_field.activate();
	}
	if(Base_System_Entry::no_target(event_h->pollMp('x'), event_h->pollMp('y'), event_h->pollMb('l'))){ 
		Base_System_Entry::deactivate_all();
	}
	
	
	if(event_h->poll_once_ch('q')) slot[0].switch_state();
	if(event_h->poll_once_ch('w')) slot[1].switch_state();
	if(event_h->poll_once_ch('e')) slot[2].switch_state();
	if(event_h->poll_once_ch('r')) slot[3].switch_state();
	if(event_h->poll_once_ch('t')) slot[4].switch_state();
	if(event_h->poll_once_ch('y')) slot[5].switch_state();
	if(event_h->poll_once_ch('u')) slot[6].switch_state();
	if(event_h->poll_once_ch('i')) slot[7].switch_state();
	
	if(event_h->poll_once_ch('a')) slot[8].switch_state();
	if(event_h->poll_once_ch('s')) slot[9].switch_state();
	if(event_h->poll_once_ch('d')) slot[10].switch_state();
	if(event_h->poll_once_ch('f')) slot[11].switch_state();
	if(event_h->poll_once_ch('g')) slot[12].switch_state();
	if(event_h->poll_once_ch('h')) slot[13].switch_state();
	if(event_h->poll_once_ch('j')) slot[14].switch_state();
	if(event_h->poll_once_ch('k')) slot[15].switch_state();
	
	if(cue.update()){
		if(slot[cue.get_pos()].is_active()) slot[cue.get_pos()].play();
	}
}