#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "../personagem/personagem.h"

typedef struct {
    float vx;
    float vy;
} Velocities;

typedef struct {
    Rectangle rect;
    Velocities velocities;
    int is_active;
    int should_send_new_velocities;
} Obstacule;

Obstacule* obstacules_init(int number_of_max_obstacules, Texture2D* texturesObs) {
    Obstacule* obstacules = malloc(sizeof(Obstacule) * number_of_max_obstacules);
    for (int i = 0; i < number_of_max_obstacules; i++) {
        obstacules[i].rect.x = rand() % 901;
        obstacules[i].rect.y = -20;
        obstacules[i].rect.width = texturesObs[i].width;
        obstacules[i].rect.height = texturesObs[i].height;
        obstacules[i].is_active = 0;
        obstacules[i].should_send_new_velocities = 1;
    }
    return obstacules;    
};

void render_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules,  Texture2D* obstacules_texture_2d) {
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        DrawTexture(obstacules_texture_2d[i], obstacules_obstacules[i].rect.x, obstacules_obstacules[i].rect.y, WHITE);
    }
};

float* calculate_vel_x_and_vel_y_of_the_obstacule(Obstacule obstacule, float player_x, float player_y) {
    float* velocities = malloc(sizeof(float) * 2);
    int vel_module = (rand() % 11) + 1;
    int direction = 0;
    float tangent = 0;
    if (player_x > obstacule.rect.x) {
        direction = 1;
    } else {
        direction = -1;
    }

    float delta_x = abs(obstacule.rect.x - player_x) + (rand() % 10);
    float delta_y = abs(obstacule.rect.y - player_y);

    tangent = (delta_x + (rand() % 5)) / (delta_y + (rand() % 5) + 1);
    velocities[1] = sqrt((vel_module / tangent));
    velocities[0] = velocities[1] * tangent * direction;

    return velocities;

};

Obstacule reset_position_of_the_obstacule(Obstacule obstacules) {  
    obstacules.rect.x = rand() % 901;
    obstacules.rect.y = -20;
    obstacules.is_active = 1;
    obstacules.should_send_new_velocities = 1;

    return obstacules;
};


Rectangle* return_all_rectangles_of_obstacules(Obstacule* obstacules_obstacules, int obstacules_number_of_obstacules) {
    Rectangle* all_rectangles_of_obstacules = NULL;
    all_rectangles_of_obstacules = (Rectangle*) malloc(sizeof(Rectangle) * obstacules_number_of_obstacules);
    
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        all_rectangles_of_obstacules[i] = obstacules_obstacules[i].rect;
    }
    return all_rectangles_of_obstacules;
};

Image* obstacules_image(int obstacules_number_of_obstacules) {
    Image* obstacules_image = (Image*) malloc(sizeof(Image) * obstacules_number_of_obstacules);
    obstacules_image[0] = LoadImage("./src/asserts/obstacules/cabo_mau.png");
    obstacules_image[1] = LoadImage("src/asserts/obstacules/ciro_novo.png");
    obstacules_image[2] = LoadImage("src/asserts/obstacules/sat_mexico.png");
    obstacules_image[3] = LoadImage("src/asserts/obstacules/sat_urss.png");

    return obstacules_image;
};

Texture2D* obstacules_texture_2d(int obstacules_number_of_obstacules, Image* obstacules_texture) {
    Texture2D* obstacules_texture_2d = (Texture2D*) malloc(sizeof(Texture2D) * obstacules_number_of_obstacules);
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {
        obstacules_texture_2d[i] = LoadTextureFromImage(obstacules_texture[i]);
    }
    return obstacules_texture_2d;
};

void update_obstacules(Obstacule* obstacules_obstacules, 
                        int obstacules_number_of_obstacules, 
                        Texture2D* obstacules_texture_2d, 
                        Player player) {
    float* velocies_aux = NULL;
    for (int i = 0; i < obstacules_number_of_obstacules; i++) {

        if(obstacules_obstacules[i].rect.y > 700) { 
            obstacules_obstacules[i] = reset_position_of_the_obstacule(obstacules_obstacules[i]);
        }
        else {
            obstacules_obstacules[i].is_active = 1;
            if(obstacules_obstacules[i].should_send_new_velocities == 1) {
                obstacules_obstacules[i].should_send_new_velocities = 0;

                velocies_aux = calculate_vel_x_and_vel_y_of_the_obstacule(obstacules_obstacules[i], 
                                                            player.playerPosition.x, 
                                                            player.playerPosition.y); 
                obstacules_obstacules[i].velocities.vx = velocies_aux[0];
                obstacules_obstacules[i].velocities.vy = velocies_aux[1];
                free(velocies_aux);
            }
            
            obstacules_obstacules[i].rect.x += obstacules_obstacules[i].velocities.vx;
            obstacules_obstacules[i].rect.y += obstacules_obstacules[i].velocities.vy;

        }

    }
    render_obstacules(obstacules_obstacules, obstacules_number_of_obstacules, obstacules_texture_2d);
};

void unloadALlObstaculesImages(int NumOfObstacules, Image* imagesOfObstacules) {
    int i = 0;

    for(i = 0; i < NumOfObstacules; i++) {
        UnloadImage(imagesOfObstacules[i]);
    }

};
