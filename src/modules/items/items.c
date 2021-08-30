//Funcoes referentes aos items do jogo (inicializacao, carregamento das texturas, renderizacao etc)

#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    float x;
    float y;
} ObjectiveItems;

typedef struct {
    Rectangle rect;
    ObjectiveItems objective;
    int is_active;
    int is_bosst;
} Items;

Items* itemsInit(int number_of_max_items) {
    Items* items = malloc(sizeof(Items) * number_of_max_items);
    for (int i = 0; i < number_of_max_items; i++) {
        items[i].rect.x = rand() % 901;
        items[i].rect.y = -20;
        items[i].rect.width = 40;
        items[i].rect.height = 40;
        items[i].objective.x = -1;
        items[i].objective.y = -1;
        items[i].is_active = 1;
        if(i == 1) {
            items[i].is_bosst = 1;
        }
        else {
            items[i].is_bosst = 0;
        }
    }
    return items;    
}

void render_items(Items* items_items, int items_number_of_items,  Texture2D* items_texture_2d) {
    for (int i = 0; i < items_number_of_items; i++) {
        if(items_items[i].is_active == 1) {
            DrawTexture(items_texture_2d[i], items_items[i].rect.x, items_items[i].rect.y, WHITE);
        }
    }
}
Rectangle BoostRectangle(Items* items_items) {
    return items_items[1].rect;
}

ObjectiveItems create_action_items(Rectangle actual_obs, float player_x, float player_y) {
    ObjectiveItems action_items;
    action_items.x = player_x + (rand() % 100) - 50;
    action_items.y = player_y;
    return action_items;   
}

float* calculate_vel_x_and_vel_y_of_the_items(ObjectiveItems action_items, float player_x, float player_y) {
    float* vel_x_and_vel_y_of_the_items = (float*) malloc(sizeof(float) * 2);
    float vel_x_and_vel_y_of_the_items_x = action_items.x - player_x;
    float vel_x_and_vel_y_of_the_items_y = action_items.y - player_y;
    vel_x_and_vel_y_of_the_items[0] = vel_x_and_vel_y_of_the_items_x;
    vel_x_and_vel_y_of_the_items[1] = vel_x_and_vel_y_of_the_items_y;
    return vel_x_and_vel_y_of_the_items;
}

Items reset_position_of_the_items(Items items, float playerX) {  
    float posItem = 0;

    if(playerX > 400 && playerX < 800) posItem = rand() % 1280;
    else if(playerX >= 800) posItem = rand() % 400;
    else if(playerX <= 400) posItem = rand() % 400 + 880;

    items.rect.x = posItem;
    items.rect.y = 20;
    items.objective.x = -1;
    items.objective.y = -1;
    items.is_active = 1;
    return items;
}


Rectangle* return_all_rectangles_of_items(Items* items_items, int items_number_of_items) {
    Rectangle* all_rectangles_of_items = NULL;
    all_rectangles_of_items = (Rectangle*) malloc(sizeof(Rectangle) * items_number_of_items);
    
    for (int i = 0; i < items_number_of_items; i++) {
        all_rectangles_of_items[i] = items_items[i].rect;
    }
    return all_rectangles_of_items;
}

Image* items_image(int items_number_of_items) {
    Image* items_image = (Image*) malloc(sizeof(Image) * items_number_of_items);
    items_image[0] = LoadImage("./src/asserts/items/item_versiculo.png");
    items_image[1] = LoadImage("src/asserts/items/item_biblia.png");

    return items_image;
};

Texture2D* items_texture_2d(int items_number_of_items, Image* items_texture) {
    Texture2D* items_texture_2d = (Texture2D*) malloc(sizeof(Texture2D) * items_number_of_items);
    for (int i = 0; i < items_number_of_items; i++) {
        items_texture_2d[i] = LoadTextureFromImage(items_texture[i]);
    }
    return items_texture_2d;
}

void update_items(Items* items_items, int items_number_of_items, Texture2D* items_texture_2d, float playerX) {
    int r = 0;
    for (int i = 0; i < items_number_of_items; i++) {

        if(items_items[i].rect.y > 700) { 
            items_items[i] = reset_position_of_the_items(items_items[i], playerX);
        }
        else {
            if(items_items[i].is_active == 1) {
                if(i != 1) {
                    items_items[i].rect.y += rand() % 7;
                }
                else {
                    items_items[i].rect.y += (rand() % 15) + 1;
                }
            }
        }

    }
    render_items(items_items, items_number_of_items, items_texture_2d);
}

void unloadALlItemsImages(int NumOfItems, Image* imagesOfItems) {
    int i = 0;

    for(i = 0; i < NumOfItems; i++) {
        UnloadImage(imagesOfItems[i]);
    }

}

void init_module_items() {
    Rectangle* items_items = itemsInit(5);
    int items_number_of_items = 5;
}
