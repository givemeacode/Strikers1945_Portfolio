#pragma once
#include "Scene.h"

class TitleScene
	: public Scene
{
	Image* TitleLogo;
public:
	TitleScene();
	~TitleScene();
public:
	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};
