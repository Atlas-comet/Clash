#ifndef CHARACTER_H
#define CHARACTER_H

#include "GenericCharacter.h"

class Character : public GenericCharacter 
{

public:
    // Initializing char funcationality
    Character(int WinWidth, int WinHeight);
    virtual void Tick(float deltatime) override;
    virtual Vector2 GetScreenPos() override;
    Rectangle GetWeaponCollisionRec(){return WeaponCollisionRec;}
    float GetHealth() const { return Health; }
    virtual float GetDMG_PS() const { return DMG_PS; }
    virtual float SetDMG_PS(float dmg_ps) { return DMG_PS = dmg_ps; }
    virtual float SetHealth(float health) { return Health = health; }
    virtual void TakeDMG(float dmg);

private:

    int WindowWidth{};
    int WindowHight{};

    // setting up weapon
    Texture2D Weapon { LoadTexture("characters/weapon_sword.png") };
    Rectangle WeaponCollisionRec{};
};

#endif