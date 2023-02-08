#pragma once

#include "ThreadObject.h"

class AssetLoaderThread : public ThreadObject
{
public:
	AssetLoaderThread();
	~AssetLoaderThread();

	void Run() override;
};

