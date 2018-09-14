#include "stdafx.h"
#include "KeyManager.h"



KeyManager::KeyManager()
{
}


KeyManager::~KeyManager()
{
}

bool KeyManager::Init()
{
	this->GetKeyUp().reset();
	this->GetKeyDown().reset();

	return true;
}

void KeyManager::Release()
{
}

bool KeyManager::IsOnceKeyDown(int _key)	// 현재 키가 눌렷는지만 알고싶을떄. (이전상태는 관심사가 아님)
{
	if (GetAsyncKeyState(_key) & 0x8000)
	{
		if (!this->GetKeyDown()[_key])
		{
			this->setKeyDown(_key, true);
			return true;
		}
	}
	else
		this->setKeyDown(_key, false);

	return false;
}

bool KeyManager::IsOnceKeyUp(int _key)
{
	if (GetAsyncKeyState(_key) & 0x8000)
		this->setKeyUp(_key, true);
	else
	{
		if (this->GetKeyUp()[_key])
		{
			this->setKeyUp(_key, false);
			return true;
		}
	}

	return false;
}

bool KeyManager::IsStayKeyDown(int _key) // 현재 계속 눌러져있는경우 true, 아니면 false
{
	if (GetAsyncKeyState(_key) & 0x8000)
		return true;

	return false;
}

bool KeyManager::IsToggleKey(int _key) // 한번 누르면 on, 다시누르면 false     ex) Caps Lock같은경우.
{
	if (GetKeyState(_key) & 0x0001)
		return true;

	return false;
}
