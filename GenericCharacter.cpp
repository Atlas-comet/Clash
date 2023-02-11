#include "GenericCharacter.h"

// Constructor defenition
GenericCharacter::GenericCharacter() {} 

// Undo movement
void GenericCharacter::UndoMovement()
{
    WorldPos = WorldPL; // setting the world pso to the last frame pos
}

// creating collision rec
Rectangle GenericCharacter::GetCollisionRec()
{
    return Rectangle{
        GetScreenPos().x,
        GetScreenPos().y,
        Width * Scale,
        Height * Scale};
}

// Tick function
void GenericCharacter::Tick(float deltatime)
{

    WorldPL = WorldPos; // setting up last location

        // updateing anim frames
    Runningtime += deltatime;
    if (Runningtime >= AnimUpdateRate)
    {

        Frame++;
        Runningtime = 0.f;
        if (Frame > MaxFrames)
        {
            Frame = 0;
        }
    }

        // changing character direction
    if (Vector2Length(Velocity) != 0.0)
    {

        WorldPos = Vector2Add(WorldPos, Vector2Scale(Vector2Normalize(Velocity), Speed)); // setting world position based on speed and velcoity
        Velocity.x < 0.f ? CharDir = -1.f : CharDir = 1.f;
        DefaultTexture = Run;
    }
    else
    {

        DefaultTexture = Idle;
    }

        // after reaching the end position set velocity to 0
    Velocity = {};

        // Drawing Character
    Rectangle Source{Frame * Width, 0.f, CharDir * Width, Height};
    Rectangle Dest{GetScreenPos().x, GetScreenPos().y, Scale * Width, Scale * Height};
    DrawTexturePro(DefaultTexture, Source, Dest, Vector2{}, 0.f, WHITE);
}