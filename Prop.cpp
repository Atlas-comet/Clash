#include "Prop.h"

Prop::Prop(Vector2 pos, Texture2D tex) : WorldPos(pos),
                                         Texture(tex)
{
}

void Prop::Render(Vector2 pos)
{

    Vector2 ScreenPos{Vector2Subtract(WorldPos, pos)};
    DrawTextureEx(Texture, ScreenPos, 0.f, Scale, WHITE);
}

Rectangle Prop::GetCollisionRec(Vector2 pos)
{

    Vector2 ScreenPos{Vector2Subtract(WorldPos, pos)};
    return Rectangle{
        ScreenPos.x,
        ScreenPos.y,
        Texture.width * Scale,
        Texture.height * Scale};
}