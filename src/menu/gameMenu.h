#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define Max_game_menu 4
class GameMenu 
{
    public:
        GameMenu(float width, float height);

        void draw(RenderWindow& window);
        void MoveUp();
        void MoveDown();

        int GameMenuPressed() {
            return GameMenuSelected;
        }
        ~GameMenu();

    private:
        int GameMenuSelected;
        Font font;
        Font font1;
        Music music;
        Text text;
        Text gameMenu[Max_game_menu];
};