#pragma once

enum GamePatten
{
	GAMEPATTEN1,
	GAMEPATTEN2,
	GAMEPATTEN3,
	GP_NONE,
};
class Gun;

class Boss
{
private:
	bool isLive;
	float fHp;
	bool isPatton;
	float deltaTime1;
	float deltaTime2;
	float deltaTime3;
	float deltaTime4;
	float deltaTime5;

	float coolTime1;
	float coolTime2;
	float coolTime3;
	float coolTime4;
	float coolTime5;


private:
	Gun* gun1;
	Gun* gun2;
	Gun* gun3;
	Gun* gun4;
	Gun* gun5;
	GamePatten gp;
	float fResult;
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
private:
	Effect* damageEffect;
	Image* damageBodyImage;
	Image* damageLeftImage;
	Image* damageRightImage;

private:
	bool isFirstStop;
	float fSpeed;
	int iDir;
public:
	Boss();
	~Boss();
public:
	 bool Init(int x, int y);
	
	void Update();
	void Render(HDC hdc);
	void Release();
public:
	void DeCreaseHp(float _damage);

	RECT GetRectBossBody() { return rcBossBody; }
	RECT GetRectBossLeft() { return rcBossLeft; }
	RECT GetRectBossRight() { return rcBossRight; }

	POINT GetPointBossCenter() { return ptBossCenter; }
	POINT GetPointBossBodyCenter() { return ptBossBodyCenter; }
	POINT GetPointBossLeftCenter() { return ptBossLeftCenter; }
	POINT GetPointBossRightCenter() { return ptBossRightCenter; }
	
	Gun* GetGun1() { return gun1; }
	Gun* GetGun2() { return gun2; }
	Gun* GetGun3() { return gun3; }
	Gun* GetGun4() { return gun4; }
	Gun* GetGun5() { return gun5; }

	bool GetIsLive() { return isLive; }
	void SetIsLive(bool _isLive) { isLive = _isLive; }

};	
	
