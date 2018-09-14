#pragma once

#include "SceneManager.h"
#include "MainGame.h"

class Scene
	: public MainGame
{
protected:
	eSceneType sceneType;
public:
	Scene();
	~Scene();
public:
	virtual bool Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
public:
	void SetSceneType(eSceneType _type);
	eSceneType GetSceneType();

};
