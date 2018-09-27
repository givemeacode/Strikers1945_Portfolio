#include "stdafx.h"
#include "Boss.h"


// 수정
#include "DegreeGun.h"
#include "NormalGun.h"
#include "RevolvingGun.h"
#include "MultiGun.h"
#include "GuidedMissileGun.h"

Boss::Boss()
{
	fHp = 500;
	isFirstStop = false;
	isLive = true;
	fSpeed = 2.0f;
	iDir = 1;
	fResult = 0.0f;
	gp = GamePatten::GP_NONE;
	isPatton = false;
	deltaTime1 = 0.0f;
	deltaTime2 = 0.0f;
	deltaTime3 = 0.0f;
	deltaTime4 = 0.0f;
	deltaTime5 = 0.0f;

	coolTime1 = 3.0f;
	coolTime2 = 3.0f;
	coolTime3 = 3.0f;
	coolTime4 = 3.0f;
	coolTime5 = 3.0f;
}


Boss::~Boss()
{
}

bool Boss::Init(int x, int y)
{

	bossBody = IMAGEMANAGER->FindImage(TEXT("Boss_body"));


	//aniBossBody = new Animation();
	//aniBossBody->Init(bossBody);
	//aniBossBody->setDefPlayFrame(false, true);
	//aniBossBody->setFPS(1);
	//aniBossBody->start();

	bossLeft = IMAGEMANAGER->FindImage(TEXT("Boss_left"));

	//aniBossLeft = new Animation();
	//aniBossLeft->Init(bossLeft);
	//aniBossLeft->setDefPlayFrame(false, true);
	//aniBossLeft->setFPS(1);
	//aniBossLeft->start();

	bossRight = IMAGEMANAGER->FindImage(TEXT("Boss_right"));

	//aniBossRight = new Animation();
	//aniBossRight->Init(bossRight);
	//aniBossRight->setDefPlayFrame(false, true);
	//aniBossRight->setFPS(1);
	//aniBossRight->start();

	bossPropellerLeft = IMAGEMANAGER->FindImage(TEXT("Boss_propeller"));
	aniBossPropellerLeft = new Animation();
	aniBossPropellerLeft->Init(bossPropellerLeft);
	aniBossPropellerLeft->setDefPlayFrame(false, true);
	aniBossPropellerLeft->setFPS(1.5f);
	aniBossPropellerLeft->start();

	bossPropellerRight = IMAGEMANAGER->FindImage(TEXT("Boss_propeller"));
	aniBossPropellerRight = new Animation();
	aniBossPropellerRight->Init(bossPropellerRight);
	aniBossPropellerRight->setDefPlayFrame(false, true);
	aniBossPropellerRight->setFPS(1.5f);
	aniBossPropellerRight->start();


	// 위치값 정하기
//	int width = bossBody->GetFrameWidth() + bossLeft->GetFrameWidth() + bossRight->GetFrameWidth();
	int width = bossBody->GetFrameWidth();

	int height = bossBody->GetFrameHeight();

	{
		rcBoss = RectMakeCenter(x ,
			y - bossBody->GetFrameHeight() / 2,
			bossBody->GetFrameWidth() + bossLeft->GetFrameWidth() + bossRight->GetFrameWidth() + 60,
			bossBody->GetFrameHeight());
		// 보스 위치 지정 
		rcBossBody = RectMakeCenter(x,
			y - bossBody->GetFrameHeight() / 2, width, height);

		// 보스 왼쪽 팔
		rcBossLeft = RectMakeCenter(rcBossBody.left - (bossLeft->GetFrameWidth() / 2) + 3,
			rcBoss.top + (bossBody->GetFrameHeight() / 2) + (bossLeft->GetFrameHeight() / 2) - 12,
			bossLeft->GetFrameWidth(), bossLeft->GetFrameHeight());

		// 보스 오른쪽 팔
		rcBossRight = RectMakeCenter(rcBossBody.right + (bossLeft->GetFrameWidth() / 2) - 3,
			rcBoss.top + (bossBody->GetFrameHeight() / 2) + (bossLeft->GetFrameHeight() / 2) - 12,
			bossLeft->GetFrameWidth(), bossLeft->GetFrameHeight());

		rcBossPropellerLeft = RectMakeCenter(rcBossLeft.left + 50,
			rcBossLeft.top + 20,
			bossPropellerLeft->GetFrameWidth(),
			bossPropellerLeft->GetFrameHeight());

		rcBossPropellerRight = RectMakeCenter(rcBossRight.right - 50,
			rcBossRight.top + 20,
			bossPropellerRight->GetFrameWidth(),
			bossPropellerRight->GetFrameHeight());
	}



	//=============CENTER POINT==================================
	ptBossCenter = { (rcBoss.left + ((rcBoss.right - rcBoss.left) / 2)) ,
		(rcBoss.top + ((rcBoss.bottom - rcBoss.top) / 2)) };

	ptBossBodyCenter = { (rcBossBody.left + ((rcBossBody.right - rcBossBody.left) / 2)) ,
		(rcBossBody.top + ((rcBossBody.bottom - rcBossBody.top) / 2)) };

	ptBossLeftCenter = { (rcBossLeft.left + ((rcBossLeft.right - rcBossLeft.left) / 2)) ,
		(rcBossLeft.top + ((rcBossLeft.bottom - rcBossLeft.top) / 2)) };

	ptBossRightCenter = { (rcBossRight.left + ((rcBossRight.right - rcBossRight.left) / 2)) ,
		(rcBossRight.top + ((rcBossRight.bottom - rcBossRight.top) / 2)) };

	ptBossPropellerLeftCenter = { (rcBossPropellerLeft.left + ((rcBossPropellerLeft.right - rcBossPropellerLeft.left) / 2)) ,
		(rcBossPropellerLeft.top + ((rcBossPropellerLeft.bottom - rcBossPropellerLeft.top) / 2)) };

	ptBossPropellerRightCenter = { (rcBossPropellerRight.left + ((rcBossPropellerRight.right - rcBossPropellerRight.left) / 2)) ,
		(rcBossPropellerRight.top + ((rcBossPropellerRight.bottom - rcBossPropellerRight.top) / 2)) };



	// GUN
	{
		gun1 = new NormalGun();
		gun2 = new NormalGun();
		gun3 = new NormalGun();
		gun4 = new NormalGun();
		gun5 = new NormalGun();


		gun1->Init(ptBossLeftCenter.x, ptBossLeftCenter.y);
		gun2->Init(ptBossRightCenter.x, ptBossRightCenter.y);

		gun3->Init(ptBossBodyCenter.x, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);
		gun4->Init(ptBossBodyCenter.x + 50, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);
		gun5->Init(ptBossBodyCenter.x - 50, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);

	}

	{
		// 충돌체 위치 
		rcBossBody = RectMakeCenter(ptBossBodyCenter.x, ptBossBodyCenter.y,
			bossBody->GetFrameWidth(), bossBody->GetFrameHeight());
		rcBossLeft = RectMakeCenter(ptBossLeftCenter.x, ptBossLeftCenter.y,
			bossLeft->GetFrameWidth(), bossLeft->GetFrameHeight());
		rcBossRight = RectMakeCenter(ptBossRightCenter.x, ptBossRightCenter.y,
			bossRight->GetFrameWidth(), bossRight->GetFrameHeight());
	}

	damageBodyImage = IMAGEMANAGER->FindImage(TEXT("Boss_body2"));
	damageRightImage = IMAGEMANAGER->FindImage(TEXT("Boss_right2"));
	damageLeftImage = IMAGEMANAGER->FindImage(TEXT("Boss_left2"));

	//damageEffect->Init(damageBodyImage, damageBodyImage->GetFrameWidth(), damageBodyImage->GetFrameHeight(),
	//	1, 1.0f);
	EFFECTMANAGER->AddEffect(TEXT("DBoss_body2"), TEXT("../Resource/Image/Monster/Boss_body2.bmp"),
		damageBodyImage->GetWidth(), damageBodyImage->GetHeight(),
		damageBodyImage->GetFrameWidth(), damageBodyImage->GetFrameHeight(), 1, 1.0f, 1, RGB(0, 0, 0));
	EFFECTMANAGER->AddEffect(TEXT("DBoss_Left2"), TEXT("../Resource/Image/Monster/Boss_left2.bmp"),
		damageLeftImage->GetWidth(), damageLeftImage->GetHeight(),
		damageLeftImage->GetFrameWidth(), damageLeftImage->GetFrameHeight(), 1, 1.0f, 1, RGB(0, 0, 0));
	EFFECTMANAGER->AddEffect(TEXT("DBoss_Right2"), TEXT("../Resource/Image/Monster/Boss_right2.bmp"),
		damageRightImage->GetWidth(), damageRightImage->GetHeight(),
		damageRightImage->GetFrameWidth(), damageRightImage->GetFrameHeight(), 1, 1.0f, 1, RGB(0, 0, 0));
	return true;
}

bool Boss::Init(const TCHAR * fileName, int x, int y)
{
	return true;
}

bool Boss::Init(const TCHAR * fileName)
{
	return true;
}

bool Boss::Init(const TCHAR * fileName, int number, GAMEPOS pos)
{
	return true;
}


bool Boss::Init()
{
//	bossBody = IMAGEMANAGER->FindImage(TEXT("Boss_body"));
//
//
//	//aniBossBody = new Animation();
//	//aniBossBody->Init(bossBody);
//	//aniBossBody->setDefPlayFrame(false, true);
//	//aniBossBody->setFPS(1);
//	//aniBossBody->start();
//
//	bossLeft = IMAGEMANAGER->FindImage(TEXT("Boss_left"));
//
//	//aniBossLeft = new Animation();
//	//aniBossLeft->Init(bossLeft);
//	//aniBossLeft->setDefPlayFrame(false, true);
//	//aniBossLeft->setFPS(1);
//	//aniBossLeft->start();
//
//	bossRight = IMAGEMANAGER->FindImage(TEXT("Boss_right"));
//
//	//aniBossRight = new Animation();
//	//aniBossRight->Init(bossRight);
//	//aniBossRight->setDefPlayFrame(false, true);
//	//aniBossRight->setFPS(1);
//	//aniBossRight->start();
//
//	bossPropellerLeft = IMAGEMANAGER->FindImage(TEXT("Boss_propeller"));
//	aniBossPropellerLeft = new Animation();
//	aniBossPropellerLeft->Init(bossPropellerLeft);
//	aniBossPropellerLeft->setDefPlayFrame(false, true);
//	aniBossPropellerLeft->setFPS(1.f);
//	aniBossPropellerLeft->start();
//
//	bossPropellerRight = IMAGEMANAGER->FindImage(TEXT("Boss_propeller"));
//	aniBossPropellerRight = new Animation();
//	aniBossPropellerRight->Init(bossPropellerRight);
//	aniBossPropellerRight->setDefPlayFrame(false, true);
//	aniBossPropellerRight->setFPS(1.f);
//	aniBossPropellerRight->start();
//
//
//	// 위치값 정하기
////	int width = bossBody->GetFrameWidth() + bossLeft->GetFrameWidth() + bossRight->GetFrameWidth();
//	int width = bossBody->GetFrameWidth();
//
//	int height = bossBody->GetFrameHeight();
//
//	{
//		rcBoss = RectMakeCenter(WINSIZEX / 2 + bossBody->GetFrameWidth() / 2,
//			100 + bossBody->GetFrameHeight() / 2,
//			bossBody->GetFrameWidth() + bossLeft->GetFrameWidth() + bossRight->GetFrameWidth() + 60,
//			bossBody->GetFrameHeight());
//		// 보스 위치 지정 
//		rcBossBody = RectMakeCenter(WINSIZEX / 2 + bossBody->GetFrameWidth() / 2,
//			100 + bossBody->GetFrameHeight() / 2, width, height);
//
//		// 보스 왼쪽 팔
//		rcBossLeft = RectMakeCenter(rcBossBody.left - (bossLeft->GetFrameWidth() / 2) + 3,
//			rcBoss.top + (bossBody->GetFrameHeight() / 2) + (bossLeft->GetFrameHeight() / 2) - 12,
//			bossLeft->GetFrameWidth(), bossLeft->GetFrameHeight());
//
//		// 보스 오른쪽 팔
//		rcBossRight = RectMakeCenter(rcBossBody.right + (bossLeft->GetFrameWidth() / 2) - 3,
//			rcBoss.top + (bossBody->GetFrameHeight() / 2) + (bossLeft->GetFrameHeight() / 2) - 12,
//			bossLeft->GetFrameWidth(), bossLeft->GetFrameHeight());
//
//		rcBossPropellerLeft = RectMakeCenter(rcBossLeft.left + 50,
//			rcBossLeft.top + 20,
//			bossPropellerLeft->GetFrameWidth(),
//			bossPropellerLeft->GetFrameHeight());
//
//		rcBossPropellerRight = RectMakeCenter(rcBossRight.right - 50,
//			rcBossRight.top + 20,
//			bossPropellerRight->GetFrameWidth(),
//			bossPropellerRight->GetFrameHeight());
//	}
//
//
//	
//	//=============CENTERPOINT==================================
//	ptBossCenter = {(rcBoss.left + ((rcBoss.right - rcBoss.left)/2)) ,
//		(rcBoss.top + ((rcBoss.bottom - rcBoss.top) / 2)) };
//
//	ptBossBodyCenter = { (rcBossBody.left + ((rcBossBody.right - rcBossBody.left) / 2)) ,
//		(rcBossBody.top + ((rcBossBody.bottom - rcBossBody.top) / 2)) };
//	
//	ptBossLeftCenter = { (rcBossLeft.left + ((rcBossLeft.right - rcBossLeft.left) / 2)) ,
//		(rcBossLeft.top + ((rcBossLeft.bottom - rcBossLeft.top) / 2)) };
//	
//	ptBossRightCenter = { (rcBossRight.left + ((rcBossRight.right - rcBossRight.left) / 2)) ,
//		(rcBossRight.top + ((rcBossRight.bottom - rcBossRight.top) / 2)) };
//	
//	ptBossPropellerLeftCenter = { (rcBossPropellerLeft.left + ((rcBossPropellerLeft.right - rcBossPropellerLeft.left) / 2)) ,
//		(rcBossPropellerLeft.top + ((rcBossPropellerLeft.bottom - rcBossPropellerLeft.top) / 2)) };
//	
//	ptBossPropellerRightCenter = { (rcBossPropellerRight.left + ((rcBossPropellerRight.right - rcBossPropellerRight.left) / 2)) ,
//		(rcBossPropellerRight.top + ((rcBossPropellerRight.bottom - rcBossPropellerRight.top) / 2)) };
//
//
//
//	// GUN
//	{
//		gun1 = new NormalGun();
//		gun2 = new NormalGun();
//		gun3 = new NormalGun();
//		gun4 = new NormalGun();
//		gun5 = new NormalGun();
//
//
//		gun1->Init(ptBossLeftCenter.x , ptBossLeftCenter.y);
//		gun2->Init(ptBossRightCenter.x, ptBossRightCenter.y);
//
//		gun3->Init(ptBossBodyCenter.x, ptBossBodyCenter.y + bossBody->GetFrameHeight() /2 );
//		gun4->Init(ptBossBodyCenter.x + 50, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);
//		gun5->Init(ptBossBodyCenter.x - 50, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);
//
//
//
//
//	}
//	//rcBossRight; RectMakeCenter();
//
//
//	//bossLeft->FrameRender(hdc, WINSIZEX / 2 - bossLeft->GetFrameWidth() + 3, bossBody->GetFrameHeight() / 3 + 140, 0, 0);
//	//bossRight->FrameRender(hdc, WINSIZEX / 2 + bossBody->GetFrameWidth() - 3, bossBody->GetFrameHeight() / 3 + 140, 0, 0);
//	//bossPropellerLeft->AniRender(hdc,
//	//	WINSIZEX / 2 - bossPropellerLeft->GetFrameWidth() + 68,
//	//	bossBody->GetFrameHeight() / 2 + 15, aniBossPropellerLeft);
//	//bossPropellerRight->AniRender(hdc,
//	//	WINSIZEX / 2 + bossBody->GetFrameWidth() - 68,
//	//	bossBody->GetFrameHeight() / 2 + 15, aniBossPropellerRight);
//
	return true;
}

void Boss::Update()
{
	if (NULL == gun1 || NULL == gun2 || NULL == gun3 || NULL == gun4 || NULL == gun5)
	{
		return;
	}

	if (fHp <= 0)
	{
		isLive = false;
	}
	//aniBossBody->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	//aniBossLeft->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	//aniBossRight->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	/*
	ptBossCenter;
	ptBossBodyCenter;
	ptBossLeftCenter;
	ptBossRightCenter;
	ptBossPropellerLeftCenter;
	ptBossPropellerRightCenter;
	*/
	// 이동 
	{
		// 예외 처리 

		if (ptBossBodyCenter.y >= WINSIZEY + (bossBody->GetFrameHeight() + 200.f))
		{
			isLive = false;
			return;
		}
	}
	{
		// ====================================== 처음 내려 온다.
		if (!isFirstStop)
		{
			ptBossCenter.y += -sinf(PI + PI / 2) *2.0f;
			ptBossBodyCenter.y += -sinf(PI + PI / 2) *2.0f;
			ptBossLeftCenter.y += -sinf(PI + PI / 2) *2.0f;
			ptBossRightCenter.y += -sinf(PI + PI / 2) *2.0f;
			ptBossPropellerLeftCenter.y += -sinf(PI + PI / 2) *2.0f;
			ptBossPropellerRightCenter.y += -sinf(PI + PI / 2) *2.0f;

			if (ptBossCenter.y >= 300 ||
				ptBossBodyCenter.y >= 300 ||
				ptBossLeftCenter.y >= 300 ||
				ptBossRightCenter.y >= 300 ||
				ptBossPropellerLeftCenter.y >= 300 ||
				ptBossPropellerRightCenter.y >= 300)
			{
				isFirstStop = true;
				ptBossCenter.y = ptBossCenter.y;
				ptBossBodyCenter.y = ptBossBodyCenter.y;
				ptBossLeftCenter.y = ptBossLeftCenter.y;
				ptBossRightCenter.y = ptBossRightCenter.y;
				ptBossPropellerLeftCenter.y = ptBossPropellerLeftCenter.y;
				ptBossPropellerRightCenter.y = ptBossPropellerRightCenter.y;
			}

		}
		
		

		if (isFirstStop)
		{
			// 좌우 이동
			ptBossCenter.x += cosf(PI * iDir) *fSpeed;
			ptBossBodyCenter.x += cosf(PI* iDir) *fSpeed;
			ptBossLeftCenter.x += cosf(PI* iDir) *fSpeed;
			ptBossRightCenter.x += cosf(PI* iDir) *fSpeed;
			ptBossPropellerLeftCenter.x += cosf(PI* iDir) *fSpeed;
			ptBossPropellerRightCenter.x += cosf(PI* iDir) *fSpeed;

			if (rcBoss.left <= 100)
			{
				iDir = 0;
			}
			
			if (rcBoss.right >= 900)
			{
				iDir = 1;
			}

			fResult = (500 * 80) / 100;

			if (!isPatton && fHp < fResult)
			{
  				//gun1->Release();
				SAFE_DELETE(gun1);
				gun1 = new RevolvingGun();
				gun1->Init(ptBossLeftCenter.x, ptBossLeftCenter.y);
				//isFirstStop = false;
				coolTime1 = 2.0f;
				gp = GamePatten::GAMEPATTEN1;
				isPatton = true;
			}
			
		}

		switch (gp)
		{
		case GamePatten::GAMEPATTEN1:
		{
			fResult = (500 * 60) / 100;
			if (fHp > fResult)
			{
				//gun2->Release();
				SAFE_DELETE(gun2);
				gun2 = new RevolvingGun();
				gun2->Init(ptBossLeftCenter.x, ptBossLeftCenter.y);
				fSpeed = 3.0f;
				coolTime2 = 2.0f;
			}
		}
			break;
		case GamePatten::GAMEPATTEN2:
		{
			fResult = (500 * 40) / 100;
			if (fHp > fResult)
			{
				//gun2->Release();
				SAFE_DELETE(gun3);
				gun3 = new MultiGun();
				gun3->Init(ptBossLeftCenter.x, ptBossLeftCenter.y);
				fSpeed = 3.5f;
				coolTime3 = 4.0f;
			}
		}
			break;
		case GamePatten::GAMEPATTEN3:
		{
			fResult = (500 * 20) / 100;
			if (fHp > fResult)
			{
				//gun2->Release();
				SAFE_DELETE(gun4);
				gun4 = new DegreeGun();
				gun4->Init(ptBossLeftCenter.x, ptBossLeftCenter.y);
				fSpeed = 3.0f;
				coolTime4 = 3.0f;

				SAFE_DELETE(gun5);
				gun5 = new GuidedMissileGun();
				gun5->Init(ptBossLeftCenter.x, ptBossLeftCenter.y);
				fSpeed = 3.0f;
				coolTime5 = 2.0f;
			}
		}
			break;
		}

		if (fHp < 20)
		{
			isFirstStop = false;
		}
		//=========================================
	

	}

	// GUN
	{
		deltaTime1 += TIMEMANAGER->getElapsedTime();
		deltaTime2 += TIMEMANAGER->getElapsedTime();
		deltaTime3 += TIMEMANAGER->getElapsedTime();
		deltaTime4 += TIMEMANAGER->getElapsedTime();
		deltaTime5 += TIMEMANAGER->getElapsedTime();


		if (deltaTime1 >=coolTime1)
		{
			gun1->BulletFire(ptBossLeftCenter.x, ptBossLeftCenter.y);
			
			deltaTime1 = 0;
		}

		if (deltaTime2 >= coolTime2)
		{
			gun2->BulletFire(ptBossRightCenter.x, ptBossRightCenter.y);
			
			deltaTime2 = 0;
		}

		if (deltaTime3 >= coolTime3)
		{
			gun3->BulletFire(ptBossBodyCenter.x, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);
			
			deltaTime3 = 0;
		}

		if (deltaTime4 >= coolTime4)
		{
			gun4->BulletFire(ptBossBodyCenter.x + 50, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);

			deltaTime4 = 0;
		}

		if (deltaTime5 >= coolTime5)
		{
			gun5->BulletFire(ptBossBodyCenter.x - 50, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);

			deltaTime5 = 0;
		}

		gun1->BulletMove();
		gun2->BulletMove();
		gun3->BulletMove();
		gun4->BulletMove();
		gun5->BulletMove();
	}

	{
		rcBoss = RectMakeCenter(ptBossCenter.x, ptBossCenter.y,
			bossBody->GetFrameWidth() + bossLeft->GetFrameWidth() + bossRight->GetFrameWidth() + 60,
			bossBody->GetFrameHeight());

		rcBossBody = RectMakeCenter(ptBossBodyCenter.x, ptBossBodyCenter.y,
			bossBody->GetFrameWidth(),
			bossBody->GetFrameHeight());

		rcBossLeft = RectMakeCenter(ptBossLeftCenter.x, ptBossLeftCenter.y,
			bossLeft->GetFrameWidth(),
			bossLeft->GetFrameHeight());

		rcBossRight = RectMakeCenter(ptBossRightCenter.x, ptBossRightCenter.y,
			bossRight->GetFrameWidth(),
			bossRight->GetFrameHeight());

		rcBossPropellerLeft = RectMakeCenter(ptBossPropellerLeftCenter.x, ptBossPropellerLeftCenter.y,
			bossPropellerLeft->GetFrameWidth(),
			bossPropellerLeft->GetFrameHeight());

		rcBossPropellerRight = RectMakeCenter(ptBossPropellerRightCenter.x, ptBossPropellerRightCenter.y,
			bossPropellerRight->GetFrameWidth(),
			bossPropellerRight->GetFrameHeight());

	}


	// ANI
	{
		aniBossPropellerLeft->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
		aniBossPropellerRight->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	}
}

void Boss::Render(HDC hdc)
{
	//bossBody->FrameRender(hdc, WINSIZEX / 2, WINSIZEY / 2);
	//bossBody->AniRender(hdc, WINSIZEX / 2, 100, aniBossBody);
	//bossLeft->AniRender(hdc, WINSIZEX / 2 , 100, aniBossLeft);
	//bossRight->AniRender(hdc, WINSIZEX / 2 + bossBody->GetFrameWidth(), 100, aniBossRight);

	//DrawObject(hdc, rcBoss, 1, RGB(155, 0, 155), RECTANGLE);
	//DrawObject(hdc, rcBossBody, 1, RGB(0, 155, 155), RECTANGLE);
	//DrawObject(hdc, rcBossLeft, 1, RGB(0, 255, 255), RECTANGLE);
	//DrawObject(hdc, rcBossRight, 1, RGB(0, 255, 255), RECTANGLE);
	//DrawObject(hdc, rcBossPropellerLeft, 1, RGB(125, 125, 0), RECTANGLE);
	//DrawObject(hdc, rcBossPropellerRight, 1, RGB(125, 125, 0), RECTANGLE);


	//============================================================

	if (isLive)
	{
		bossBody->FrameRender(hdc, rcBossBody.left, rcBossBody.top, 0, 0);


		float fResult = (500 * 50) / 100;

		if (fHp > fResult)
		{
			bossLeft->FrameRender(hdc, rcBossLeft.left, rcBossLeft.top, 0, 0);
			bossRight->FrameRender(hdc, rcBossRight.left, rcBossRight.top, 0, 0);

			bossPropellerLeft->AniRender(hdc,
				rcBossPropellerLeft.left,
				rcBossPropellerLeft.top, aniBossPropellerLeft);

			bossPropellerRight->AniRender(hdc,
				rcBossPropellerRight.left,
				rcBossPropellerRight.top, aniBossPropellerRight);
		}
		else
		{
			bossLeft->FrameRender(hdc, rcBossLeft.left + 11, rcBossLeft.top, 1, 0);
			bossRight->FrameRender(hdc, rcBossRight.left - 14, rcBossRight.top, 1, 0);

			bossPropellerLeft->AniRender(hdc,
				rcBossPropellerLeft.left + 3,
				rcBossPropellerLeft.top, aniBossPropellerLeft);

			bossPropellerRight->AniRender(hdc,
				rcBossPropellerRight.left - 3,
				rcBossPropellerRight.top, aniBossPropellerRight);


		}

		gun1->Render(hdc);
		gun2->Render(hdc);
		gun3->Render(hdc);
		gun4->Render(hdc);
		gun5->Render(hdc);


		EFFECTMANAGER->Render(hdc);

	}
	
}

void Boss::Release()
{
	gun1->Release();
	gun2->Release();
	gun3->Release();
	gun4->Release();
	gun5->Release();

	EFFECTMANAGER->Release();
	damageBodyImage->Release();
	damageLeftImage->Release();
	damageRightImage->Release();
}

void Boss::DeCreaseHp(float _damage)
{
	fHp -= _damage;
	EFFECTMANAGER->Play(TEXT("DBoss_body2"), ptBossBodyCenter);
	EFFECTMANAGER->Play(TEXT("DBoss_Left2"), ptBossLeftCenter);
	EFFECTMANAGER->Play(TEXT("DBoss_Right2"), ptBossRightCenter);

}
