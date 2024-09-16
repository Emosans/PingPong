#include "../bin/include/raylib.h"
#include "../include/Ball.hpp"
#include "../include/Paddle.hpp"

//colors
Color Dark_Green = Color{20,160,133,255};
Color Light_Green = Color{129,185,154,255};
Color Green = Color{28,185,154,255};

int main(){
    //variables
    const int screenHeight = 800;
    const int screenWidth = 1280;

    //struct objects
    ballInfo info;
    WallPaddle playerwallpaddle;
    WallPaddle cpuwallpaddle;

    //class objects
    Ball ball;
    Paddle paddle;

    //window initialisation
    InitWindow(screenWidth,screenHeight,"PingPong");

    //initialise ball struct values
    info.x = screenWidth/2;
    info.y = screenHeight/2;
    info.radius=20;
    info.x_speed = 7;
    info.y_speed=7;

    //initialise player paddle struct values
    playerwallpaddle.rect.width = 25;
    playerwallpaddle.rect.height = 120;
    playerwallpaddle.pos = {GetScreenWidth()-playerwallpaddle.rect.width-10,(float)GetScreenHeight()/2 - playerwallpaddle.rect.height/2};
    playerwallpaddle.y_speed = 7;

    //initialise cpu paddle struct values
    cpuwallpaddle.rect.width = 25;
    cpuwallpaddle.rect.height = 120;
    cpuwallpaddle.pos = {10,(float)GetScreenHeight()/2 - cpuwallpaddle.rect.height/2};
    cpuwallpaddle.y_speed = 7;

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        ball.UpdateBall(&info);
        paddle.updatePlayerPaddle(&playerwallpaddle);
        paddle.updateCpuPaddle(&cpuwallpaddle,info.y);

        //check for collisions
        if(CheckCollisionCircleRec(Vector2{info.x,info.y},info.radius,Rectangle{playerwallpaddle.pos.x,playerwallpaddle.pos.y,playerwallpaddle.rect.width,playerwallpaddle.rect.height})){
            info.x_speed*=-1;
        }
        if(CheckCollisionCircleRec(Vector2{info.x,info.y},info.radius,Rectangle{cpuwallpaddle.pos.x,cpuwallpaddle.pos.y,cpuwallpaddle.rect.width,cpuwallpaddle.rect.height})){
            info.x_speed*=-1;
        }

        BeginDrawing();
        ClearBackground(Dark_Green);
        DrawRectangle(screenWidth/2,0,screenWidth/2,screenHeight,Green);
        DrawCircle(screenWidth/2,screenHeight/2,150,Light_Green);
        ball.DrawBall(&info);
        paddle.DrawPaddle(&playerwallpaddle);
        paddle.DrawPaddle(&cpuwallpaddle);
        DrawLine(screenWidth/2,0,screenWidth/2,screenHeight,WHITE);
        DrawText(TextFormat("%i",info.cpu_score),screenWidth/4,20,35,WHITE);
        DrawText(TextFormat("%i",info.player_score),3*screenWidth/4,20,35,WHITE);
        EndDrawing();
    }

    CloseWindow();
    return(0);
}