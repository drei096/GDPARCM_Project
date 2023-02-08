#include "TileIconObject.h"
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Application.h"
#include "Renderer.h"
#include "ThreadObject.h"

TileIconObject::TileIconObject(std::string name, std::string tileID) : AGameObject(name)
{
	tileName = tileID;
}

void TileIconObject::initialize()
{
	ThreadObject::Sleep(1000);

	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	sf::Sprite* sprite = new sf::Sprite();
	if(TextureManager::getInstance()->getTexture(tileName) != nullptr)
		sprite->setTexture(*TextureManager::getInstance()->getTexture(tileName));

	

	Renderer* renderer = new Renderer(tileName + "_renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}