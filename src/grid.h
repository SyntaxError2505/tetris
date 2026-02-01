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
	piece type;
	cell(piece type);
};

// Singelton for accesing a grid vector of size (ROWS; COLOUMNS)
class grid{
	public:
	std::vector<std::vector<cell>> grid_vector;

	grid();

	void draw(SDL_Renderer* renderer);
};
