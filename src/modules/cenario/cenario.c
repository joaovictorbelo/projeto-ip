#include "raylib.h"
#include "../obstacules/obstacules.h"
#include "../items/items.h"
#define NUMBER_OF_OBSTACLES 4

void generateCenario(Texture2D background, float* scrollingBack, int points, Obstacule* obstacules_obstacules, Texture2D* obstacules_texture_2d, Items* items_items, Texture2D* items_texture_2d) { 
    
    (*scrollingBack) -= 0.7f;
       
    if ((*scrollingBack) <= -background.width*2) (*scrollingBack) = 0;
       
    ClearBackground(GetColor(0x052c46ff));
    
    DrawTextureEx(background, (Vector2){ (*scrollingBack), 0 }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(background, (Vector2){ background.width*2 + (*scrollingBack), 0 }, 0.0f, 2.0f, WHITE);
    DrawText(TextFormat("Pontuação: %i", (int)points), 1000, 15, 35, YELLOW);

    update_obstacules(obstacules_obstacules, NUMBER_OF_OBSTACLES, obstacules_texture_2d);
    update_items(items_items, 1, items_texture_2d);
    
}
