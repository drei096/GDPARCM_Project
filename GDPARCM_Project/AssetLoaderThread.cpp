#include "AssetLoaderThread.h"

#include "GameObjectManager.h"
#include "IExecutionEvent.h"
#include "TextureManager.h"
#include "TileIconObject.h"



AssetLoaderThread::AssetLoaderThread(std::string name_assetToLoad, std::string id_assetToLoad, IExecutionEvent* execution_event)
{
	assetName = name_assetToLoad;
	assetID = id_assetToLoad;
	executionEvent = execution_event;
}

AssetLoaderThread::~AssetLoaderThread()
{
}

void AssetLoaderThread::Run()
{
	ThreadObject::Sleep(200);

	// LOAD TILE ICON
	std::cout << "TILE NAME DEBUG: " << assetName << std::endl;

	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Media/Streaming/" + assetName + ".png");
	TextureManager::getInstance()->gettextureMap()[assetName] = texture;

	this->executionEvent->OnFinishedExecution();

	delete this;
}
