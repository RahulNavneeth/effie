#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <SDL3/SDL.h>
#include "effie.h"

int32_t main (int32_t argc, char **argv) {
    if (argc == 1) {
        printf ("Err :: args <filename>\n");
        return 1;
    }

	Eff *effie = init_effie (argv[1]);
	// printf ("FileSize -> %ld\n", effie->torrent->fileSize);
	// printf ("FilePath -> %s\n", effie->torrent->filePath);
	// bec_print(effie->torrent->contents, 0);
	
	SDL_Init (SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow ("Effie", 800, 600, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer (window, NULL);

	int q = 0;
	SDL_Event event;
	while (!q) {
		while (SDL_PollEvent (&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				q = 1;
			}
		}

    	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    	SDL_RenderClear(renderer);
    	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    	SDL_FRect rect = {100, 100, 200, 100};
    	SDL_RenderFillRect(renderer, &rect);
    	SDL_RenderPresent(renderer);

	}

	SDL_DestroyRenderer (renderer);
	SDL_DestroyWindow (window);
	SDL_Quit ();
	
    return 0;
}
