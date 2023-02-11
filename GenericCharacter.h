#ifndef GENERIC_CHARACTER_H
#define GENERIC_CHARACTER_H

#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <string.h>
using namespace std;

class GenericCharacter {
protected:
    // initializing basic char attributes
        // textures
    Texture2D DefaultTexture {LoadTexture("characters/knight_idle_spritesheet.png")}; 
    Texture2D Idle {LoadTexture("characters/knight_idle_spritesheet.png")}; 
    Texture2D Run {LoadTexture("characters/knight_run_spritesheet.png")}; 
        // settup positions
    Vector2 ScreenPos{};
    Vector2 WorldPos{};
    Vector2 WorldPL{};
        // Velocity and character direction
    Vector2 Velocity{};
    float CharDir{1.f};
    float Speed{4};
        // animation settings
    float Runningtime{};
    int Frame{};
    int MaxFrames{6};
    float AnimUpdateRate{0.1};
        // base transform
    float Width{};
    float Height{};
    float Scale{4.f};
        // Damage and health
    float Health{100.f};
    float DMG_PS{10.f};
    

public:
    // Initializing char funcationality
        // constructor
    GenericCharacter();
        // settup positions
    Vector2 GetWorldPos() const {return WorldPos;}
    virtual Vector2 GetScreenPos() = 0;
        // collision and stop movement
    void UndoMovement();
    Rectangle GetCollisionRec();
        // Damage and health
    bool GetAlive() const { return Alive; }
    bool SetAlive(bool alive) { return Alive = alive; }
    float GetHealth() const { return Health;}
    virtual float GetDMG_PS() const { return DMG_PS;}
    virtual float SetDMG_PS(float dmg_ps) { return DMG_PS = dmg_ps; }
    virtual float SetHealth(float health) {return Health = health;}
    virtual void TakeDMG(float dmg) = 0;
        // Tick
    virtual void Tick(float deltatime);

private:
    // is alive
    bool Alive{1};
};

#endif