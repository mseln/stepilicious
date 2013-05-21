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
	Button::init();
	Cue::init();
		
	for(int i = 0; i < N_SLOTS; i++){
		slot[i].set_pos((i % 16) * 70 + 100, (i / 16) * 70 + 100);
		slot[i].set_color(100, 100, 100);
		slot[i].set_active_sample(i / 16);
	}
	
	for(int i = 0; i < 4; i++){
		mute_horiz[i].set_pos(20, i * 70 + 100);
		mute_horiz[i].set_size(50, 50);
	}
	
	path_to_dir_field.set_pos(20, 20);
	path_to_dir_field.set_size(200, 20);
	
	sound_h.load_dir("/Users/geopard/Dropbox/Geopard/Programmering/stepilicious/test_sounds");
	
	file_list.init(sound_h.get_file_names());
	file_list.set_pos(50, 450);
	file_list.set_size(200, 300);
}

void Step_Matrix::draw(sf::RenderWindow * window){
	for(int i = 0; i < N_SLOTS; i++)
		slot[i].draw(window);
	for(int i = 0; i < 4; i++)
		mute_horiz[i].draw(window);
	cue.draw(window);
	path_to_dir_field.draw(window);
	file_list.draw(window);
}

void Step_Matrix::update(Event_Handler * event_h){
	update_text_fields(event_h);
	update_choice_fields(event_h);
	update_slots(event_h);
	
	update_cue();
	
	for(int i = 0; i < 4; i++){
		if(mute_horiz[i].check(event_h->pollMp('x'), event_h->pollMp('y'), event_h->pollMb('l'))){
			std::cout << "CHANGE!\n";
			mute_horiz[i].switch_state();
		}
	}
}

void Step_Matrix::update_text_fields(Event_Handler * event_h){
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
}
void Step_Matrix::update_choice_fields(Event_Handler * event_h){
	int s = (int)event_h->get_ch()-49;
	int a = file_list.check(event_h->pollMp('x'), event_h->pollMp('y'), event_h->pollMb('l'));
	if (a != -1 and s >= 0 and s < 32){ 
		std::cout << a << " and " << s << '\n';
		sound_h.load_sound(s, file_list.get_file_name(a));
	}
	
}

void Step_Matrix::update_cue(){
	if(cue.update()){
		if(slot[cue.get_pos()].is_active()) slot[cue.get_pos()].play();
		if(slot[cue.get_pos()+16].is_active()) slot[cue.get_pos()+16].play();
		if(slot[cue.get_pos()+32].is_active()) slot[cue.get_pos()+32].play();
		if(slot[cue.get_pos()+48].is_active()) slot[cue.get_pos()+48].play();
	}
	for(int i = 0; i < N_SLOTS; i++) slot[i].unmute();
}
void Step_Matrix::update_slots(Event_Handler * event_h){
	int s = (int)event_h->get_ch()-49;
	if(s >= 0 and s < 4){
		if(event_h->poll_once_ch('q')) slot[0+16*s].switch_state();
		if(event_h->poll_once_ch('w')) slot[1+16*s].switch_state();
		if(event_h->poll_once_ch('e')) slot[2+16*s].switch_state();
		if(event_h->poll_once_ch('r')) slot[3+16*s].switch_state();
		if(event_h->poll_once_ch('t')) slot[4+16*s].switch_state();
		if(event_h->poll_once_ch('y')) slot[5+16*s].switch_state();
		if(event_h->poll_once_ch('u')) slot[6+16*s].switch_state();
		if(event_h->poll_once_ch('i')) slot[7+16*s].switch_state();
	
		if(event_h->poll_once_ch('a')) slot[8+16*s].switch_state();
		if(event_h->poll_once_ch('s')) slot[9+16*s].switch_state();
		if(event_h->poll_once_ch('d')) slot[10+16*s].switch_state();
		if(event_h->poll_once_ch('f')) slot[11+16*s].switch_state();
		if(event_h->poll_once_ch('g')) slot[12+16*s].switch_state();
		if(event_h->poll_once_ch('h')) slot[13+16*s].switch_state();
		if(event_h->poll_once_ch('j')) slot[14+16*s].switch_state();
		if(event_h->poll_once_ch('k')) slot[15+16*s].switch_state();
	}
	for(int i = 0; i < 64; i++){
		if(mute_horiz[i/16].poll()) slot[i].mute();
	}
}