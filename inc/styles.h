#ifndef STYLES_H
#define STYLES_H

#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

extern TTF_Font *styles_font_main;
extern TTF_Font *styles_font_header;
bool styles_init(std::string font_dir, std::string assets_dir);

#endif
