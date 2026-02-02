#include"grid.h"
#include <vector>

#include <SDL3/SDL_render.h>

cell::cell(piece type){
	this->type = type;
}

grid::grid(){
	for(int i = 0; i < ROWS; i++){
		std::vector<cell> row_buffer;

		for(int j = 0; j < COLOUMNS; j++){
			row_buffer.push_back(cell(piece::BLACK));
		}

		this->grid_vector.push_back(row_buffer);
	}
}

void grid::draw(SDL_Renderer *renderer){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLOUMNS; j++){
			SDL_FRect square;
			square.h = square.w = 30;
			square.x = j * 30;
			square.y = i * 30;

			switch(this->grid_vector[i][j].type){
				case piece::ORANGE:
					SDL_SetRenderDrawColor(renderer, 255, 150, 0, 255);
					break;
				case piece::BLUE:
					SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
					break;
				case piece::RED:
					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
					break;
				case piece::GREEN:
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
					break;
				case piece::LIGHT_BLUE:
					SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
					break;
				case piece::PINK:
					SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
					break;
				case piece::YELLOW:
					SDL_SetRenderDrawColor(renderer, 255, 240, 0, 255);
					break;
				case piece::BLACK:
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					break;


			}

			SDL_RenderFillRect(renderer, &square);
		}
	}
}

void grid::update_gravity(){
	//  start at SECOND row from bottom
	for(int i = ROWS - 2; i >= 0; i--){
		for(int j = 0; j < COLOUMNS; j++){
			if(this->grid_vector[i][j].type != piece::BLACK && this->grid_vector[i+1][j].type == piece::BLACK){
				// makes current cell black and cell below the color of the cell above
				this->grid_vector[i + 1][j].type = this->grid_vector[i][j].type;
				this->grid_vector[i][j].type = piece::BLACK;
			}
		}
	}
}
