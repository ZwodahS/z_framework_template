#include "Game.hpp"
#include "screens/Screen.hpp"
#include "screens/MainScreen.hpp"
#include <SFML/Graphics.hpp>
#define CLEAR_COLOR sf::Color(20,20,20,255)
#define GAME_TITLE "Game Name"

// move this elsewhere if the order of definition matters.
const sf::Vector2i Game::ScreenSize = sf::Vector2i(960, 640);
Game::Game()
    : title(GAME_TITLE)
    , window(sf::VideoMode(ScreenSize.x,ScreenSize.y),title),mouse(), isFocused(true), _currentScreen(0), _nextScreen(0), _quit(false)
{
    // limit the framerate to 60. Could go lower, but 120 seems fine.
    window.setFramerateLimit(60);
}

Game::~Game()
{

}

void Game::run()
{
    // Load the assets. method is defined inside f_assetsloading.cpp
    loadAssets();
    
    // set up the clock for delta
    sf::Clock clock;

    // define the mainscreen
    _currentScreen = new MainScreen(*this);

    // check for quit condition
    while((!_quit || _currentScreen != 0) && window.isOpen())
    {
        // update clock 
        sf::Time delta = clock.restart();

        // update mouse.
        mouse.update(delta);

        // check for events, especially mousewheel
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                _quit = true;
            }
            else if(event.type == sf::Event::MouseWheelMoved)
            {
                mouse.wheelDelta = event.mouseWheel.delta;
            }
            else if(event.type == sf::Event::LostFocus)
            {
                isFocused = false;
            }
            else if(event.type == sf::Event::GainedFocus)
            {
                isFocused = true;
            }
        }

        // if not quit , update then draw.
        if(!_quit)
        {
            update(delta);
            draw(delta);
        }
    }
}

void Game::update(sf::Time delta)
{
    // if there is a current screen then we process.
    if(_currentScreen != 0)
    {
        // if it is not focus, we do not process any inputs.
        if(isFocused || true)
        {
            _currentScreen->inputs(window, delta);
        }
        // update regardless of it is focus. 
        // The other screen will decides if there is a need to pause
        _currentScreen->update(window, delta);    

        // if the current screen is exited, then we switch to the next screen.
        if(_currentScreen->screenState == Screen::Exited)
        {
            // delete the current screen
            delete _currentScreen;
            // set the current screen = 0;
            _currentScreen = 0;
            // if there is next screen, then we assign it to the current screen and
            // tell it to enter.
            if(_nextScreen != 0)
            {
                _currentScreen = _nextScreen;
                _nextScreen = 0;
                _currentScreen->screenEnter();
            }
        }
    }
}

void Game::draw(sf::Time delta)
{
    // clear the screen
    window.clear(CLEAR_COLOR);
    if(_currentScreen != 0)
    {
        // draw the current screen
        _currentScreen->draw(window);   
    }
    // display what is drawn
    window.display();
}
