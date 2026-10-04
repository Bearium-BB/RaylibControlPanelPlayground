#include <raylib.h>
#include "WebSearchingWidget.hpp"
#include "GameState.hpp"


int main()
{
    InitWindow(1080, 607, "Beargle");

    SetTargetFPS(60);


	WebSearchingWidget webSearchingWidget(100, 140, 10, 15, 50);

    while (!WindowShouldClose() && GameState::isRun)
    {
        webSearchingWidget.Update();

        BeginDrawing();

        webSearchingWidget.Draw();

        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

}