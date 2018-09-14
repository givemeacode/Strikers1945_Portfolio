#include "stdafx.h"
#include "SceneManager.h"

#include "Scene.h"
#include "GameScene.h"
#include "SingleTonTest.h"

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::ChangeScene(eSceneType type)
{
	switch (type)
	{
	case eSceneType::SCENE_TEST1:
		scene = new GameScene();
		scene->Init();

		break;
	case eSceneType::SCENE_TEST2:
		scene = new SingleTonTest();
		scene->Init();
		break;
	}
}


void SceneManager::Update()
{
	scene->Update();
}

void SceneManager::Render(HDC hdc)
{
	scene->Render(hdc);
}
