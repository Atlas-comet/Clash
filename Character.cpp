#include "Character.h"


// Constructor                                      // Initializer list
Character::Character(int WinWidth, int WinHeight) : WindowWidth(WinWidth),
                                                    WindowHight(WinHeight)
{

        // setting up width and height
    Width = DefaultTexture.width / MaxFrames;
    Height = DefaultTexture.height;
}

// getting screen positions
Vector2 Character::GetScreenPos()
{

    return Vector2{
        static_cast<float>(WindowWidth) / 2.f - Scale * (0.5f * Width),
        static_cast<float>(WindowHight) / 2.f - Scale * (0.5f * Height)};
}

// Tick function
void Character::Tick(float deltatime)
{
        // checking if alive
    if(!GetAlive()) return;
        // accepting input and conditions
    if (IsKeyDown(KEY_A))
        Velocity.x -= 1.f;
    if (IsKeyDown(KEY_D))
        Velocity.x += 1.f;
    if (IsKeyDown(KEY_W))
        Velocity.y -= 1.f;
    if (IsKeyDown(KEY_S))
        Velocity.y += 1.f;

        // calling parent tick function after input
    GenericCharacter::Tick(deltatime);

        // Setting up weapon
    Vector2 Origin{};
    Vector2 Offset{};
    float Rotation{};
    if (CharDir > 0.f)
    {

        Origin = {0.f, Weapon.height * Scale};
        Offset = {35.f, 55.f};
        WeaponCollisionRec = {GetScreenPos().x + Offset.x,
                              GetScreenPos().y + Offset.y - Weapon.height * Scale,
                              Weapon.width * Scale,
                              Weapon.height * Scale};

        Rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? 35.f : 0.f;
    }
    else
    {
        Origin = {Weapon.height * Scale, Weapon.height * Scale};
        Offset = {25.f, 55.f};
        WeaponCollisionRec = {
            GetScreenPos().x + Offset.x - Weapon.width * Scale,
            GetScreenPos().y + Offset.y - Weapon.height * Scale,
            Weapon.width * Scale,
            Weapon.height * Scale};
        Rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? -35.f : 0.f;
    }
        // Drawing weapon
    Rectangle Source{0.f, 0.f, static_cast<float>(Weapon.width) * CharDir, static_cast<float>(Weapon.height)};
    Rectangle Dest{GetScreenPos().x + Offset.x, GetScreenPos().y + Offset.y, Weapon.width * Scale, Weapon.height * Scale};
    DrawTexturePro(Weapon, Source, Dest, Origin, Rotation, WHITE);
}

// taking damage function
void Character::TakeDMG(float dmg){
    if(Health != 0){
        Health -= dmg;
        if(Health <= 0){
            SetAlive(0);
        }
    }
}