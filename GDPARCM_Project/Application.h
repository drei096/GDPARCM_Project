#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <vector>

class Application
{
public:
    static const int WINDOW_WIDTH = 1920;
    static const int WINDOW_HEIGHT = 1080;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

    Application();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

private:
    sf::RenderWindow mWindow;
    std::vector<Entity*> entityList;
    sf::Font* font;
    sf::Text* fpsText;
    sf::Text* fpsCount;

};

