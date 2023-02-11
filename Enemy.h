#ifndef ENEMY_H
#define ENEMY_H

#include "GenericCharacter.h"
#include "Character.h"

class Enemy : public GenericCharacter{

private:
    Character* Target; // setting up the Enemy's target through call by ref
    float Radius{50.f};

public:
    Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex);
    virtual void Tick(float deltatime) override;
    void SetTarget(Character* target){Target = target;}
    virtual Vector2 GetScreenPos() override;
    float GetHealth() const { return Health; }
    virtual float GetDMG_PS() const { return DMG_PS; }
    virtual float SetDMG_PS(float dmg_ps) { return DMG_PS = dmg_ps; }
    virtual float SetHealth(float health) { return Health = health; }
    virtual void TakeDMG(float dmg);
};

#endif