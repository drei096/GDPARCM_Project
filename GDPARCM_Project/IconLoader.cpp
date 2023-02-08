#include "IconLoader.h"

#include "GameObjectManager.h"
#include "TileIconObject.h"
#include "AssetLoaderThread.h"

IconLoader::IconLoader() : AGameObject("IconDisplayer")
{
}

void IconLoader::initialize()
{
	
}

void IconLoader::update(sf::Time deltaTime)
{
	this->loadTicks += deltaTime.asMilliseconds();

	if(this->loadTicks > 1000.0f)
	{
		this->loadTicks = 0.0f;

		if(tileIdx < 10)
		{
			AssetLoaderThread* assetLoaderThread = new AssetLoaderThread(idx1 + std::to_string(tileIdx), idx1 + std::to_string(tileIdx), this);
			assetLoaderThread->ScheduleThreadForExecution();
		}
		else if(tileIdx < 100)
		{
			AssetLoaderThread* assetLoaderThread = new AssetLoaderThread(idx2 + std::to_string(tileIdx), idx2 + std::to_string(tileIdx), this);
			assetLoaderThread->ScheduleThreadForExecution();
		}
		else
		{
			AssetLoaderThread* assetLoaderThread = new AssetLoaderThread(idx3 + std::to_string(tileIdx), idx3 + std::to_string(tileIdx), this);
			assetLoaderThread->ScheduleThreadForExecution();
		}
		tileIdx++;
	}
	
}

void IconLoader::OnFinishedExecution()
{
	this->displayIcon();
}

void IconLoader::displayIcon()
{
	TileIconObject* temp = nullptr;

	if (tileIdx < 10)
		temp = new TileIconObject(idx1 + std::to_string(tileIdx), idx1 + std::to_string(tileIdx));
	else if(tileIdx < 100)
		temp = new TileIconObject(idx2 + std::to_string(tileIdx), idx2 + std::to_string(tileIdx));
	else
		temp = new TileIconObject(idx3 + std::to_string(tileIdx), idx3 + std::to_string(tileIdx));

	int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
	float x = this->columnGrid * IMG_WIDTH;
	float y = this->rowGrid * IMG_HEIGHT;
	temp->setPosition(x, y);


	this->columnGrid++;
	if (this->columnGrid == this->maxColumns)
	{
		this->columnGrid = 0;
		this->rowGrid++;
	}

	GameObjectManager::getInstance()->addObject(temp);
	tileIconList.push_back(temp);
	
	

		
}

void IconLoader::createIconObjects(sf::Time deltaTime, float loadTicks)
{
	if(loadTicks > 200.0f)
	{
		if (tileIdx < 480)
		{

			if (tileIdx < 10)
			{
				std::string idx = "tile00";
				TileIconObject* temp = new TileIconObject(idx + std::to_string(tileIdx), idx + std::to_string(tileIdx));

				int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
				float x = this->columnGrid * IMG_WIDTH;
				float y = this->rowGrid * IMG_HEIGHT;
				temp->setPosition(x, y);


				this->columnGrid++;
				if (this->columnGrid == this->maxColumns)
				{
					this->columnGrid = 0;
					this->rowGrid++;
				}

				GameObjectManager::getInstance()->addObject(temp);
				tileIconList.push_back(temp);


			}

			else if (tileIdx < 100)
			{
				std::string idx = "tile0";
				TileIconObject* temp = new TileIconObject(idx + std::to_string(tileIdx), idx + std::to_string(tileIdx));

				int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
				float x = this->columnGrid * IMG_WIDTH;
				float y = this->rowGrid * IMG_HEIGHT;
				temp->setPosition(x, y);


				this->columnGrid++;
				if (this->columnGrid == this->maxColumns)
				{
					this->columnGrid = 0;
					this->rowGrid++;
				}

				GameObjectManager::getInstance()->addObject(temp);
				tileIconList.push_back(temp);


			}

			else
			{
				std::string idx = "tile";
				TileIconObject* temp = new TileIconObject(idx + std::to_string(tileIdx), idx + std::to_string(tileIdx));


				int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
				float x = this->columnGrid * IMG_WIDTH;
				float y = this->rowGrid * IMG_HEIGHT;
				temp->setPosition(x, y);


				this->columnGrid++;
				if (this->columnGrid == this->maxColumns)
				{
					this->columnGrid = 0;
					this->rowGrid++;
				}

				GameObjectManager::getInstance()->addObject(temp);
				tileIconList.push_back(temp);


			}

			this->loadTicks = 0.0f;
			tileIdx++;
		}
	}

	
}
