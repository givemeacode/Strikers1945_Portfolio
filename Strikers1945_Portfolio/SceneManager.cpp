#include "stdafx.h"
#include "SceneManager.h"

#include "Scene.h"
#include "CharacterSelectScene.h"
#include "GameScene.h"
#include "GameClear.h"
#include "GameOver.h"
#include "TitleScene.h"
SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::ChangeScene(eSceneType type)
{
	if (scene != NULL)
	{
		Release();
	}

	switch (type)
	{
	case eSceneType::SCENE_TITLE:
		scene = new TitleScene();
		scene->Init();
		break;
	case eSceneType::SCENE_CHARACTER:
		scene = new CharacterSelectScene();
		scene->Init();
		break;
	case eSceneType::SCENE_GAME1:
		scene = new GameScene();
		scene->Init();
		break;
	case eSceneType::SCENE_CLEAR:
		scene = new GameClear();
		scene->Init();
		break;
	case eSceneType::SCENE_END:
		scene = new GameOver();
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

void SceneManager::Release()
{
	delete scene;
}
