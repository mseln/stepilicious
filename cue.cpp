/*
 *  cue.cpp
 *  Stepilicious
 *
 *  Created by Magnus Selin on 4/29/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "cue.h"

sf::Image Cue::cue_img;

Cue::Cue(){
	clock.Reset();
	bpm = 120;
	pos = 0;
	
	for (int i = 0; i < LENGTH; i++){
		img_col[i][0] = 100;
		img_col[i][1] = 100;
		img_col[i][2] = 100;
		
		img_pos[i][0] = i * 70 + 100;
		img_pos[i][1] = 380;
	}
}

//                    Static functions
// ********************************************************

bool Cue::init(){
	if (!cue_img.LoadFromFile("button.jpg")){
		std::cerr << "Couldn't load cue image!";
		return false;
	}
	std::cerr << "Succesfully loaded image!\n";
	return true;
}

// ********************************************************

bool Cue::update(){
	float min_ela = clock.GetElapsedTime() / (60 / 4);
	
	if(min_ela * bpm > 1){
		clock.Reset();
		
		img_col[pos][0] = 100;
		img_col[pos][1] = 100;
		img_col[pos][2] = 100;
		
		pos++;
		pos = pos % LENGTH;
		
		img_col[pos][0] = 200;
		img_col[pos][1] = 200;
		img_col[pos][2] = 100;
		
		return true;
	}
	
	return false;
}

void Cue::draw(sf::RenderWindow * window){
	for(int i = 0; i < LENGTH; i++){
		sf::Sprite tmp_img(cue_img);
		tmp_img.SetPosition(img_pos[i][0], img_pos[i][1]);
		tmp_img.SetColor(sf::Color(img_col[i][0], img_col[i][1], img_col[i][2], 200));
		tmp_img.Scale(1, 0.5);
		window->Draw(tmp_img);
	}
}

int Cue::get_pos(){ return pos; }