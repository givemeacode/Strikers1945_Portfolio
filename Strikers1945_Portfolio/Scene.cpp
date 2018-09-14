#include "stdafx.h"
#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

bool Scene::Init()
{
	return true;
}

void Scene::Update()
{
}

void Scene::Render(HDC hdc)
{
}

void Scene::Release()
{
}


void Scene::SetSceneType(eSceneType _type)
{
	sceneType = _type;
}

eSceneType Scene::GetSceneType()
{
	return sceneType;
}