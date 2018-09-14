#pragma once

#include "SingleTon.h"

class Scene;


enum eSceneType
{
	SCENE_TEST1,
	SCENE_TEST2,
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

};

