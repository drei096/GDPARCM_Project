#include "TextureManager.h"
#include <cstddef>
#include <iostream>
#include <iomanip>

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance()
{
	//initialize only when we need it
	if (sharedInstance == NULL) 
	{
		sharedInstance = new TextureManager();
	}
	return sharedInstance;
}

void TextureManager::loadAll()
{
	//BG TEXTURE
	loadTexture("desert_bg", "Media/Textures/Desert.png");
	sf::Texture* bgTex;
	bgTex = getTexture("desert_bg");
	bgTex->setRepeated(true);

	//ADD ALL TEXTURES TO LOAD BELOW
	for(int tileIdx = 0; tileIdx < 480; tileIdx++)
	{
		if(tileIdx < 10)
		{
			std::string idx = "tile00";
			loadTexture(idx + std::to_string(tileIdx), "Media/Streaming/" + idx + std::to_string(tileIdx) + ".png");
		}
			
		else if (tileIdx < 100)
		{
			std::string idx = "tile0";
			loadTexture(idx + std::to_string(tileIdx), "Media/Streaming/" + idx + std::to_string(tileIdx) + ".png");
		}
			
		else
		{
			std::string idx = "tile";
			loadTexture(idx + std::to_string(tileIdx), "Media/Streaming/" + idx + std::to_string(tileIdx) + ".png");
		}
			
	}
	
}

void TextureManager::loadTexture(std::string key, std::string path)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}


sf::Texture* TextureManager::getTexture(std::string key)
{
	if (textureMap[key] != NULL) 
	{
		return textureMap[key];
	}
	else 
	{
		std::cout << "No texture found for " << key;
		return NULL;
	}
}

void TextureManager::testFunction()
{
	std::cout << "Hi, I'm single-ton ;D";
}