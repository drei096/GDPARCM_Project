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
	//ThreadObject::Sleep(200);

	// LOAD TILE ICON
	TextureManager::getInstance()->loadTexture(assetName, "Media/Streaming/" + assetName + ".png");

	this->executionEvent->OnFinishedExecution();

	delete this;
}
