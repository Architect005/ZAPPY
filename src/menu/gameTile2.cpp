#include "gameTile2.h"

GameTile2::GameTile2(string textureName2, float x2, float y2, bool passable2, bool exit2) {
    if (!setUpSprite2(textureName2)) {
        return;
    }
    pos2 = Vector2f(x2,y2);
    sprite2.setPosition(pos2);
    isPassable2 = passable2;
    isExit2 = exit2;
}

bool GameTile2::setUpSprite2(string textureName2) {
    if(!texture2.loadFromFile(textureName2)) {
        return false;
    }
    texture2.setSmooth(true);
    sprite2.setTexture(texture2);
    sprite2.setTextureRect(IntRect(0,0,128,128));
    return true;
}