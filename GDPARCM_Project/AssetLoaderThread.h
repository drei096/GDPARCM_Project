#pragma once

#include "ThreadObject.h"

class IExecutionEvent;

class AssetLoaderThread : public ThreadObject
{
public:
	AssetLoaderThread(std::string path, IExecutionEvent* execution_event);
	~AssetLoaderThread();

	void Run() override;

private:
	std::string asset_path;

private:
	IExecutionEvent* executionEvent;
};

