#ifndef OBSTACULES_H
#define OBSTACULES_H
#include "obstacules.c"

Obstacule* obstacules_init(int number_of_max_obstacules, Texture2D* texturesObs);
void render_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules,  Texture2D* obstacules_texture_2d);
float* calculate_vel_x_and_vel_y_of_the_obstacule(Obstacule action_obstacule, float player_x, float player_y);
Obstacule reset_position_of_the_obstacule(Obstacule obstacules);
Rectangle* return_all_rectangles_of_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules);
Image* obstacules_image(int obstacules_number_of_obstacules);
Texture2D* obstacules_texture_2d(int obstacules_number_of_obstacules, Image* obstacules_texture);
void update_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules, Texture2D* obstacules_texture_2d, Player player);
void unloadALlObstaculesImages(int NumOfObstacules, Image* imagesOfObstacules);
void init_module_obstacules();

#endif