#include"grid.h"
#include <vector>
#include <iostream>

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

void grid::reset_moved(){
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLOUMNS; j++){
			this->grid_vector[i][j].moved = false;
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
				this->grid_vector[i + 1][j].current_part = this->grid_vector[i][j].current_part;
				this->grid_vector[i][j].type = piece::BLACK;
				this->grid_vector[i][j].current_part = false;
			}
		}
	}
}

void grid::move_left(){
	this->reset_moved();

	for(int i = 0; i < ROWS; i++){
		//starts at SECOND coloumn form left
		for(int j = COLOUMNS - 1; j > 0; j--){
			if(this->grid_vector[i][j].current_part && !this->grid_vector[i][j].moved && this->grid_vector[i][j - 1].type == piece::BLACK){
				std::cout << "moving left at Y: " << i << " X: " << j << "\n";
				// makes current cell black and cell below the color of the cell above
				this->grid_vector[i][j - 1].type = this->grid_vector[i][j].type;
				this->grid_vector[i][j - 1].current_part = true;
				this->grid_vector[i][j - 1].moved = true;
				this->grid_vector[i][j].type = piece::BLACK;
				this->grid_vector[i][j].current_part = false;
			}
		}
	}
}

void grid::move_right(){
	this->reset_moved();

	for(int i = 0; i < ROWS; i++){
		//starts at SECOND coloumn form right
		for(int j = COLOUMNS - 2; j >= 0; j--){
			if(this->grid_vector[i][j].current_part && !this->grid_vector[i][j].moved && this->grid_vector[i][j + 1].type == piece::BLACK){
				std::cout << "moving right at Y: " << i << " X: " << j << "\n";
				// makes current cell black and cell below the color of the cell above
				this->grid_vector[i][j + 1].type = this->grid_vector[i][j].type;
				this->grid_vector[i][j + 1].current_part = true;
				this->grid_vector[i][j + 1].moved = true;
				this->grid_vector[i][j].type = piece::BLACK;
				this->grid_vector[i][j].current_part = false;
			}
		}
	}
}
