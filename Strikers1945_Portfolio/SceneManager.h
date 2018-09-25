#pragma once

#include "SingleTon.h"

class Scene;

enum eSceneType
{
	SCENE_TITLE,
	SCENE_CHARACTER,
	SCENE_GAME1,
	SCENE_CLEAR,
	SCENE_END,
};


class SceneManager
	:public SingletonBase<SceneManager>
{
private:
	Scene * scene;
public:
	SceneManager();
	~SceneManager();
public:
	void ChangeScene(eSceneType type);
	void Update();
	void Render(HDC hdc);
	void Release();
};
