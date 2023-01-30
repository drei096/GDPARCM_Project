#include "Application.h"

#include "GameObjectManager.h"
#include "SceneManager.h"
#include "NonThreadedScene.h"
#include "TextureManager.h"

Application::Application() :
mWindow(sf::VideoMode(Application::WINDOW_WIDTH, Application::WINDOW_HEIGHT), "SFML Application")
{
    font = new sf::Font();
    font->loadFromFile("Media/Sansation.ttf");

    fpsText = new sf::Text();
    fpsText->setFont(*font);
    fpsText->setCharacterSize(48);

    fpsCount = new sf::Text();
    fpsCount->setFont(*font);
    fpsCount->setCharacterSize(48);

    SceneManager::getInstance()->registerScene(new NonThreadedScene());

    SceneManager::getInstance()->loadScene(SceneManager::NON_THREADED_SCENE_NAME);

    
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) 
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) 
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
        SceneManager::getInstance()->checkLoadScene();
    }
}

void Application::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event)) 
    {
        switch (event.type)
    	{
        case sf::Event::Closed:
            mWindow.close();
            break;
        default:
            break;
        }
    }
}

void Application::update(sf::Time deltaTime)
{
    GameObjectManager::getInstance()->update(deltaTime);
    SceneManager::getInstance()->checkLoadScene();

    fpsCount->setString(to_string(floor(1.0f / deltaTime.asSeconds())));
}

void Application::render()
{
    mWindow.clear();

    GameObjectManager::getInstance()->draw(&mWindow);
    fpsText->setString("FPS:");
    fpsText->setPosition(WINDOW_WIDTH - 300, WINDOW_HEIGHT - 100);
    mWindow.draw(*fpsText);

    fpsCount->setPosition(WINDOW_WIDTH - 200, WINDOW_HEIGHT - 100);
    mWindow.draw(*fpsCount);

    mWindow.display();
}
