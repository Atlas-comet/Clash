#include "Enemy.h"

// Enemy constructor (Initializing variables with primary values )
Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex)
{
    WorldPos = pos;
    DefaultTexture = idle_tex;
    Idle = idle_tex;
    Run = run_tex;
    Width = DefaultTexture.width / MaxFrames;
    Height = DefaultTexture.height;
    Speed = 1.5f;
}

// Tick function
void Enemy::Tick(float deltatime)
{
        // checking if alive
    if(!GetAlive()) return;

        // calculating velocity
    Velocity = Vector2Subtract(Target->GetScreenPos(), GetScreenPos());

        // check if near player
    if(Vector2Length(Velocity) < Radius) Velocity={0};

        // collision check
    if(CheckCollisionRecs(Target->GetCollisionRec(),GetCollisionRec())) Target->TakeDMG(DMG_PS*deltatime);

        // parent tick
    GenericCharacter::Tick(deltatime);
}

// getting screen position
Vector2 Enemy::GetScreenPos()
{
    return Vector2Subtract(WorldPos, Target->GetWorldPos());
}

// taking damage
void Enemy::TakeDMG(float dmg)
{
    if (Health != 0)
    {
        Health -= dmg;
        if (Health <= 0)
        {
            SetAlive(0);
        }
    }
}