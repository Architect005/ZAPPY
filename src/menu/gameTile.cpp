#include "gameTile.h"

GameTile::GameTile(string textureName, float x, float y, bool passable, bool exit) {
    if (!setUpSprite(textureName)) {
        return;
    }
    pos = Vector2f(x,y);
    sprite.setPosition(pos);
    isPassable = passable;
    isExit = exit;
}
    int x = 0;
bool GameTile::setUpSprite(string textureName) {
    if(!texture.loadFromFile(textureName)) {
        return false;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,128,128));
    return true;
}