/*
 *  slot.cpp
 *  StepSeq
 *
 *  Created by Magnus Selin on 2012-05-27.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include "slot.h"

sf::Image	Slot::button_img;
double		Slot::pitch;


Slot::Slot(){}

//                    Static functions
// ********************************************************

bool Slot::init(){
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

void Slot::set_color(int slot, int r, int g, int b){
	col[0] = r; col[1] = g; col[2] = b;
}
void Slot::set_pos(int x, int y) {
	pos[0] = x; pos[1] = y;
}

void Slot::switch_state(int n){ 
}
void Slot::disable(int n){
}
void Slot::play(){
}

void Slot::draw(sf::RenderWindow * window){
	sf::Sprite tmp_img(button_img);
	tmp_img.SetPosition(pos[0], pos[1]);
	tmp_img.SetColor(sf::Color(col[0], col[1], col[2], 200));
	window->Draw(tmp_img);
}