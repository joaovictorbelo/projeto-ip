#include "raylib.h"

Image loadImageOfLostScreen(int screenWidth, int screenHeight) {
    Image image = LoadImage("./src/asserts/lost/lost_screen.png");
    ImageResize(&image, screenWidth, screenHeight);
    return image;
}

void DrawLostScreen(Texture2D background) {
    DrawTexture(background, 0.0, 0.0, WHITE);
};
