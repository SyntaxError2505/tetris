#pragma once

#include <SDL3/SDL_render.h>
#include<vector>

#define ROWS 20
#define COLOUMNS 10

enum piece{
	ORANGE, // Left L
	BLUE, // Right L
	RED, // Left Z
	GREEN, // Right Z
	LIGHT_BLUE, // Stick
	PINK, // _-_
	YELLOW, // Square
	BLACK, // Empty square
};

// Class for every square of a grid
class cell{
	// if true: is influenced by keystrokes
	public:
	bool current_part;
	bool moved;
	piece type;
	cell(piece type);
};

// Singelton for accesing a grid vector of size (ROWS; COLOUMNS)
class grid{
	public:
	std::vector<std::vector<cell>> grid_vector;

	grid();
	// makes cells fall if cell below is clear
	void update_gravity();
	void move_left();
	void move_right();

	void reset_moved();

	// returns if a controlled piece is on the grid
	bool check_piece();

	void draw(SDL_Renderer* renderer);
};
