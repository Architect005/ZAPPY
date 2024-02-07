#include "gameTile3.h"

GameTile3::GameTile3(string textureName3, float x3, float y3, bool passable3, bool exit3) {
    if (!setUpSprite3(textureName3)) {
        return;
    }
    pos3 = Vector2f(x3,y3);
    sprite3.setPosition(pos3);
    isPassable3 = passable3;
    isExit3 = exit3;
}

bool GameTile3::setUpSprite3(string textureName3) {
    if(!texture3.loadFromFile(textureName3)) {
        return false;
    }
    texture3.setSmooth(true);
    sprite3.setTexture(texture3);
    sprite3.setTextureRect(IntRect(0,0,128,128));
    return true;
}