#pragma once

#include "SingleTon.h"

enum eReSourceType
{
	R_BOMB,
	R_BULLET,
	R_EFFECT,
	R_ITEM,
	R_MONSTER,
	R_PLAYER,
	R_SCORE,
	R_STAGE,
};
class ResourceManager
	: public SingletonBase<ResourceManager>
{
private:
	std::string fileKey;
	int width;
	int height;
	int frameX;
	int frameY;
	bool trans;
	COLORREF transColor;
	int _r, _g, _b;

public:
	ResourceManager();
	~ResourceManager();
public:
	void AddResource(eReSourceType type, const TCHAR* fileName);
	void ParsingData(eReSourceType type, const TCHAR* fileName);
};

