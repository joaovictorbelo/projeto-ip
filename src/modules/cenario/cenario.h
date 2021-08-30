#ifndef CENARIO_H
#define CENARIO_H
#include "cenario.c"


void generateCenario(Texture2D background, float* scrollingBack, int points, Obstacule* obstacules_obstacules, 
    Texture2D* obstacules_texture_2d, Items* items_items, Texture2D* items_texture_2d, Player player, int *delayFrames);

#endif