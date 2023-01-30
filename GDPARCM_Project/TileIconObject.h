#pragma once
#include "AGameObject.h"


class TileIconObject : public AGameObject
{
public:
	TileIconObject(std::string name, std::string tileID);
	void initialize();

private:
	std::string tileName;
};

