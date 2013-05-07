/*
 *  system_entries.h
 *  Stepilicious
 *
 *  Created by Magnus Selin on 5/3/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Base_System_Entry{
private:
	static int items;
	static std::vector<Base_System_Entry*> adress_list;
	
protected:
	int pos[2];
	int size[2];
	int col[4];
	
	bool is_down;
	bool activated;
public:	
	Base_System_Entry();
	
	static bool no_target(int x, int y, bool l_mouse_key);
	static void deactivate_all();
	
	void set_pos(int x, int y);
	void set_size(int x, int y);
	void set_col(int r, int g, int b);
	void set_col(int r, int g, int b, int a);
	
	void activate(){activated = true;}
	void deactivate(){activated = false;};
	
	bool has_focus(){return activated;}
	bool check(int x, int y, bool l_mouse_key);
};

class Text_Field : public Base_System_Entry{
private:
	std::string text;
	
public:
	void text_append(char c);
	void text_remove(bool r);
	
	void draw(sf::RenderWindow * window);
};