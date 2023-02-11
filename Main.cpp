#include "Character.h"
#include "Enemy.h"
#include "Prop.h"

int main()
{

    // initializing window
    const int WinWidth{500};
    const int WinHeight{500};
    InitWindow(WinWidth, WinHeight, "Clash");
    // initializing map
    Texture2D Map{LoadTexture("nature/World.png")};
    Vector2 MapPose{0.0, 0.0};
    int MapScale{5};

    // creating player character
    Character Knight{WinWidth, WinHeight};

    // creating props
    Prop MyProps[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature/Sign.png")}};
    // creating enemies    
    Enemy Goblin{
        Vector2{800.f, 300.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")

    };
    Enemy Slime{
        Vector2{500.f, 12.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")};


    // creating an array of enemies (call by ref)
    Enemy *enemies[]{&Goblin, &Slime};

    // setting player as target for enemies
    for (auto enemy : enemies)
    {
        enemy->SetTarget(&Knight);
    }

    // main function inside a while loop
        // setting fps
    SetTargetFPS(144);
    while (!WindowShouldClose())
    {
            // Drawing every frame
        BeginDrawing();
            // clearing every frame
        ClearBackground(WHITE);
            // setting up map position and drawing the map every frame
        MapPose = Vector2Scale(Knight.GetWorldPos(), -1.f);
        DrawTextureEx(Map, MapPose, 0.0, MapScale, WHITE);
            // calling knight's tick
        Knight.Tick(GetFrameTime());
            // rendering props
        for (auto Prop : MyProps)
        {

            Prop.Render(Knight.GetWorldPos());
        }
            // game over
        if (!Knight.GetAlive())
        {
            DrawText("Game Over", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }
            // showing health
        else
        {
            string KnightHealth = "Health: ";
            KnightHealth.append(to_string(Knight.GetHealth()), 0, 5);
            DrawText(KnightHealth.c_str(), 55.f, 45.f, 40, RED);
        }
            // checking map bounds to undo the movement
        if (Knight.GetWorldPos().x < 0.f ||
            Knight.GetWorldPos().y < 0.f ||
            Knight.GetWorldPos().x + WinWidth > Map.width * MapScale ||
            Knight.GetWorldPos().y + WinHeight > Map.height * MapScale)
        {
            Knight.UndoMovement();
        }
            // checking props' collision
        for (auto Prop : MyProps)
        {
            if (CheckCollisionRecs(Prop.GetCollisionRec(Knight.GetWorldPos()), Knight.GetCollisionRec()))
            {
                Knight.UndoMovement();
            }
        }
            // calling enemies tik 
        for (auto enemy : enemies)
        {
            enemy->Tick(GetFrameTime());
        }
            // accepting input for attack
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            for (auto enemy : enemies)
            {
                if (CheckCollisionRecs(enemy->GetCollisionRec(), Knight.GetWeaponCollisionRec()))
                {
                    enemy->TakeDMG(50);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
}