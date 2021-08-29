#ifndef OBSTACULES_H
#define OBSTACULES_H
#include "obstacules.c"

void test_obstacules();
Obstacule* obstacules_init(int number_of_max_obstacules);
void render_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules,  Texture2D* obstacules_texture_2d);
Objective create_action_obstacule(Rectangle actual_obs, float player_x, float player_y);
float* calculate_vel_x_and_vel_y_of_the_obstacule(Objective action_obstacule, float player_x, float player_y);
Obstacule reset_position_of_the_obstacule(Obstacule obstacules);
Rectangle* return_all_rectangles_of_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules);
Image* obstacules_image(int obstacules_number_of_obstacules);
Texture2D* obstacules_texture_2d(int obstacules_number_of_obstacules, Image* obstacules_texture);
void update_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules, Texture2D* obstacules_texture_2d) ;
void init_module_obstacules();

#endif