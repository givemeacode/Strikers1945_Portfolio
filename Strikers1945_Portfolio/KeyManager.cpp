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

bool KeyManager::IsOnceKeyDown(int _key)	// ���� Ű�� ���Ǵ����� �˰������. (�������´� ���ɻ簡 �ƴ�)
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

bool KeyManager::IsStayKeyDown(int _key) // ���� ��� �������ִ°�� true, �ƴϸ� false
{
	if (GetAsyncKeyState(_key) & 0x8000)
		return true;

	return false;
}

bool KeyManager::IsToggleKey(int _key) // �ѹ� ������ on, �ٽô����� false     ex) Caps Lock�������.
{
	if (GetKeyState(_key) & 0x0001)
		return true;

	return false;
}
