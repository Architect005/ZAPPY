#include <SFML/Graphics.hpp>
#include "gameMenu.h"
#include "gameWorld.h"
#include "gameWorld2.h"
#include "gameWorld3.h"

using namespace sf;

int main() {
    RenderWindow MENU(VideoMode(950,700), "ZAPPY", Style::Default);
    GameMenu gameMenu(MENU.getSize().x, MENU.getSize().y);
    RectangleShape background;
    background.setSize(Vector2f(950, 700));
    Texture MainTexture;
    MainTexture.loadFromFile("src/menu/ZAPPY GAME.jpg");
    background.setTexture(&MainTexture);

    GameWorld gameWorld = GameWorld();
    GameWorld2 gameWorld2 = GameWorld2();
    GameWorld3 gameWorld3 = GameWorld3();

    while(MENU.isOpen()) {
        Event event;
        while(MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close();
            }

            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) {
                    gameMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down) {
                    gameMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return) {
                    RenderWindow Play(VideoMode(950, 700), "Map1");
                    RenderWindow Option(VideoMode(950, 700), "Map2");
                    RenderWindow About(VideoMode(950, 700), "Map3");

                    int x = gameMenu.GameMenuPressed();
                    if (x == 0) {
                        while(Play.isOpen())
                        {
                            Event aevent;
                            while (Play.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed) {
                                    Play.close();
                                }
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        Play.close();
                                    }
                                }
                            }
                            Option.close();
                            About.close();
                            Play.clear();
                            for (int i = 0; i < gameWorld.gridLength; i++) {
                                for (int j = 0; j < gameWorld.gridLength; j++) {
                                    Play.draw(gameWorld.tiles[i][j]->sprite);
                                    }
                                }
                            Play.display();
                            MENU.close();
                        }
                    }
                    if (x == 1) {
                        while (Option.isOpen()) 
                        {
                            Event aevent;
                            while (Option.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed) {
                                    Option.close();
                                }
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        Option.close();
                                    }
                                }
                            }
                            Play.close();
                            About.close();
                            Option.clear();
                            for (int k = 0; k < gameWorld2.gridLength2; k++) {
                                for (int l = 0; l < gameWorld2.gridLength2; l++) {
                                    Option.draw(gameWorld2.tiles2[k][l]->sprite2);
                                    }
                                }
                            Option.display();
                            MENU.close();
                        }
                    }
                    if (x == 2) {
                        while (About.isOpen()) 
                        {
                            Event aevent;
                            while (About.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed) {
                                    About.close();
                                }
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        About.close();
                                    }
                                }
                            }
                            Play.close();
                            Option.close();
                            About.clear();
                            for (int m = 0; m < gameWorld3.gridLength3; m++) {
                                for (int n = 0; n < gameWorld3.gridLength3; n++) {
                                    About.draw(gameWorld3.tiles[m][n]->sprite3);
                                    }
                                }
                            About.display();
                            MENU.close();
                        }
                    }
                    if (x == 3)
                        MENU.close();
                    break;
                }
            }
        MENU.clear();
        MENU.draw(background);
        gameMenu.draw(MENU);
        MENU.display();
        }
    }
}