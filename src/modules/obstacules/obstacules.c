#include "raylib.h"
#include <stdlib.h>
#include <time.h>

Rectangle* obstacules_init(int number_of_max_obstacules) {
    int obstacules_max_number_of_obstacules = number_of_max_obstacules;
    int obstacules_number_of_obstacules = 0;
    Rectangle* obstacules_obstacules = (Rectangle*) malloc(sizeof(Rectangle) * obstacules_max_number_of_obstacules);
    
    for (int i = 0; i < obstacules_max_number_of_obstacules; i++) {
        obstacules_obstacules[i].x = 1200;
        obstacules_obstacules[i].y = -40;
        obstacules_obstacules[i].width = 20;
        obstacules_obstacules[i].height = 20;
    }
    return obstacules_obstacules;    
}

void render_obstacules(Rectangle* obstacules_obstacules, int obstacules_number_of_obstacules) {
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        DrawRectangleRec(obstacules_obstacules[i], RED);
    }
}

float* create_action_obstacule(Rectangle actual_obs, float player_x, float player_y) {
    float* action_obstacule = (float*) malloc(sizeof(float) * 2);
    action_obstacule[0] = 0;
    action_obstacule[1] = 0;
    if (actual_obs.x < player_x && actual_obs.x + actual_obs.width > player_x) {
        if (actual_obs.y < player_y && actual_obs.y + actual_obs.height > player_y) {
            action_obstacule[0] = 1;
            action_obstacule[1] = 1;
        }
    }
    return action_obstacule;
}


void test_obstacules() {
    Rectangle* obstacules_obstacules = obstacules_init(5);
    int obstacules_number_of_obstacules = 5;
    render_obstacules(obstacules_obstacules, obstacules_number_of_obstacules);
}

void update_obstacules(Rectangle* obstacules_obstacules, int obstacules_number_of_obstacules) {
    int r = 0;
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        r = rand() % 4;
        // if(r == 0) {
            obstacules_obstacules[i].x -= r;
            obstacules_obstacules[i].y += r;

        // }
    
    }
    render_obstacules(obstacules_obstacules, obstacules_number_of_obstacules);
}

void init_module_obstacules() {
    Rectangle* obstacules_obstacules = obstacules_init(5);
    int obstacules_number_of_obstacules = 5;
}
