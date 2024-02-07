#include <SFML/Graphics.hpp>
#include "gameTile3.h"
#include <vector>

using namespace std;
using namespace sf;

#ifndef GAMEWORLD3_H
#define GAMEWORLD3_H

class GameWorld3 {

    Vector2i exitPos3;
    Vector2i playerPos3;
    void setUpInitialState3();
    void setUpTiles3();
    
public:
    vector< vector< GameTile3 *> > tiles;
    int gridLength3;
    GameWorld3();
};

#endif