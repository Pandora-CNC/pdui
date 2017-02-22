#ifndef STYLES_H
#define STYLES_H

#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

extern int styles_font_default_size;
extern TTF_Font *styles_font_default;
extern int styles_font_bold_size;
extern TTF_Font *styles_font_bold;
extern int styles_font_header_size;
extern TTF_Font *styles_font_header;

extern SDL_Color styles_color_text_main;

bool styles_init(void);
void styles_cleanup(void);

#endif
