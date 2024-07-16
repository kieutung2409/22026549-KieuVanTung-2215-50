#include <windows.h>  
#include <SDL2/SDL.h>   
#include <SDL2/SDL_image.h>  
#include <string>  

SDL_Surface* LoadImage(std::string file_path) {  
    SDL_Surface* loadimage = IMG_Load(file_path.c_str());  
    SDL_Surface* optimize_image = NULL;  

    if (loadimage != NULL) {  
        optimize_image = SDL_ConvertSurface(loadimage, loadimage->format, 0);  
        SDL_FreeSurface(loadimage);  
    }  

    return optimize_image;  
}  

int main(int argc, char* argv[]) {  
    SDL_Surface* image;  
    SDL_Window* window;  
    SDL_Surface* screen;  

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return 1;  

    window = SDL_CreateWindow("Gameplay Plane", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 600, SDL_WINDOW_SHOWN);  
    screen = SDL_GetWindowSurface(window);  
    image = LoadImage("bgplane.png");  

    SDL_BlitSurface(image, NULL, screen, NULL);  

    SDL_UpdateWindowSurface(window);  
    SDL_Delay(5000);  
    SDL_FreeSurface(image);  
    SDL_DestroyWindow(window);  
    SDL_Quit();  

    return 0;  
}