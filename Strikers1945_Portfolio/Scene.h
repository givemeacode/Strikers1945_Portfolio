#pragma once

#include "SceneManager.h"
#include "GameNode.h"

class Scene
	: public GameNode
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