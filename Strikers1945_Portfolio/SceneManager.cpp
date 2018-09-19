#include "stdafx.h"
#include "SceneManager.h"

#include "Scene.h"
#include "GameScene.h"

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