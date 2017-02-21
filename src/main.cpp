#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "main.h"
#include "ui.h"
#include "params.h"

SDL_Surface *screen = NULL;
SDL_Event event;


int main(int argc, char* args[])
{
  if(!init())
    printf("Error failed to initialize the program!");

  return 0;
}

bool init(void)
{
  if(!ui_init())
    return false;

  return true;
}
