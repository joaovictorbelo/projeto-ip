#ifndef ITEMS_H
#define ITEMS_H
#include "items.c"

Items* itemsInit(int number_of_max_items);
void render_items(Items* items_items, int items_number_of_items,  Texture2D* items_texture_2d);
ObjectiveItems create_action_items(Rectangle actual_obs, float player_x, float player_y);
float* calculate_vel_x_and_vel_y_of_the_items(ObjectiveItems action_items, float player_x, float player_y);
Items reset_position_of_the_items(Items items, float playerX);
Rectangle* return_all_rectangles_of_items(Items* items_items, int items_number_of_items);
Image* items_image(int items_number_of_items);
Texture2D* items_texture_2d(int items_number_of_items, Image* items_texture);
void update_items(Items* items_items, int items_number_of_items, Texture2D* items_texture_2d, float playerX);
void init_module_items();

#endif
