#include "raylib.h"

//Image loadImageVictoryScreen(int screenWidth, int screenHeight) {
//    Image image = LoadImage("./src/asserts/victory/lost_screen.png");
//    ImageResize(&image, screenWidth, screenHeight);
//    return image;
//}

int drawVictoryScreen(Texture2D background, Font font) {
    DrawTexture(background, 0.0, 0.0, WHITE);
    
    Vector2 postionOfRestart = {50,660};
    Vector2 positionOfBackMenu = {50,680};
    int choice = -1;
   
    DrawTextEx(font, "Pressione [ENTER] para jogar de novo!",postionOfRestart, 18, 0, YELLOW); 
    DrawTextEx(font, "Pressione [SPACE] para voltar ao menu!",positionOfBackMenu, 18, 0, YELLOW);

    if (IsKeyPressed(KEY_ENTER)) choice = 1;
    
    if (IsKeyDown(KEY_SPACE)) choice = 0;
   
     
    
    return choice;
}