#pragma once

class Gun;

class Boss
{
private:
	float fHp;
	bool IsLive;
	float deltaTime = 0;
private:
	Gun* gun1;
	Gun* gun2;
	Gun* gun3;
	Gun* gun4;
private:
	Image* bossBody;
	Animation* aniBossBody;

	Image* bossLeft;
	Animation* aniBossLeft;

	Image* bossRight;
	Animation* aniBossRight;

	Image* bossPropellerLeft;
	Animation* aniBossPropellerLeft;

	Image* bossPropellerRight;
	Animation* aniBossPropellerRight;

private:
	RECT rcBoss;
	RECT rcBossBody;
	RECT rcBossLeft;
	RECT rcBossRight;
	RECT rcBossPropellerLeft;
	RECT rcBossPropellerRight;

	POINT ptBossCenter;
	POINT ptBossBodyCenter;
	POINT ptBossLeftCenter;
	POINT ptBossRightCenter;
	POINT ptBossPropellerLeftCenter;
	POINT ptBossPropellerRightCenter;

public:
	Boss();
	~Boss();
public:
	bool Init();
	void Update();
	void Render(HDC hdc);
};

