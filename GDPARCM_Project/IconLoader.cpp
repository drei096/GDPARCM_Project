#include "IconLoader.h"

#include "GameObjectManager.h"
#include "TileIconObject.h"


IconLoader::IconLoader() : AGameObject("IconDisplayer")
{
}

void IconLoader::initialize()
{
	
}

void IconLoader::update(sf::Time deltaTime)
{
	//AGameObject::update(deltaTime);

	loadTicks += deltaTime.asMilliseconds();

	createIconObjects(deltaTime, loadTicks);
	
}

void IconLoader::displayIcon()
{

	
	

		
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
