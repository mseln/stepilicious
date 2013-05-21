/*
 *  slot.cpp
 *  StepSeq
 *
 *  Created by Magnus Selin on 2012-05-27.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include "slot.h"

sf::Image		Slot::button_img;
double			Slot::pitch;
Sound_Handler * Slot::sound_list;

Slot::Slot(){
	active = false;
}

//                    Static functions
// ********************************************************

bool Slot::init(Sound_Handler * s){
	sound_list = s;
	
	if (!button_img.LoadFromFile("button.jpg")){
		std::cerr << "Couldn't load button image!";
		return false;
	}
	std::cerr << "Succesfully loaded image!\n";
	return true;
}
void Slot::set_pitch(double val){
	pitch = val;
}

// ********************************************************

bool Slot::is_active(){
	return active;
}

void Slot::set_color(int r, int g, int b){
	col[0] = r; col[1] = g; col[2] = b;
}
void Slot::set_pos(int x, int y) {
	pos[0] = x; pos[1] = y;
}
void Slot::set_active_sample(int n){
	active_sample = n;
}

void Slot::switch_state(){
	active = !active;
	if(active){
		col[0] = 100;
		col[1] = 100;
		col[2] = 200;
	}
	else{
		col[0] = 100;
		col[1] = 100;
		col[2] = 100;
	}
}
void Slot::disable(int n){
}

void Slot::mute(){muted = true;}
void Slot::unmute(){muted = false;}

void Slot::play(){
	if(!muted) sound_list->play(active_sample);
}

void Slot::draw(sf::RenderWindow * window){
	sf::Sprite tmp_img(button_img);
	tmp_img.SetPosition(pos[0], pos[1]);
	tmp_img.SetColor(sf::Color(col[0], col[1], col[2], 200));
	window->Draw(tmp_img);
}