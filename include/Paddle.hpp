#pragma once
#include "../bin/include/raylib.h"

struct WallPaddle{
    Vector2 pos;
    Rectangle rect;
    int y_speed;
};

class Paddle{
    public:
        void DrawPaddle(WallPaddle* paddle);
        void updatePlayerPaddle(WallPaddle* paddle);
        void updateCpuPaddle(WallPaddle* paddle,float ball_y);
};