#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef GAMETILE2_H
#define GAMETILE2_H

class GameTile2 {

    public:
        bool isPassable2;
        bool isExit2;
        Vector2f pos2;
        Texture texture2;
        Sprite sprite2;
        GameTile2(string, float, float, bool, bool);
        bool setUpSprite2(string);
};

#endif