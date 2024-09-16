#include "../include/Ball.hpp"

//color for ball
Color Yellow = Color{243,213,91,255};

void Ball::DrawBall(ballInfo* info){
    DrawCircle(info->x,info->y,info->radius,Yellow);
}

void Ball::UpdateBall(ballInfo* info){
    info->x += info->x_speed;
    info->y += info->y_speed;

    //change direction to maintain the ball inside the window
    if(info->y + info->radius >= GetScreenHeight() || info->y - info->radius <=0){
        info->y_speed *=-1;
    }
    if(info->x + info->radius >= GetScreenWidth()){ 
        info->cpu_score++;
        info->x_speed *=-1;
    }
    if(info->x - info->radius <=0){
        info->player_score++;
        info->x_speed*=-1;
    }
}