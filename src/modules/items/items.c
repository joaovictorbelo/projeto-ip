#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    float x;
    float y;
} Objective;

typedef struct {
    Rectangle rect;
    Objective objective;
    int is_active;
} Items;

Items* itemsInit(int number_of_max_items) {
    Items* items = malloc(sizeof(Items) * number_of_max_items);
    for (int i = 0; i < number_of_max_items; i++) {
        items[i].rect.x = 900;
        items[i].rect.y = 10 *(i + 1);
        items[i].rect.width = 40;
        items[i].rect.height = 40;
        items[i].objective.x = -1;
        items[i].objective.y = -1;
        items[i].is_active = 0;
    }
    return items;    
}

void render_items(Items* obstacules_obstacules, int obstacules_number_of_obstacules,  Texture2D* obstacules_texture_2d) {
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        DrawTexture(obstacules_texture_2d[i], obstacules_obstacules[i].rect.x, obstacules_obstacules[i].rect.y, WHITE);
    }
}

Objective create_action_obstacule(Rectangle actual_obs, float player_x, float player_y) {
    Objective action_obstacule;
    action_obstacule.x = player_x + (rand() % 100) - 50;
    action_obstacule.y = player_y;
    return action_obstacule;   
}

float* calculate_vel_x_and_vel_y_of_the_obstacule(Objective action_obstacule, float player_x, float player_y) {
    float* vel_x_and_vel_y_of_the_obstacule = (float*) malloc(sizeof(float) * 2);
    float vel_x_and_vel_y_of_the_obstacule_x = action_obstacule.x - player_x;
    float vel_x_and_vel_y_of_the_obstacule_y = action_obstacule.y - player_y;
    vel_x_and_vel_y_of_the_obstacule[0] = vel_x_and_vel_y_of_the_obstacule_x;
    vel_x_and_vel_y_of_the_obstacule[1] = vel_x_and_vel_y_of_the_obstacule_y;
    return vel_x_and_vel_y_of_the_obstacule;
}

Items reset_position_of_the_obstacule(Items obstacules) {  
    obstacules.rect.x = 900;
    obstacules.rect.y = 20;
    obstacules.objective.x = -1;
    obstacules.objective.y = -1;
    obstacules.is_active = 1;
    return obstacules;
}


Rectangle* return_all_rectangles_of_obstacules(Items* obstacules_obstacules, int obstacules_number_of_obstacules) {
    Rectangle* all_rectangles_of_obstacules = NULL;
    all_rectangles_of_obstacules = (Rectangle*) malloc(sizeof(Rectangle) * obstacules_number_of_obstacules);
    
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        all_rectangles_of_obstacules[i] = obstacules_obstacules[i].rect;
    }
    return all_rectangles_of_obstacules;
}

Image* obstacules_image(int obstacules_number_of_obstacules) {
    Image* obstacules_image = (Image*) malloc(sizeof(Image) * obstacules_number_of_obstacules);
    obstacules_image[0] = LoadImage("./src/asserts/items/.png");
    obstacules_image[1] = LoadImage("src/asserts/items/.png");
    obstacules_image[2] = LoadImage("src/asserts/items/.png");

    return obstacules_image;
};

Texture2D* obstacules_texture_2d(int obstacules_number_of_obstacules, Image* obstacules_texture) {
    Texture2D* obstacules_texture_2d = (Texture2D*) malloc(sizeof(Texture2D) * obstacules_number_of_obstacules);
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        obstacules_texture_2d[i] = LoadTextureFromImage(obstacules_texture[i]);
    }
    return obstacules_texture_2d;
}

void update_items(Items* obstacules_obstacules, int obstacules_number_of_obstacules, Texture2D* obstacules_texture_2d) {
    int r = 0;
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {

        if(obstacules_obstacules[i].rect.y > 700) { 
            obstacules_obstacules[i] = reset_position_of_the_obstacule(obstacules_obstacules[i]);
        }
        else {
            obstacules_obstacules[i].is_active = 1;
            
            if(obstacules_obstacules[i].is_active == 1) {
                obstacules_obstacules[i].rect.y += rand() % 5;
                // obstacules_obstacules[i].rect.x -= rand() % 5;
            }
        }

    }
    render_obstacules(obstacules_obstacules, obstacules_number_of_obstacules, obstacules_texture_2d);
}

void init_module_obstacules() {
    Rectangle* obstacules_obstacules = obstacules_init(5);
    int obstacules_number_of_obstacules = 5;
}
