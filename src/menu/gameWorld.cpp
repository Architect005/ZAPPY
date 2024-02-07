#include "gameWorld.h"
#include "gameTile.h"

GameWorld::GameWorld() {
    gridLength = 10;
    setUpInitialState();
}

void GameWorld::setUpInitialState() {
    exitPos = Vector2i(1,0);
    playerPos = Vector2i(gridLength-1, gridLength-1);
    setUpTiles();
}

void GameWorld::setUpTiles() {
    tiles.clear();
    
    vector<GameTile *> firstRow;
    firstRow.push_back(new GameTile("src/menu/Sol.png",0,0,false,false));
    firstRow.push_back(new GameTile("src/menu/Sol.png",100,0,true,true));
    firstRow.push_back(new GameTile("src/menu/Sol.png",200,0,false,false));
    firstRow.push_back(new GameTile("src/menu/Sol.png",300,0,false,false));
    firstRow.push_back(new GameTile("src/menu/Sol.png",400,0,false,false));
    firstRow.push_back(new GameTile("src/menu/Sol.png",500,0,false,false));
    firstRow.push_back(new GameTile("src/menu/Sol.png",600,0,false,false));
    firstRow.push_back(new GameTile("src/menu/Sol.png",700,0,false,false));
    firstRow.push_back(new GameTile("src/menu/Sol.png",800,0,false,false));
    firstRow.push_back(new GameTile("src/menu/Sol.png",850,0,false,false));
    tiles.push_back(firstRow);

    vector<GameTile *> secondRow;
    secondRow.push_back(new GameTile("src/menu/Sol.png",0,100,false,false));
    secondRow.push_back(new GameTile("src/menu/Sol.png",100,100,true,false));
    secondRow.push_back(new GameTile("src/menu/Sol.png",200,100,true,false));
    secondRow.push_back(new GameTile("src/menu/Sol.png",300,100,true,false));
    secondRow.push_back(new GameTile("src/menu/Sol.png",400,100,true,false));
    secondRow.push_back(new GameTile("src/menu/Sol.png",500,100,true,false));
    secondRow.push_back(new GameTile("src/menu/Sol.png",600,100,true,false));
    secondRow.push_back(new GameTile("src/menu/Sol.png",700,100,true,false));
    secondRow.push_back(new GameTile("src/menu/Sol.png",800,100,true,false));
    secondRow.push_back(new GameTile("src/menu/Sol.png",850,100,true,true));
    tiles.push_back(secondRow);

    vector<GameTile *> thirdRow;
    thirdRow.push_back(new GameTile("src/menu/Sol.png",0,200,true,false));
    thirdRow.push_back(new GameTile("src/menu/Sol.png",100,200,true,true));
    thirdRow.push_back(new GameTile("src/menu/Sol.png",200,200,true,false));
    thirdRow.push_back(new GameTile("src/menu/Sol.png",300,200,false,false));
    thirdRow.push_back(new GameTile("src/menu/Sol.png",400,200,true,false));
    thirdRow.push_back(new GameTile("src/menu/Sol.png",500,200,true,false));
    thirdRow.push_back(new GameTile("src/menu/Sol.png",600,200,false,false));
    thirdRow.push_back(new GameTile("src/menu/Sol.png",700,200,false,false));
    thirdRow.push_back(new GameTile("src/menu/Sol.png",800,200,true,false));
    thirdRow.push_back(new GameTile("src/menu/Sol.png",850,200,true,false));
    tiles.push_back(thirdRow);

    vector<GameTile *> fourRow;
    fourRow.push_back(new GameTile("src/menu/Sol.png",0,300,false,false));
    fourRow.push_back(new GameTile("src/menu/Sol.png",100,300,true,true));
    fourRow.push_back(new GameTile("src/menu/Sol.png",200,300,true,false));
    fourRow.push_back(new GameTile("src/menu/Sol.png",300,300,false,false));
    fourRow.push_back(new GameTile("src/menu/Sol.png",400,300,true,false));
    fourRow.push_back(new GameTile("src/menu/Sol.png",500,300,true,false));
    fourRow.push_back(new GameTile("src/menu/Sol.png",600,300,true,false));
    fourRow.push_back(new GameTile("src/menu/Sol.png",700,300,false,false));
    fourRow.push_back(new GameTile("src/menu/Sol.png",800,300,false,false));
    fourRow.push_back(new GameTile("src/menu/Sol.png",850,300,false,true));
    tiles.push_back(fourRow);

    vector<GameTile *> fiveRow;
    fiveRow.push_back(new GameTile("src/menu/Sol.png",0,400,false,false));
    fiveRow.push_back(new GameTile("src/menu/Sol.png",100,400,true,true));
    fiveRow.push_back(new GameTile("src/menu/Sol.png",200,400,true,false));
    fiveRow.push_back(new GameTile("src/menu/Sol.png",300,400,false,false));
    fiveRow.push_back(new GameTile("src/menu/Sol.png",400,400,false,false));
    fiveRow.push_back(new GameTile("src/menu/Sol.png",500,400,true,false));
    fiveRow.push_back(new GameTile("src/menu/Sol.png",600,400,true,false));
    fiveRow.push_back(new GameTile("src/menu/Sol.png",700,400,true,false));
    fiveRow.push_back(new GameTile("src/menu/Sol.png",800,400,true,false));
    fiveRow.push_back(new GameTile("src/menu/Sol.png",850,400,false,true));
    tiles.push_back(fiveRow);

    vector<GameTile *> sixRow;
    sixRow.push_back(new GameTile("src/menu/Sol.png",0,500,true,false));
    sixRow.push_back(new GameTile("src/menu/Sol.png",100,500,true,true));
    sixRow.push_back(new GameTile("src/menu/Sol.png",200,500,true,false));
    sixRow.push_back(new GameTile("src/menu/Sol.png",300,500,true,false));
    sixRow.push_back(new GameTile("src/menu/Sol.png",400,500,false,false));
    sixRow.push_back(new GameTile("src/menu/Sol.png",500,500,true,false));
    sixRow.push_back(new GameTile("src/menu/Sol.png",600,500,true,false));
    sixRow.push_back(new GameTile("src/menu/Sol.png",700,500,false,false));
    sixRow.push_back(new GameTile("src/menu/Sol.png",800,500,false,false));
    sixRow.push_back(new GameTile("src/menu/Sol.png",850,500,false,true));
    tiles.push_back(sixRow);

    vector<GameTile *> sevethRow;
    sevethRow.push_back(new GameTile("src/menu/Sol.png",0,600,true,false));
    sevethRow.push_back(new GameTile("src/menu/Sol.png",100,600,true,true));
    sevethRow.push_back(new GameTile("src/menu/Sol.png",200,600,true,false));
    sevethRow.push_back(new GameTile("src/menu/Sol.png",300,600,true,false));
    sevethRow.push_back(new GameTile("src/menu/Sol.png",400,600,false,false));
    sevethRow.push_back(new GameTile("src/menu/Sol.png",500,600,true,false));
    sevethRow.push_back(new GameTile("src/menu/Sol.png",600,600,true,false));
    sevethRow.push_back(new GameTile("src/menu/Sol.png",700,600,false,false));
    sevethRow.push_back(new GameTile("src/menu/Sol.png",800,600,false,false));
    sevethRow.push_back(new GameTile("src/menu/Sol.png",850,600,false,true));
    tiles.push_back(sevethRow);

    vector<GameTile *> eigthRow;
    eigthRow.push_back(new GameTile("src/menu/Sol.png",0,700,false,false));
    eigthRow.push_back(new GameTile("src/menu/Sol.png",100,700,false,false));
    eigthRow.push_back(new GameTile("src/menu/Sol.png",200,700,true,false));
    eigthRow.push_back(new GameTile("src/menu/Sol.png",300,700,false,false));
    eigthRow.push_back(new GameTile("src/menu/Sol.png",400,700,false,false));
    eigthRow.push_back(new GameTile("src/menu/Sol.png",500,700,true,false));
    eigthRow.push_back(new GameTile("src/menu/Sol.png",600,700,true,false));
    eigthRow.push_back(new GameTile("src/menu/Sol.png",700,700,true,false));
    eigthRow.push_back(new GameTile("src/menu/Sol.png",800,700,true,false));
    eigthRow.push_back(new GameTile("src/menu/Sol.png",850,700,false,true));
    tiles.push_back(eigthRow);

    vector<GameTile *> nineRow;
    nineRow.push_back(new GameTile("src/menu/Sol.png",0,800,false,true));
    nineRow.push_back(new GameTile("src/menu/Sol.png",100,800,true,true));
    nineRow.push_back(new GameTile("src/menu/Sol.png",200,800,true,false));
    nineRow.push_back(new GameTile("src/menu/Sol.png",300,800,true,false));
    nineRow.push_back(new GameTile("src/menu/Sol.png",400,800,false,false));
    nineRow.push_back(new GameTile("src/menu/Sol.png",500,800,true,false));
    nineRow.push_back(new GameTile("src/menu/Sol.png",600,800,true,false));
    nineRow.push_back(new GameTile("src/menu/Sol.png",700,800,false,false));
    nineRow.push_back(new GameTile("src/menu/Sol.png",800,800,false,false));
    nineRow.push_back(new GameTile("src/menu/Sol.png",850,800,false,true));
    tiles.push_back(nineRow);

    vector<GameTile *> tenRow;
    tenRow.push_back(new GameTile("src/menu/Sol.png",0,850,false,true));
    tenRow.push_back(new GameTile("src/menu/Sol.png",100,850,true,true));
    tenRow.push_back(new GameTile("src/menu/Sol.png",200,850,true,false));
    tenRow.push_back(new GameTile("src/menu/Sol.png",300,850,true,false));
    tenRow.push_back(new GameTile("src/menu/Sol.png",400,850,false,false));
    tenRow.push_back(new GameTile("src/menu/Sol.png",500,850,true,false));
    tenRow.push_back(new GameTile("src/menu/Sol.png",600,850,true,false));
    tenRow.push_back(new GameTile("src/menu/Sol.png",700,850,false,false));
    tenRow.push_back(new GameTile("src/menu/Sol.png",800,850,false,false));
    tenRow.push_back(new GameTile("src/menu/Sol.png",850,850,false,true));
    tiles.push_back(tenRow);
}