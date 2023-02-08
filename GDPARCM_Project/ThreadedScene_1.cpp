#include "ThreadedScene_1.h"
#include "GameObjectManager.h"
#include "TextureManager.h"
#include "SceneBG.h"
#include "TileIconObject.h"
#include "IconLoader.h"

ThreadedScene_1::ThreadedScene_1() : AScene("ThreadedScene_1")
{
}

ThreadedScene_1::~ThreadedScene_1()
{
}

void ThreadedScene_1::onLoadResources()
{
    TextureManager::getInstance()->loadAll();
}

void ThreadedScene_1::onLoadObjects()
{

    SceneBG* bgObject = new SceneBG("BGObject");
    this->registerObject(bgObject);

    IconLoader* loader = new IconLoader();
    this->registerObject(loader);


}

void ThreadedScene_1::onUnloadResources()
{
    GameObjectManager::getInstance()->deleteAllObjectsInScene();
}