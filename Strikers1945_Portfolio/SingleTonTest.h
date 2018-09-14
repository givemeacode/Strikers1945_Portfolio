#pragma once

#include "Scene.h"

class SingleTonTest
	: public Scene
{
public:
	SingleTonTest();
	~SingleTonTest();
public:
	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

