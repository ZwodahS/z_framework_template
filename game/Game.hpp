#ifndef _GAME_GAME_H_
#define _GAME_GAME_H_

#include "Assets.hpp"
#include "../z_framework/zf_sfml/Mouse.hpp"
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
class Screen;
class Game
{
    public:
        /**
         * Store the constant to the screen size.
         * TODO :Need to think of a way to do resizing.
         */
        static const sf::Vector2i ScreenSize;
        const std::string title;

        Game();
        ~Game();

        // the main run method.
        void run(); 

        // the rendering window
        sf::RenderWindow window; 
        /* 
         * the mouse object. See zf::Mouse
         */
        zf::Mouse mouse;

        // boolean representing if this game is currently focused.
        bool isFocused;
        
        // Stores all the assets files.
        Assets assets;
        // the method to load the assets.
        void loadAssets();

    private:
        // The standard update function
        void update(sf::Time delta);
        // the standard draw function
        void draw(sf::Time delta);
        
        /* 
         * Store the current screen that is being draw and updated
         */
        Screen* _currentScreen;        
        /* 
         * Stores the next screen to be drawn and updated.
         * When the current screen completes its exit, this will be the next screen.
         */
        Screen* _nextScreen;

        /**
         * Internal boolean for quitting. 
         */
        bool _quit;
};


#endif

