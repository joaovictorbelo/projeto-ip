#ifndef LOST_H
#define LOST_H
#include "lost.c"

Image loadImageOfLostScreen(int screenWidth, int screenHeight);
int DrawLostScreen(Texture2D background, Font font);

#endif
