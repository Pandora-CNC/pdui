#ifndef UI_H
#define UI_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

extern SDL_Surface *screen;

bool ui_init(SDL_Surface *ext_screen);
void ui_cleanup(void);

int ui_get_pixcolor(SDL_Color *color);
int ui_get_pixcolor_rgb(unsigned char r, unsigned char g, unsigned char b);
int ui_get_pixcolor_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
bool ui_map_pixcolor(int pixcolor, SDL_Color *color);

bool ui_clear(int pixcolor);
bool ui_blit(SDL_Surface *source, SDL_Surface *buffer, int x, int y, SDL_Rect *clip);
bool ui_draw_str_solid(std::string str, SDL_Surface *buffer, TTF_Font *font, int pixcolor, int x, int y, SDL_Rect *clip);

#endif
