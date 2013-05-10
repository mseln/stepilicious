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
	
	activated = false;
	
	this->set_active_col(120, 120, 120, 200);
	this->set_nonactive_col(100, 100, 100, 200);
	this->set_text_col(0, 0, 0);
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

void Base_System_Entry::set_active_col(int r, int g, int b){
	active_col[0] = r;
	active_col[1] = g;
	active_col[2] = b;
	active_col[3] = 100;
}
void Base_System_Entry::set_active_col(int r, int g, int b, int a){
	active_col[0] = r;
	active_col[1] = g;
	active_col[2] = b;
	active_col[3] = a;
}
void Base_System_Entry::set_nonactive_col(int r, int g, int b){
	nonactive_col[0] = r;
	nonactive_col[1] = g;
	nonactive_col[2] = b;
	nonactive_col[3] = 100;
}
void Base_System_Entry::set_nonactive_col(int r, int g, int b, int a){
	nonactive_col[0] = r;
	nonactive_col[1] = g;
	nonactive_col[2] = b;
	nonactive_col[3] = a;
}
void Base_System_Entry::set_text_col(int r, int g, int b){
	text_col[0] = r;
	text_col[1] = g;
	text_col[2] = b;
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

void Text_Field::text_append(char c){
	if(c!='\0') text.append(1u, c);
	if(c == (char)(8)) text.erase(text.end()-1, text.end());
	//std::cout << text << '\n';
}
void Text_Field::text_remove(bool r){
	if(r) text.erase(text.end()-1, text.end());
}

void Text_Field::draw(sf::RenderWindow * window){
	sf::Shape text_field;
	if(activated)	text_field = sf::Shape::Rectangle(pos[0], pos[1], pos[0]+size[0], pos[1]+size[1], 
																sf::Color(active_col[0], active_col[1], active_col[2], active_col[3]));
	else			text_field = sf::Shape::Rectangle(pos[0], pos[1], pos[0]+size[0], pos[1]+size[1], 
																sf::Color(nonactive_col[0], nonactive_col[1], nonactive_col[2], nonactive_col[3]));
	
	sf::String sf_text(text);
	sf_text.SetPosition(pos[0]+5, pos[1]);
	sf_text.SetColor(sf::Color(text_col[0], text_col[1], text_col[2]));
	sf_text.Move(sf_text.GetCenter());
	sf_text.SetSize(14);
	
	window->Draw(text_field);
	window->Draw(sf_text);
}

Choice_Field::Choice_Field(){
	active_field = -1;
}
void Choice_Field::init(std::vector<std::string> f_list){
	files = f_list;
}
void Choice_Field::draw(sf::RenderWindow * window){
	sf::Shape choice_field = sf::Shape::Rectangle(pos[0], pos[1], pos[0]+size[0], pos[1]+size[1], 
												  sf::Color(nonactive_col[0], nonactive_col[1], nonactive_col[2], nonactive_col[3]));
	
	sf::String sf_text[files.size()];
	sf::Shape txt_bkg[files.size()];
	
	for(int i = 0; i < files.size(); i++){
		
		if(active_field == i)	txt_bkg[i] = sf::Shape::Rectangle(pos[0]+5, pos[1] + i*16 + 2, pos[0]+size[0]-5, pos[1] + 16 + i*16, 
																  sf::Color(active_col[0], 
																			active_col[1], 
																			active_col[2]+15, 
																			active_col[3]));
		else					txt_bkg[i] = sf::Shape::Rectangle(pos[0]+5, pos[1] + i*16 + 2, pos[0]+size[0]-5, pos[1] + 16 + i*16, 
																  sf::Color(nonactive_col[0], 
																			nonactive_col[1], 
																			nonactive_col[2]+15, 
																			nonactive_col[3]));
		sf_text[i].SetText(files[i]);
		sf_text[i].SetPosition(pos[0]+5, pos[1] + i * 16);
		sf_text[i].SetColor(sf::Color(text_col[0], text_col[1], text_col[2]));
		sf_text[i].Move(sf_text[i].GetCenter());
		sf_text[i].SetSize(14);
	}
	
	
	window->Draw(choice_field);
	for(int i = 0; i < files.size(); i++) {
		window->Draw(txt_bkg[i]);
		window->Draw(sf_text[i]);
	}
}
int  Choice_Field::check(int x, int y, bool l_mouse_key){
	active_field = INF;
	for(int i = 0; i < files.size(); i++){
		if(x > pos[0]+5 and y > pos[1] + i*16 + 2 and x < pos[0]+size[0]-5 and y < pos[1] + 16 + i*16 and !l_mouse_key){
			active_field = i;
		}
		if(x > pos[0]+5 and y > pos[1] + i*16 + 2 and x < pos[0]+size[0]-5 and y < pos[1] + 16 + i*16 and l_mouse_key){
			active_field = i;
			is_down = i;
		}
		else {
			if(is_down != -1 and !l_mouse_key) {
				active_field = -i;
 			}
			if(i == is_down) is_down = -1;
		}
	}
	
	if(active_field < 0) return -active_field;
	else return -1;
}
std::string Choice_Field::get_file_name(int n){
	return files[n];
}