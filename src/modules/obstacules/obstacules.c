#include "raylib.h"
#include <stdlib.h>
#include <time.h>


typedef struct {
    float x;
    float y;
} Objective;
typedef struct {
    Rectangle rect;
    Objective objective;
    int is_active;
} Obstacule;

Obstacule* obstacules_init(int number_of_max_obstacules) {
    Obstacule* obstacules = malloc(sizeof(Obstacule) * number_of_max_obstacules);
    for (int i = 0; i < number_of_max_obstacules; i++) {
        obstacules[i].rect.x = 900;
        obstacules[i].rect.y = 300 *(i + 1);
        obstacules[i].rect.width = 40;
        obstacules[i].rect.height = 40;
        obstacules[i].objective.x = -1;
        obstacules[i].objective.y = -1;
        obstacules[i].is_active = 0;
    }
    return obstacules;    
}

void render_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules) {
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        if(i == 0) {
            DrawRectangleRec(obstacules_obstacules[i].rect, RED);
            // printf("%f\n", obstacules_obstacules[i].y);
        } else {
            DrawRectangleRec(obstacules_obstacules[i].rect, GREEN);

        }
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

Obstacule reset_position_of_the_obstacule(Obstacule obstacules) {  
    obstacules.rect.x = 900;
    obstacules.rect.y = 300;
    obstacules.objective.x = -1;
    obstacules.objective.y = -1;
    obstacules.is_active = 1;
    return obstacules;
}

void test_obstacules() {
    Rectangle* obstacules_obstacules = obstacules_init(5);
    int obstacules_number_of_obstacules = 5;
    render_obstacules(obstacules_obstacules, obstacules_number_of_obstacules);
}
Rectangle* return_all_rectangles_of_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules) {
    Rectangle* all_rectangles_of_obstacules = NULL;
    all_rectangles_of_obstacules = (Rectangle*) malloc(sizeof(Rectangle) * obstacules_number_of_obstacules);
    
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        all_rectangles_of_obstacules[i] = obstacules_obstacules[i].rect;
    }
    return all_rectangles_of_obstacules;
}

void update_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules) {
    int r = 0;
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {

        if(obstacules_obstacules[i].rect.y > 700) { 
            obstacules_obstacules[i] = reset_position_of_the_obstacule(obstacules_obstacules[i]);
        }
        else {
            // if(i == 1) {
                // printf("pos y: %f, pox x: %f,is_ativate: %d\n", obstacules_obstacules[i].rect.y, obstacules_obstacules[i].rect.x ,obstacules_obstacules[i].is_active);
            // }
            obstacules_obstacules[i].is_active = 1;
            
            if(obstacules_obstacules[i].is_active == 1) {
                obstacules_obstacules[i].rect.y += rand() % 2;
            }
        }
        // obstacules_obstacules[i].x -= r;
        // obstacules_obstacules[i].y += r;    
    }
    render_obstacules(obstacules_obstacules, obstacules_number_of_obstacules);
}

void init_module_obstacules() {
    Rectangle* obstacules_obstacules = obstacules_init(5);
    int obstacules_number_of_obstacules = 5;
}
