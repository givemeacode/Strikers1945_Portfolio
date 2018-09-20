#include "stdafx.h"
#include "Boss.h"


// 수정
#include "DegreeGun.h"


Boss::Boss()
{
	fHp = 500;
}


Boss::~Boss()
{
}


bool Boss::Init()
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
	aniBossPropellerLeft->setFPS(1.f);
	aniBossPropellerLeft->start();

	bossPropellerRight = IMAGEMANAGER->FindImage(TEXT("Boss_propeller"));
	aniBossPropellerRight = new Animation();
	aniBossPropellerRight->Init(bossPropellerRight);
	aniBossPropellerRight->setDefPlayFrame(false, true);
	aniBossPropellerRight->setFPS(1.f);
	aniBossPropellerRight->start();


	// 위치값 정하기
//	int width = bossBody->GetFrameWidth() + bossLeft->GetFrameWidth() + bossRight->GetFrameWidth();
	int width = bossBody->GetFrameWidth();

	int height = bossBody->GetFrameHeight();

	{
		rcBoss = RectMakeCenter(WINSIZEX / 2 + bossBody->GetFrameWidth() / 2,
			100 + bossBody->GetFrameHeight() / 2,
			bossBody->GetFrameWidth() + bossLeft->GetFrameWidth() + bossRight->GetFrameWidth() + 60,
			bossBody->GetFrameHeight());
		// 보스 위치 지정 
		rcBossBody = RectMakeCenter(WINSIZEX / 2 + bossBody->GetFrameWidth() / 2,
			100 + bossBody->GetFrameHeight() / 2, width, height);

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


	
	//=============CENTERPOINT==================================
	ptBossCenter = {(rcBoss.left + ((rcBoss.right - rcBoss.left)/2)) ,
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
		gun1 = new DegreeGun();
		gun2 = new DegreeGun();
		gun3 = new DegreeGun();
		gun4 = new DegreeGun();

		gun1->Init(ptBossLeftCenter.x , ptBossLeftCenter.y);
		gun2->Init(ptBossRightCenter.x, ptBossRightCenter.y);

		gun3->Init(ptBossBodyCenter.x, ptBossBodyCenter.y + bossBody->GetFrameHeight() /2 );
		gun4->Init(ptBossBodyCenter.x + 50, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);



	}
	//rcBossRight; RectMakeCenter();


	//bossLeft->FrameRender(hdc, WINSIZEX / 2 - bossLeft->GetFrameWidth() + 3, bossBody->GetFrameHeight() / 3 + 140, 0, 0);
	//bossRight->FrameRender(hdc, WINSIZEX / 2 + bossBody->GetFrameWidth() - 3, bossBody->GetFrameHeight() / 3 + 140, 0, 0);
	//bossPropellerLeft->AniRender(hdc,
	//	WINSIZEX / 2 - bossPropellerLeft->GetFrameWidth() + 68,
	//	bossBody->GetFrameHeight() / 2 + 15, aniBossPropellerLeft);
	//bossPropellerRight->AniRender(hdc,
	//	WINSIZEX / 2 + bossBody->GetFrameWidth() - 68,
	//	bossBody->GetFrameHeight() / 2 + 15, aniBossPropellerRight);

	return true;
}

void Boss::Update()
{
	//aniBossBody->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	//aniBossLeft->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	//aniBossRight->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	
	// 이동 
	{
		if (KEYMANAGER->IsStayKeyDown(VK_RIGHT))
		{
			/*rcBoss;
			rcBossBody;
			rcBossLeft;
			rcBossRight;
			rcBossPropellerLeft;
			rcBossPropellerRight;*/
			fHp--;
			ptBossCenter.x += cosf(0) *2.0f;
			ptBossCenter.y += -sinf(0) *2.0f;

			ptBossBodyCenter.x += cosf(0) *2.0f;
			ptBossBodyCenter.y += -sinf(0) *2.0f;
			
			ptBossLeftCenter.x += cosf(0) *2.0f;
			ptBossLeftCenter.y += -sinf(0) *2.0f;
			
			ptBossRightCenter.x += cosf(0) *2.0f;
			ptBossRightCenter.y += -sinf(0) *2.0f;
			
			ptBossPropellerLeftCenter.x += cosf(0) *2.0f;
			ptBossPropellerLeftCenter.y += -sinf(0) *2.0f;
			
			ptBossPropellerRightCenter.x += cosf(0) *2.0f;
			ptBossPropellerRightCenter.y += -sinf(0) *2.0f;

		}

		if (KEYMANAGER->IsStayKeyDown(VK_LEFT))
		{
			fHp--;
			/*rcBoss;
			rcBossBody;
			rcBossLeft;
			rcBossRight;
			rcBossPropellerLeft;
			rcBossPropellerRight;*/

			ptBossCenter.x -= cosf(0) *2.0f;
			ptBossCenter.y -= -sinf(0) *2.0f;

			ptBossBodyCenter.x -= cosf(0) *2.0f;
			ptBossBodyCenter.y -= -sinf(0) *2.0f;
							   
			ptBossLeftCenter.x -= cosf(0) *2.0f;
			ptBossLeftCenter.y -= -sinf(0) *2.0f;

			ptBossRightCenter.x -= cosf(0) *2.0f;
			ptBossRightCenter.y -= -sinf(0) *2.0f;

			ptBossPropellerLeftCenter.x -= cosf(0) *2.0f;
			ptBossPropellerLeftCenter.y -= -sinf(0) *2.0f;

			ptBossPropellerRightCenter.x -= cosf(0) *2.0f;
			ptBossPropellerRightCenter.y -= -sinf(0) *2.0f;

		}
		
	}

	// GUN
	{
		deltaTime += TIMEMANAGER->getElapsedTime();

		if (deltaTime >= 3.0f)
		{
			gun1->BulletFire(ptBossLeftCenter.x, ptBossLeftCenter.y);
			gun2->BulletFire(ptBossRightCenter.x, ptBossRightCenter.y);
			gun3->BulletFire(ptBossBodyCenter.x, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);
			gun4->BulletFire(ptBossBodyCenter.x + 50, ptBossBodyCenter.y + bossBody->GetFrameHeight() / 2);
			deltaTime = 0;
		}
		gun1->BulletMove();
		gun2->BulletMove();
		gun3->BulletMove();
		gun4->BulletMove();
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
	float fResult = (500 * 50) / 100;
	if (fHp > fResult)
	{
		bossLeft->FrameRender(hdc, rcBossLeft.left, rcBossLeft.top, 0, 0);
		bossRight->FrameRender(hdc, rcBossRight.left, rcBossRight.top, 0, 0);
	}
	else
	{
		bossLeft->FrameRender(hdc, rcBossLeft.left, rcBossLeft.top, 1, 0);
		bossRight->FrameRender(hdc, rcBossRight.left, rcBossRight.top, 1, 0);
	}
	
	//bossLeft->FrameRender(hdc, WINSIZEX / 2 - bossLeft->GetFrameWidth() + 13, bossBody->GetFrameHeight() / 3 + 140, 1, 0);
	//bossRight->FrameRender(hdc, WINSIZEX / 2 + bossBody->GetFrameWidth() - 16, bossBody->GetFrameHeight() / 3 + 140, 1, 0);
	bossBody->FrameRender(hdc, rcBossBody.left, rcBossBody.top,0, 0);
	
	bossPropellerLeft->AniRender(hdc,
		rcBossPropellerLeft.left,
		rcBossPropellerLeft.top, aniBossPropellerLeft);
	
	bossPropellerRight->AniRender(hdc,
		rcBossPropellerRight.left,
		rcBossPropellerRight.top, aniBossPropellerRight);

	gun1->Render(hdc);
	gun2->Render(hdc);
	gun3->Render(hdc);
	gun4->Render(hdc);
}
