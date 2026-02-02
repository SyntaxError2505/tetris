#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <iostream>
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include"grid.h"

#define UPDATE_SPEED_ms 500

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

grid game_grid = grid();

Uint64 last_update = 0;
Uint64 timer = 0;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    /* Create the window */
    if (!SDL_CreateWindowAndRenderer("Hello World", 800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

	game_grid.grid_vector[0][5].type = piece::ORANGE;
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
    	return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
	if(event->type == SDL_EVENT_KEY_UP && event->key.key == SDLK_G){
		game_grid.update_gravity();
	}
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
	timer = SDL_GetTicks() - last_update;

	SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_RenderClear(renderer);
	
	if(timer >= UPDATE_SPEED_ms){
		timer = 0;
		game_grid.update_gravity();
		last_update = SDL_GetTicks();
	}

	std::cout << "Timer: " << timer << "\n";

	game_grid.draw(renderer);
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}

