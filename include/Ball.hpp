#pragma once
#include "../bin/include/raylib.h"

struct ballInfo{
    float x,y;
    int radius,x_speed,y_speed;
    int cpu_score=0;
    int player_score=0;
};

class Ball{
    public:

    void DrawBall(ballInfo* info);
    void UpdateBall(ballInfo* info);
};