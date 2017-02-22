#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

#include "ui.h"
#include "styles.h"

SDL_Surface *screen = NULL;
SDL_Surface *ui_background = NULL;

bool ui_init(SDL_Surface *ext_screen)
{
  screen = ext_screen;

  if(!styles_init())
    return false;

  return true;
}

void ui_cleanup(void)
{
  styles_cleanup();
}

int ui_get_pixcolor(SDL_Color *color)
{
  return SDL_MapRGB(screen->format, color->r, color->g, color->b);
}

int ui_get_pixcolor_rgb(unsigned char r, unsigned char g, unsigned char b)
{
  return SDL_MapRGB(screen->format, r, g, b);
}

int ui_get_pixcolor_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
  return SDL_MapRGBA(screen->format, r, g, b, a);
}

bool ui_map_pixcolor(int pixcolor, SDL_Color *color)
{
  if(color == NULL)
    return false;
  unsigned char r, g, b;
  SDL_GetRGB(pixcolor, screen->format, &r, &g, &b);
  color->r = r;
  color->g = g;
  color->b = b;
  return true;
}

bool ui_clear(int pixcolor)
{
  SDL_FillRect(screen, NULL, pixcolor);
}

bool ui_blit(SDL_Surface *source, SDL_Surface *buffer, int x, int y, SDL_Rect *clip)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  return (SDL_BlitSurface(source, clip, buffer, &offset) != -1);
}

bool ui_draw_str_solid(std::string str, SDL_Surface *buffer, TTF_Font *font, int pixcolor, int x, int y, SDL_Rect *clip)
{
  SDL_Color color;
  SDL_Surface *surface = NULL;
  ui_map_pixcolor(pixcolor, &color);

  if((surface = TTF_RenderText_Solid(font, str.c_str(), color)) == NULL)
    return false;

  return ui_blit(surface, buffer, x, y, clip);
}
