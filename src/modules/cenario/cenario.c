#include "raylib.h"

void generateCenario(Texture2D background, float* scrollingBack, int points) {
        
    (*scrollingBack) -= 0.7f;
       
    if ((*scrollingBack) <= -background.width*2) (*scrollingBack) = 0;
       
    ClearBackground(GetColor(0x052c46ff));
    
    DrawTextureEx(background, (Vector2){ (*scrollingBack), 0 }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(background, (Vector2){ background.width*2 + (*scrollingBack), 0 }, 0.0f, 2.0f, WHITE);
    DrawText(TextFormat("Pontuação: %d", points), 1000, 15, 35, YELLOW);
};
