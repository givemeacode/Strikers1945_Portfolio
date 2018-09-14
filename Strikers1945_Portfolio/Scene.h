#pragma once

class Scene
{
public:
	Scene();
	~Scene();
public:
	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};

