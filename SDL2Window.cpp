#include "SDL.h"
#include <SDL_ttf.h>
// https://stackoverflow.com/questions/22886500/how-to-render-text-in-sdl2
int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);
  const int WIDTH = 640, HEIGHT = 480;

  SDL_Window *window = SDL_CreateWindow(
    "SDL2Test",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    WIDTH,
    HEIGHT,
    0
  );

  SDL_Log("Setup SDL2 Window ");

  if (window == nullptr){
    SDL_Log("Could not create a window: %s", SDL_GetError());
    return -1;
  }

  //SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr){
    SDL_Log("Could not create a renderer: %s", SDL_GetError());
    return -1;
  }

  SDL_Rect rect;
    rect.x = 250;
    rect.y = 150;
    rect.w = 200;
    rect.h = 200;

  TTF_Init();
  //std::string score_text = "score: " + std::to_string(score); 
  TTF_Font* font = TTF_OpenFont("font/FreeSans.ttf", 24); //this opens a font style and sets a size
  //SDL_Color foregroundColor = { 255, 255, 255 };
  //SDL_Color backgroundColor = { 0, 0, 255 };
  //SDL_Color textColor = { 0, 0, 0, 255 };
  SDL_Color White = {255, 255, 255};
  //SDL_Surface* textSurface = TTF_RenderText_Shaded(font, "This is my text.", foregroundColor, backgroundColor);
  //SDL_Surface *textSurface = TTF_RenderText_Solid(Sans, "Hello World", textColor);
  SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Hello World", White);
  SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);


  // Pass zero for width and height to draw the whole surface
  //SDL_Rect textLocation = { 100, 100, 0, 0 };
  
  SDL_Rect textRect;
  //textRect.x = WIDTH - textSurface->w * 1;
  //textRect.x = 100;
  textRect.x = 0;
  //textRect.y = HEIGHT - textSurface->h * 1;
  textRect.y = 0;
  textRect.w = textSurface->w;
  textRect.h = textSurface->h;
  SDL_Log("textRect x %d",textRect.x);
  SDL_Log("textRect y %d",textRect.y);
  SDL_Log("textRect w %d",textRect.w);
  SDL_Log("textRect h %d",textRect.h);
  SDL_FreeSurface(textSurface);

  TTF_Quit();
  
  bool isRunning = true;
  while (isRunning)
  {
    // Get the next event
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        isRunning = false;
        // Break out of the loop on quit
        break;
      }
      //SDL_Log("render"); //test console log
      // Set the color to cornflower blue and clear
      SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
      //SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
      // Clear window
      SDL_RenderClear( renderer );
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      // rect
      //SDL_RenderDrawRect(renderer, &rect);
      SDL_RenderFillRect(renderer, &rect);

      //SDL_BlitSurface(textSurface, NULL, renderer, &textLocation);
      SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

      // Show the renderer contents
      SDL_RenderPresent(renderer);
    }
  }
  //
  //SDL_FreeSurface(textSurface);
  
  //TTF_Quit();

  TTF_CloseFont(font);

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}