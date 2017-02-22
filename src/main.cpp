#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "main.h"
#include "ui.h"
#include "styles.h"
#include "params.h"

SDL_Event event;

int main(int argc, char* args[])
{
  if(!init()) {
    printf("Error: Failed to initialize the program!\nExiting.\n");
    return -1;
  }

  ui_clear(ui_get_pixcolor_rgb(0xFF, 0xFF, 0xFF));
  ui_draw_str_solid("Hello World!", screen, styles_font_header, ui_get_pixcolor(&styles_color_text_main), 10, 5, NULL);
  ui_draw_str_solid("Hello MadModder.net!", screen, styles_font_bold, ui_get_pixcolor(&styles_color_text_main), 10, 35, NULL);
  ui_draw_str_solid("Hello GitHub!", screen, styles_font_default, ui_get_pixcolor(&styles_color_text_main), 10, 55, NULL);
  SDL_Surface *img = IMG_Load("./assets/madmodder.png");
  if(img != NULL)
    ui_blit(img, screen, 10, 80, NULL);

  SDL_Flip(screen);

  while(1);

  return 0;
}

bool init(void)
{
  if(SDL_Init(SDL_INIT_VIDEO) == -1) {
    printf("Error: Couldn't initialize SDL!\n");
    return false;
  }

  SDL_Surface *screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  if(screen == NULL) {
    printf("Error: Couldn't initialize the screen surface!\n");
    return false;
  }

  if(TTF_Init() == -1) {
    printf("Error: Couldn't initialize SDL_ttf!\n");
    return false;
  }

  if(!ui_init(screen)) {
    printf("Error: Couldn't initialize the UI!\n");
    return false;
  }

  return true;
}

void cleanup()
{
  ui_cleanup();

  TTF_Quit();
  SDL_Quit();
}
