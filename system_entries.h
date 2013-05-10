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
#define INF 1000000000
class Base_System_Entry{
private:
	static int items;
	static std::vector<Base_System_Entry*> adress_list;
	
protected:
	int pos[2];
	int size[2];
	
	int active_col[4];
	int nonactive_col[4];
	int text_col[3];
	
	bool is_down;
	bool activated;
public:	
	Base_System_Entry();
	
	static bool no_target(int x, int y, bool l_mouse_key);
	static void deactivate_all();
	
	void set_pos(int x, int y);
	void set_size(int x, int y);
	
	void set_active_col(int r, int g, int b);
	void set_active_col(int r, int g, int b, int a);
	void set_nonactive_col(int r, int g, int b);
	void set_nonactive_col(int r, int g, int b, int a);
	void set_text_col(int r, int g, int b);
	
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

class Choice_Field : public Base_System_Entry{
private:
	std::vector<std::string> files;
	int active_field;
	int is_down;
	
public:
	Choice_Field();
	void init(std::vector<std::string> f_list);
	void draw(sf::RenderWindow * window);
	int  check(int x, int y, bool l_mouse_key);
	std::string get_file_name(int n);
};