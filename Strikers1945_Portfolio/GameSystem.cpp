#include "stdafx.h"
#include "GameSystem.h"



GameSystem::GameSystem()
{
	GetClientRect(_hWnd, &rcClient);
}


GameSystem::~GameSystem()
{
}


RECT GameSystem::GetGameClientRect()
{
	return rcClient;
}