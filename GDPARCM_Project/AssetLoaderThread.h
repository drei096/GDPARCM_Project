#pragma once

#include "ThreadObject.h"

class IExecutionEvent;

class AssetLoaderThread : public ThreadObject
{
public:
	AssetLoaderThread(std::string name_assetToLoad, std::string id_assetToLoad, IExecutionEvent* execution_event);
	~AssetLoaderThread();

	void Run() override;

private:
	std::string assetName;
	std::string assetID;

private:
	IExecutionEvent* executionEvent;
};

