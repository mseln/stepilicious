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
}

void Session::update(){
	event_h->update();
}
void Session::draw(){
}