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

Slot::Slot(){
	
}

//                    Static functions
// ********************************************************

void Slot::load_sprite(){
	if (!button_img.LoadFromFile("button.jpg")){
		std::cerr << "Couldn't load button image!";
	}
}
void Slot::setPitch(double val){
	pitch = val;
}

// ********************************************************

void Slot::setColor(int slot, int r, int g, int b){
}
void Slot::switchState(int n){ 
}
void Slot::disable(int n){
}

void Slot::play(){
	for(int i = 0; i < 4; i++){
	}
}

void Slot::draw(int n, sf::RenderWindow * window){
	
}