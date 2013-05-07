/*
 *  system_entries.cpp
 *  Stepilicious
 *
 *  Created by Magnus Selin on 5/3/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "system_entries.h"

int Base_System_Entry::items = 0;
std::vector<Base_System_Entry*> Base_System_Entry::adress_list;

Base_System_Entry::Base_System_Entry(){
	items++;
	adress_list.push_back(this);
}

void Base_System_Entry::deactivate_all(){
	for (int i = 0; i < items; i++) adress_list[i]->deactivate();
}

bool Base_System_Entry::no_target(int x, int y, bool l_mouse_key){
	if (!l_mouse_key) return false;
	for (int i = 0; i < items; i++){
		if(x > adress_list[i]->pos[0] and 
		   y > adress_list[i]->pos[1] and 
		   x < adress_list[i]->pos[0]+adress_list[i]->size[0] and 
		   y < adress_list[i]->pos[1]+adress_list[i]->size[1]){
			return false;
		}
	}
	return true;
}

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

bool Base_System_Entry::check(int x, int y, bool l_mouse_key){
	if(x > pos[0] and y > pos[1] and x < pos[0]+size[0] and y < pos[1]+size[1] and l_mouse_key){
		return true;
	}
	else {
		if(is_down and !l_mouse_key) {
			is_down = false;
			return true;
		}
		
		is_down = false;
	}
	
	if(x > pos[0] and y > pos[1] and x < pos[0]+size[0] and y < pos[1]+size[1] and !l_mouse_key){
		// Hover
	}
	
	return false;
}

void Text_Field::draw(sf::RenderWindow * window){
	sf::Shape text_field = sf::Shape::Rectangle(pos[0], pos[1], pos[0]+size[0], pos[1]+size[1], 
												sf::Color(col[0], col[1], col[2], 200));
	sf::String sf_text(text);
	sf_text.SetPosition(pos[0]+5, pos[1]);
	sf_text.SetColor(sf::Color(200, 100, 50));
	sf_text.Move(sf_text.GetCenter());
	sf_text.SetSize(14);
	
	window->Draw(text_field);
	window->Draw(sf_text);
}