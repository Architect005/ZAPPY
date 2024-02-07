#include "gameMenu.h"

GameMenu::GameMenu(float width, float height)
{
    if (!font.loadFromFile("src/menu/AceRecords.ttf")) {
        cout << "No font is here";
    }

    if (!font1.loadFromFile("src/menu/Monster of South St.ttf")) {
        cout << "No font is here";
    }

    if (!music.openFromFile("src/menu/GameSound_out.wav")) {
        cout << "No music is here";
    }

    music.setLoop(true);
    music.play();

    gameMenu[0].setFont(font);
    gameMenu[0].setFillColor(Color::Black);
    gameMenu[0].setString("Map 1");
    gameMenu[0].setCharacterSize(70);
    gameMenu[0].setPosition(400, 200);
    
    gameMenu[1].setFont(font);
    gameMenu[1].setFillColor(Color::Black);
    gameMenu[1].setString("Map 2");
    gameMenu[1].setCharacterSize(70);
    gameMenu[1].setPosition(400, 300);

    gameMenu[2].setFont(font);
    gameMenu[2].setFillColor(Color::Black);
    gameMenu[2].setString("Map 3");
    gameMenu[2].setCharacterSize(70);
    gameMenu[2].setPosition(400, 400);

    gameMenu[3].setFont(font);
    gameMenu[3].setFillColor(Color::Black);
    gameMenu[3].setString("Exit");
    gameMenu[3].setCharacterSize(70);
    gameMenu[3].setPosition(400, 500);

    GameMenuSelected = -1;

}
GameMenu::~GameMenu()
{

}

void GameMenu::draw(RenderWindow& window) {
    for (int i = 0; i < Max_game_menu; ++i) {
         window.draw(gameMenu[i]);
    }
}

void GameMenu::MoveUp()
{
    if (GameMenuSelected - 1 >= 0) {
        gameMenu[GameMenuSelected].setFillColor(Color::White);

        GameMenuSelected--;
        
        if (GameMenuSelected == -1) {
            GameMenuSelected == 2;
        }
        gameMenu[GameMenuSelected].setFillColor(Color::Blue);
    }
}

void GameMenu::MoveDown()
{
    if (GameMenuSelected + 1 <= Max_game_menu) {
        gameMenu[GameMenuSelected].setFillColor(Color::White);

        GameMenuSelected++;
        
        if (GameMenuSelected == 4) {
            GameMenuSelected == 0;
        }
        gameMenu[GameMenuSelected].setFillColor(Color::Blue);
    }
}