//"used only to test out sprite animation"

//below is dimentions of a single backgound frame in pixels
//width - 256
//height - 128

//play button dimentions below
//width - 72
//height - 25

//other button dimentions below
//width - 39
//height - 22

//errors & issues
// - when clicking one option, then another, sprite sheet gets offest
// - play_button_pos seems to place the sprite with an offset. the press_zone is a hardcoded location to get it right.
// - when starting to click one button, then click another, the sprite sheet moves horizontally


#include "raylib.h"


void animate_button(int *frame_counter, int *texture_location_x, int frame_width, Rectangle *frame, Rectangle *button_pos, bool *animation_complete, int *outer_frame_counter, bool *type_of_button);
void animate_background(int *frame_counter, int *texture_location_x, int frame_width, Rectangle *frame );

int main(){

const int window_width = { 2560 / 2 };
const int window_height = { 1280 / 2 };

InitWindow(window_width, window_height, "Animation test:");
SetTargetFPS(60);

Texture2D gameplay_background = LoadTexture("assets/textures/midnight_drive_still.png");
Texture2D background = LoadTexture("assets/textures/midnight_drive_title_screen_animated.png");
Texture2D play_button = LoadTexture("assets/textures/play_button.png");
Texture2D settings_button = LoadTexture("assets/textures/settings_logo_1.png");
Texture2D exit_button = LoadTexture("assets/textures/exit_logo_1.png");
Texture2D dirt = LoadTexture("assets/textures/dirt_1.png");
Texture2D car_green = LoadTexture("assets/textures/car_green.png");
Texture2D car_blue = LoadTexture("assets/textures/car_blue.png");

const int background_frame_width = { 256 };
const int background_frame_height = { 128 };
const int play_button_frame_width = { 72 };
const int play_button_frame_height = { 21 };
const int other_button_frame_width = { 39 };
const int other_button_frame_height = { 22 };

int background_texture_location_x = { 0 };
int background_texture_location_y = { 0 };
int button_texture_location_x = { 0 };
int button_texture_location_y = { 0 };
int outer_frame_counter = { 0 };
int frame_counter = { 0 };
int frame_counter_2 = { 0 };
int frame_counter_3 = { 0 };
int frame_counter_4 = { 0 };

float speed = 10.0f;

bool play_button_clicked = { false };
bool settings_button_clicked = { false };
bool exit_button_clicked = { false };
bool animation_complete = { false };

Rectangle game_screen = { 0, 0, window_width, window_height };
Rectangle background_frame = { background_texture_location_x, background_texture_location_y, background_frame_width, background_frame_height};
Rectangle play_button_frame = { button_texture_location_x, button_texture_location_y, play_button_frame_width, play_button_frame_height};
Rectangle play_button_pos = { 375, 200, 300, 100 };
Rectangle play_button_press_zone = { 475, window_height - 140, 300, 100 };  //for some reaon play_button_pos is offet when trying to click it. the press_zone is a hardcoded location to get it right.
Rectangle settings_button_frame = { button_texture_location_x, button_texture_location_y, other_button_frame_width, other_button_frame_height};
Rectangle settings_button_pos = { 100, 200, 200, 100 };
Rectangle settings_button_press_zone = { 200, window_height - 135, 200, 100 };

Rectangle exit_button_frame = { button_texture_location_x, button_texture_location_y, other_button_frame_width, other_button_frame_height};
Rectangle exit_button_pos = { 750  , 200, 200, 100 };
Rectangle exit_button_press_zone = { 850 , window_height - 135, 200, 100 };

Vector2 background_origin = { 0, 0 };
Vector2 play_button_origin = { -100, -300 };
Vector2 settings_button_origin = { -100, -300 };
Vector2 exit_button_origin = { -100, -300 };

Vector2 dirt_position = { window_width - 100, window_height - 100 }; 
Vector2 background_position = { -110, 0 }; 
Vector2 car_blue_position = { 0, window_height - 245 }; 
Vector2 car_green_position = { -250, window_height - 245 }; 


while(!WindowShouldClose()){


BeginDrawing();

frame_counter++;

if (animation_complete == false){
    
    animate_background(&frame_counter, &background_texture_location_x, background_frame_width, &background_frame);

    DrawTexturePro(background, background_frame, game_screen, background_origin, 0.0f, WHITE);
    DrawTexturePro(play_button, play_button_frame, play_button_pos, play_button_origin, 0.0f, WHITE);
    DrawTexturePro(settings_button, settings_button_frame, settings_button_pos, settings_button_origin, 0.0f, WHITE);
    DrawTexturePro(exit_button, exit_button_frame, exit_button_pos, exit_button_origin, 0.0f, WHITE);



    animate_button(&frame_counter_2, &button_texture_location_x, play_button_frame_width, &play_button_frame, &play_button_press_zone, &animation_complete, &outer_frame_counter, &play_button_clicked);

    animate_button(&frame_counter_3, &button_texture_location_x, other_button_frame_width, &settings_button_frame, &settings_button_press_zone, &animation_complete, &outer_frame_counter, &settings_button_clicked);

    animate_button(&frame_counter_4, &button_texture_location_x, other_button_frame_width, &exit_button_frame, &exit_button_press_zone, &animation_complete, &outer_frame_counter, &exit_button_clicked);


//DrawRectangleRec(settings_button_pos, RAYWHITE); // FOR DEBUGGING
//DrawRectangleRec(play_button_press_zone, BLACK); // FOR DEBUGGING
//DrawRectangleRec(settings_button_press_zone, BLACK); // FOR DEBUGGING
//DrawRectangleRec(exit_button_press_zone, BLACK); // FOR DEBUGGING

}
if (animation_complete == true && play_button_clicked == true){
    
    ClearBackground(GREEN);
    DrawTexturePro(gameplay_background, background_frame, game_screen, background_origin, 0.0f, WHITE);
    DrawTextureEx(dirt, (Vector2){dirt_position.x - (155 * 8), dirt_position.y}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(dirt, (Vector2){dirt_position.x - (155 * 7), dirt_position.y}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(dirt, (Vector2){dirt_position.x - (155 * 6), dirt_position.y}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(dirt, (Vector2){dirt_position.x - (155 * 5), dirt_position.y}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(dirt, (Vector2){dirt_position.x - (155 * 4), dirt_position.y}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(dirt, (Vector2){dirt_position.x - (155 * 3), dirt_position.y}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(dirt, (Vector2){dirt_position.x - (155 * 2), dirt_position.y}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(dirt, (Vector2){dirt_position.x - 155, dirt_position.y}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(dirt, dirt_position, 0.0f, 5.0f, WHITE);
    
    if (IsKeyDown(KEY_D)) car_blue_position.x += speed;
    if (IsKeyDown(KEY_A)) car_blue_position.x -= speed;
    if (IsKeyDown(KEY_RIGHT)) car_green_position.x += speed + 0.3f;
    if (IsKeyDown(KEY_LEFT)) car_green_position.x -= speed + 0.3f;
    
    
    if(car_blue_position.x > window_width / 2) 
    {
        if (IsKeyUp(KEY_D) && IsKeyUp(KEY_A)) {
            if (car_blue_position.x < window_width) DrawText("i thought i'd add some spice", 300, 200, 40, BLACK);
        }
    }
    
    if(car_green_position.x > window_width / 3) 
    {
        if (IsKeyUp(KEY_LEFT)) {
            if (car_green_position.x < window_width) DrawText("this is the spice lol", 450, 470, 40, RED);
        }
    }
    
    DrawTextureEx(car_blue, car_blue_position, 0.0f, 5.0f, WHITE);
    DrawTextureEx(car_green, car_green_position, 0.0f, 5.0f, WHITE);
 
}
if (animation_complete == true && settings_button_clicked == true){
    ClearBackground(GREEN);
    DrawText("settings button clicked!", window_width / 2, window_height / 2, 32, BLACK);
}
if (animation_complete == true && exit_button_clicked == true){
    CloseWindow();
}

 
 

EndDrawing();

}


CloseWindow();
return 0;
}

// below is a basic animator for horizontal sprite sheets (reuseable) 
void animate_background(int *frame_counter, int *texture_location_x, int frame_width, Rectangle *frame ){
    if (*frame_counter == 4){
    *texture_location_x += frame_width;
    frame->x = *texture_location_x;
    *frame_counter = 0;
    }
}


void animate_button(int *frame_counter, int *texture_location_x, int frame_width, Rectangle *frame, Rectangle *button_pos, bool *animation_complete, int *outer_frame_counter, bool *type_of_button){
    
   bool play_animation = { false };
    
    if(CheckCollisionPointRec(GetMousePosition(), *button_pos) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)){  play_animation = true;} 
        
       
       if ((play_animation == true) && (*animation_complete == false)){
            
                (*frame_counter)++;
                if (*frame_counter == 4){
                    *texture_location_x += frame_width;
                    frame->x = *texture_location_x;
                    
                    *frame_counter = 0;
                    (*outer_frame_counter)++;
                    
                    
                    if(*outer_frame_counter == 5) {  
                    *animation_complete = true;
                    *type_of_button = true;}
                 
                
            } 
           
          
        }
    
  
}