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


class Base_System_Entry{
protected:
	int pos[2];
	int size[2];
	int col[4];
public:
	void set_pos(int x, int y);
	void set_size(int x, int y);
	void set_col(int r, int g, int b);
	void set_col(int r, int g, int b, int a);
};

class Text_Field : public Base_System_Entry{
private:
	std::string text;
	
	bool activated;
public:
	void text_append(char c);
	void text_remove(bool r);
	void activate(){activated = true;}
	void deactivate(){activated = false;};
	
	void draw(sf::RenderWindow * window);
};