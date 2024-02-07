#include <SFML/Graphics.hpp>
#include "gameTile2.h"
#include <vector>

using namespace std;
using namespace sf;

#ifndef GAMEWORLD2_H
#define GAMEWORLD2_H

class GameWorld2 {

    Vector2i exitPos2;
    Vector2i playerPos2;
    void setUpInitialState2();
    void setUpTiles2();
    
public:
    vector< vector< GameTile2 *> > tiles2;
    int gridLength2;
    GameWorld2();
};

#endif