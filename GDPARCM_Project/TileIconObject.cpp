#include "TileIconObject.h"
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Application.h"
#include "Renderer.h"

TileIconObject::TileIconObject(std::string name, std::string tileID) : AGameObject(name)
{
	tileName = tileID;
}

void TileIconObject::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture(tileName));
	

	Renderer* renderer = new Renderer(tileName + "_renderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}