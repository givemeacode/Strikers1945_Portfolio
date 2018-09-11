#pragma once
#include "GameNode.h"


class MainGame : public GameNode
{
public:
	MainGame();
	virtual ~MainGame();
public:
	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};
