#include <stdint.h>
#include "params.h"

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 272;
const int SCREEN_BPP = 16;

#ifdef ARM
  const char* FONTS_DIR = "../fonts";
  const char* ASSETS_DIR = "../assets";
#else
  const char* FONTS_DIR = "./fonts";
  const char* ASSETS_DIR = "./assets";
#endif
