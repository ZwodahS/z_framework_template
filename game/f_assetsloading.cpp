#include "Game.hpp"
#ifdef APPBUNDLE
#include "../ResourcePath.hpp"
#endif
void Game::loadAssets()
{
    std::string path = "";
    #ifdef APPBUNDLE
    path = resourcePath();
    #endif
    
    assets.master1.create(1280, 1280);
    assets.masterS1.create(&assets.master1, sf::IntRect(0, 0, 300, 300));
}
