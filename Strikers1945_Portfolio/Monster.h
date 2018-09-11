#pragma once

enum eMonsterType
{
	MONSTER_TYPE_NONE,
	MONSTER_TYPE_MIDLLEBOSS,
	MONSTER_TYPE_BOSS,
};

class Monster
{
private:

public:
	Monster();
	~Monster();
public:
	void Init();
	void Update();
	void Render(HDC hdc);
};

