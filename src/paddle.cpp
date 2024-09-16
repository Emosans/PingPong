#include "../include/Paddle.hpp"

void Paddle::DrawPaddle(WallPaddle* paddle){
    DrawRectangleRounded(Rectangle{paddle->pos.x,paddle->pos.y,paddle->rect.width,paddle->rect.height},0.8,0,WHITE);
}

void Paddle::updatePlayerPaddle(WallPaddle* paddle){
    //move the paddle according to arrow keys
    if(IsKeyDown(KEY_UP)){
        paddle->pos.y -= paddle->y_speed;
    }
    if(IsKeyDown(KEY_DOWN)){
        paddle->pos.y += paddle->y_speed;
    }
    
    //limit the paddle inside the window
    if(paddle->pos.y<=0){
        paddle->pos.y=0;
    }
    if(paddle->pos.y + paddle->rect.height > GetScreenHeight()){
        paddle->pos.y = GetScreenHeight() - paddle->rect.height;
    }
}

void Paddle::updateCpuPaddle(WallPaddle* paddle, float ball_y){
    if(paddle->pos.y + paddle->rect.height/2 > ball_y){
        paddle->pos.y -= paddle->y_speed;
    }
    if(paddle->pos.y + paddle->rect.height/2 <= ball_y){
        paddle->pos.y += paddle->y_speed;
    }

    //limit the paddle inside the window
    if(paddle->pos.y<=0){
        paddle->pos.y=0;
    }
    if(paddle->pos.y + paddle->rect.height > GetScreenHeight()){
        paddle->pos.y = GetScreenHeight() - paddle->rect.height;
    }
}