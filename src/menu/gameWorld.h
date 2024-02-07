#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

using namespace std;
using namespace sf;

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld {

    Vector2i exitPos;
    Vector2i playerPos;
    void setUpInitialState();
    void setUpTiles();
    
public:
    vector< vector< GameTile *> > tiles;
    int gridLength;
    GameWorld();
};

#endif