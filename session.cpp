/*
 *  session.cpp
 *  TCoCD
 *
 *  Created by Magnus Selin on 2012-07-01.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include "session.h"

Session::Session(sf::RenderWindow * w, Event_Handler * e){
	window = w;
	event_h = e;
	bkg_img.LoadFromFile("background.jpg");
}

void Session::update(){
	event_h->update();
}
void Session::draw(){
	sf::Sprite tmp_img(bkg_img);
	window->Draw(tmp_img);
	
	step_matrix.update();
	step_matrix.draw(window);
}