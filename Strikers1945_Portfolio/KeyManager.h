#pragma once
#include "SingleTon.h"
#include <bitset>

using std::bitset;

#define KEYMAX 256

class KeyManager : public SingletonBase<KeyManager>
{
private:
	bitset<KEYMAX> _keyUp; // 키 상태 저장
	bitset<KEYMAX> _keyDown;
public:
	KeyManager();
	virtual ~KeyManager();

	bool Init();
	void Release();

	bool IsOnceKeyDown(int _key);
	bool IsOnceKeyUp(int _key);
	bool IsStayKeyDown(int _key);
	bool IsToggleKey(int _key);

	bitset<KEYMAX> GetKeyUp() { return _keyUp; }
	bitset<KEYMAX> GetKeyDown() { return _keyDown; }

	void setKeyDown(int _key, bool _state)
	{
		_keyDown.set(_key, _state);
	}

	void setKeyUp(int _key, bool _state)
	{
		_keyUp.set(_key, _state);
	}
};

