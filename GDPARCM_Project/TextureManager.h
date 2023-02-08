#pragma once
#include <SFML/Graphics.hpp>;
#include <unordered_map>

class IExecutionEvent;

class TextureManager
{
public:
    static TextureManager* getInstance();
    void testFunction();

    void loadAll();
    sf::Texture* getTexture(std::string);
private:
    // set constructor to private
    TextureManager() {};
    // set copy contructor to private
    TextureManager(TextureManager const&) {};
    // assignment operator is private
    TextureManager& operator=(TextureManager const&) {};
    static TextureManager* sharedInstance;

    std::unordered_map<std::string, sf::Texture*> textureMap;

public:
    void loadTexture(std::string, std::string);
    std::unordered_map<std::string, sf::Texture*> gettextureMap();

public:
    int maxColumns = 28;
    int maxRows = 22;
    int columnGrid = 0;
    int rowGrid = 0;
};

