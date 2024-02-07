#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile {

    public:
        bool isPassable;
        bool isExit;
        Vector2f pos;
        Texture texture;
        Sprite sprite;
        GameTile(string, float, float, bool, bool);
        bool setUpSprite(string);
};

#endif