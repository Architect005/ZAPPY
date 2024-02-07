#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef GAMETILE3_H
#define GAMETILE3_H

class GameTile3 {

    public:
        bool isPassable3;
        bool isExit3;
        Vector2f pos3;
        Texture texture3;
        Sprite sprite3;
        GameTile3(string, float, float, bool, bool);
        bool setUpSprite3(string);
};

#endif