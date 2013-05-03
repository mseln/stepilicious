/*
 *  system_entries.cpp
 *  Stepilicious
 *
 *  Created by Magnus Selin on 5/3/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "system_entries.h"

void Base_System_Entry::set_pos(int x, int y){
	pos[0] = x;
	pos[1] = y;
}
void Base_System_Entry::set_size(int x, int y){
	size[0] = x;
	size[1] = y;
}
void Base_System_Entry::set_col(int r, int g, int b){
	col[0] = r;
	col[1] = g;
	col[2] = b;
	col[3] = 100;
}
void Base_System_Entry::set_col(int r, int g, int b, int a){
	col[0] = r;
	col[1] = g;
	col[2] = b;
	col[3] = a;
}

void Text_Field::text_append(char c){
	if(c!='\0') text.append(1u, c);
	if(c == (char)(8)) text.erase(text.end()-1, text.end());
	//std::cout << text << '\n';
}
void Text_Field::text_remove(bool r){
	if(r) text.erase(text.end()-1, text.end());
}
void Text_Field::draw(sf::RenderWindow * window){
	sf::Shape text_field = sf::Shape::Rectangle(pos[0], pos[1], pos[0]+size[0], pos[1]+size[1], 
												sf::Color(col[0], col[1], col[2], 200));
	sf::String sf_text(text);
	sf_text.SetPosition(pos[0]+5, pos[1]);
	sf_text.SetColor(sf::Color(200, 0, 50));
	sf_text.Move(sf_text.GetCenter());
	sf_text.SetSize(14);
	
	window->Draw(text_field);
	window->Draw(sf_text);
}