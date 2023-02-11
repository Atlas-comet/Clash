#include "raylib.h"
#include "raymath.h"
#include <iostream>
using namespace std;

class Prop
{

private:
    Texture2D Texture{};
    Vector2 WorldPos{};
    float Scale { 4.f };

public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 pos);
    Rectangle GetCollisionRec(Vector2 pos);
};