/**
 * This class defines the first screen that the player will see when they starts the game.
 */
#ifndef _GAME_SCREENS_MAINSCREEN_H_
#define _GAME_SCREENS_MAINSCREEN_H_
#include "Screen.hpp"
#include <SFML/Graphics.hpp>
class Game;
class MainScreen : public Screen
{
public:
    MainScreen(Game& game);
    virtual ~MainScreen();

    virtual void draw(sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void inputs(sf::RenderWindow& window, const sf::Time& delta);
    virtual void textInput(char c);

    /*
     * Screen Enter and exits are omitted.
     * If there is a need to override them, just do so.
     * When so, the method must call the screen method to change the state to the proper state.
     */
    // virtual void screenEnter();
    // virtual void screenExit();
};
#endif
