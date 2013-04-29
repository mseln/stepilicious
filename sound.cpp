/*
 *  sound.cpp
 *  StepSeq
 *
 *  Created by Magnus Selin on 2012-05-30.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include "sound.h"

bool Sound_Handler::load_sound(int n, std::string f_name){
	if(!sound_buffer[n].sound.OpenFromFile(f_name)){
		std::cerr << "Could not open " << f_name << "!\n";
		return false;
	}
	std::cout << f_name << " loaded sucessfully!\n";
	return true;
}

void Sound_Handler::play(int n){
	sound_buffer[n].sound.Play();
}
void Sound_Handler::pause(int n){
	sound_buffer[n].sound.Pause();
}