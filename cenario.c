
#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "cenario jogo");

    
    Texture2D background = LoadTexture("src/asserts/cenario/backgroundGameplay.png");
    
    float scrollingBack = 0.0f;
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        // Update
        //----------------------------------------------------------------------------------
        scrollingBack -= 0.7f;
       
        if (scrollingBack <= -background.width*2) scrollingBack = 0;
       
        BeginDrawing();

            ClearBackground(GetColor(0x052c46ff));

           
            DrawTextureEx(background, (Vector2){ scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

            

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background); 

    CloseWindow();             
    return 0;
}