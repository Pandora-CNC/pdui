#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

#include "styles.h"
#include "params.h"

int styles_font_default_size = 12;
TTF_Font *styles_font_default = NULL;
int styles_font_bold_size = styles_font_default_size;
TTF_Font *styles_font_bold = NULL;
int styles_font_header_size = 20;
TTF_Font *styles_font_header = NULL;

SDL_Color styles_color_text_main = {0, 0, 0};

bool styles_init(void)
{
  std::string font_default_path = FONTS_DIR;
  font_default_path += "/Vera.ttf";
  styles_font_default = TTF_OpenFont(font_default_path.c_str(), styles_font_default_size);
  if(!styles_font_default) {
    styles_cleanup();
    printf("Error: Cannot open font %s ('%s')!\n", "default", font_default_path.c_str());
    return false;
  }

  std::string font_bold_path = FONTS_DIR;
  font_bold_path += "/VeraBd.ttf";
  styles_font_bold = TTF_OpenFont(font_bold_path.c_str(), styles_font_bold_size);
  if(!styles_font_bold) {
    styles_cleanup();
    printf("Error: Cannot open font %s ('%s')!\n", "bold", font_bold_path.c_str());
    return false;
  }

  std::string font_header_path = FONTS_DIR;
  font_header_path += "/VeraBd.ttf";
  styles_font_header = TTF_OpenFont(font_header_path.c_str(), styles_font_header_size);
  if(!styles_font_header) {
    styles_cleanup();
    printf("Error: Cannot open font %s ('%s')!\n", "header", font_header_path.c_str());
    return false;
  }

  return true;
}

void styles_cleanup(void)
{
  if(styles_font_default)
    TTF_CloseFont(styles_font_default);
  if(styles_font_bold)
    TTF_CloseFont(styles_font_bold);
  if(styles_font_header)
    TTF_CloseFont(styles_font_header);
}
