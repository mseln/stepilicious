/*
 *  sound.cpp
 *  StepSeq
 *
 *  Created by Magnus Selin on 2012-05-30.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include "sound.h"

void Sound_Handler::load_dir(std::string path){
	DIR *dir = opendir(path.c_str()); // open the current directory
	if (!dir){
		std::cerr << "Cannot open directory!" << std::endl;
		exit(1);
	}
	
		struct dirent *entry;
	while (entry = readdir(dir)){ // notice the single '='
		std::cout << "Found directory entry: "
		<< entry->d_name << std::endl;
		f_name_in_path.push_back(entry->d_name);
	}
		closedir(dir);
}

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