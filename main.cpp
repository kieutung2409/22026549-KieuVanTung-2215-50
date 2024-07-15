#include <SDL2/SDL.h>  
#include <stdio.h>

int WinMain(int argc, char* argv[]) {  
    SDL_Window* window = NULL;  
    SDL_Renderer* renderer = NULL;  

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {  
        printf("SDL initialization failed: %s\n", SDL_GetError());  
        return 1;  
    }  

    window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 600, 0);  
    if (window == NULL) {  
        printf("Error creating window: %s\n", SDL_GetError());  
        return 1;  
    }  

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);  
    if (renderer == NULL) {  
        printf("Error creating renderer: %s\n", SDL_GetError());  
        return 1;  
    }  

    // Load and display background image  
    SDL_Surface* bg_surface = SDL_LoadBMP("back.bmp");  
    if (bg_surface == NULL) {  
        printf("Error loading background image: %s\n", SDL_GetError());  
        return 1;  
    }  

    SDL_Texture* bg_texture = SDL_CreateTextureFromSurface(renderer, bg_surface);  
    SDL_RenderCopy(renderer, bg_texture, NULL, NULL);  
    SDL_RenderPresent(renderer);  

    // Main game loop  
    bool quit = false;  
    while (!quit) {  
        // Game logic and rendering  

        // Handle events  
        SDL_Event event;  
        while (SDL_PollEvent(&event)) {  
            if (event.type == SDL_QUIT) {  
                quit = true;  
            }  
        }  
    }  

    // Clean up resources  
    SDL_FreeSurface(bg_surface);  
    SDL_DestroyTexture(bg_texture);  
    SDL_DestroyRenderer(renderer);  
    SDL_DestroyWindow(window);  
    SDL_Quit();  

    return 0;  
}