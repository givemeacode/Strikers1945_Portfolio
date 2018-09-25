#include "stdafx.h"
#include "GameSystem.h"

#include "Monster.h"
#include "Player.h"
#include "Gun.h"
#include "Bullet.h"

GameSystem::GameSystem()
{
	GetClientRect(_hWnd, &rcClient);
}


GameSystem::~GameSystem()
{
}


bool GameSystem::Init()
{
	
	// 게임 위치 초기화 
	{
		GamePositionInfoInit();
	}


	// 게임 리소스 추가 

	{
		GameResourceInit();
	}


	return true;
}


RECT GameSystem::GetGameClientRect()
{
	return rcClient;
}

void GameSystem::GamePositionInfoInit()
{
	// RECT ( 왼쪽  )
	{
		posInfo.rcGameLeft1 = RectMakeCenter(50, WINSIZEY / 2, 50, 50);
		posInfo.rcGameLeft2 = RectMakeCenter(50, WINSIZEY / 4, 50, 50);
		posInfo.rcGameLeft3 = RectMakeCenter(50, 25, 50, 50);
	}

	// RECT ( 오른쪽 )
	{
		posInfo.rcGameRight1 = RectMakeCenter(WINSIZEX - 50, WINSIZEY / 2, 50, 50);
		posInfo.rcGameRight2 = RectMakeCenter(WINSIZEX - 50, WINSIZEY / 4, 50, 50);
		posInfo.rcGameRight3 = RectMakeCenter(WINSIZEX - 50, 25, 50, 50);
	}

	// POINT ( 왼쪽 )
	{
		posInfo.ptGameCenterLeft1 = { posInfo.rcGameLeft1.left + ((posInfo.rcGameLeft1.right - posInfo.rcGameLeft1.left) /2 ),
		posInfo.rcGameLeft1.top + ((posInfo.rcGameLeft1.bottom - posInfo.rcGameLeft1.top) / 2) };
		posInfo.ptGameCenterLeft2 = { posInfo.rcGameLeft2.left + ((posInfo.rcGameLeft2.right - posInfo.rcGameLeft2.left) / 2),
		posInfo.rcGameLeft2.top + ((posInfo.rcGameLeft2.bottom - posInfo.rcGameLeft2.top) / 2) };
		posInfo.ptGameCenterLeft3 = { posInfo.rcGameLeft3.left + ((posInfo.rcGameLeft3.right - posInfo.rcGameLeft3.left) / 2),
		posInfo.rcGameLeft3.top + ((posInfo.rcGameLeft3.bottom - posInfo.rcGameLeft3.top) / 2) };
	}

	// POINT ( 오른쪽 ) 
	{
		posInfo.ptGameCenterRight1 = { posInfo.rcGameRight1.left + ((posInfo.rcGameRight1.right - posInfo.rcGameRight1.left) / 2),
		posInfo.rcGameRight1.top + ((posInfo.rcGameRight1.bottom - posInfo.rcGameRight1.top) / 2) };
		posInfo.ptGameCenterRight2 = { posInfo.rcGameRight2.left + ((posInfo.rcGameRight2.right - posInfo.rcGameRight2.left) / 2),
		posInfo.rcGameRight2.top + ((posInfo.rcGameRight2.bottom - posInfo.rcGameRight2.top) / 2) };
		posInfo.ptGameCenterRight3 = { posInfo.rcGameRight3.left + ((posInfo.rcGameRight3.right - posInfo.rcGameRight3.left) / 2),
		posInfo.rcGameRight3.top + ((posInfo.rcGameRight3.bottom - posInfo.rcGameRight3.top) / 2) };
	}


}

void GameSystem::GameResourceInit()
{
	// BOMB
	{
		RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("Bomb_Airplan"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("Bomb_Bullet"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("Bomb_Bullet2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("Bomb_Bullet3"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("Bomb_Bullet4"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("SBomb_Bullet4"));

	}

	 //R_BULLET
	{
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("BMagic_Elec2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("BMBasic_Bullet2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("BMBullet_Straight"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("BossBullet"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Bullet_Explo"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Bullet_Mob_A"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Bullet_Mob_D"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Guide_Bullet"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("LMBullet_Foward"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("LMBullet_Straight"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Magic_Elec"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Magic_Elec2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("MBasic_Bullet"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("MBasic_Bullet2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("MBasic_Bullet2_1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("MGuide_Bullet"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Player_Bullet"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Special_Bullet"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Stage2_Bullet"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Stage2_Bullet2"));

	}

	 //EFFECT
	{
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_3"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_4"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_5"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_6"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_7"));	// 플레이어 데드 이펙트
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_Boss"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_Crash"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_Power"));


	}

	{
		RESOURCEMANAGER->AddResource(eReSourceType::R_ITEM, TEXT("Item_Bomb"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_ITEM, TEXT("Item_Power"));

	}

	{
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster3"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster4"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster5"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster6"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster7"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster8"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster9"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("BigAirPlan"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("BigAirPlan2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_body"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_body2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_change"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_change2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_head"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_head2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_left"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_left2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_propeller"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_right"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_right2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("fish"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("fish2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("MidAirPlan"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_3"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_4"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_5"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_6_left"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_6_right"));


	}

	{

		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet_1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet_2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet1")); // 플레이어 총알1
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet3"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet4"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Ending"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Effect_7"));

		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet3"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet4"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet5"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet6"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet7"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Ending"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Explosion1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Explosion2"));

		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player_Bullet1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player_Bullet2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player_Bullet3"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player_Ending"));

		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet_Explosion1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet3"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet4"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet5"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet6"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet7"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet8"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Ending"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Obj"));

		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Helper"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Helper2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Move_LR_A"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Move_TB_A"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Player"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Player_left"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Player_right"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Player_up"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Player_up2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("Player2"));


	}

	{
		RESOURCEMANAGER->AddResource(eReSourceType::R_SCORE, TEXT("Score"));
	}

	{
		RESOURCEMANAGER->AddResource(eReSourceType::R_STAGE, TEXT("Stage_1"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_STAGE, TEXT("Stage_2"));
	}
}

void GameSystem::SetPlayer(Player * _player)
{
	player = _player;
}

CPOS & GameSystem::GetPosInfo()
{
	return posInfo;
}

void GameSystem::CollisionObject(std::list<Monster*> monsterlist)
{
	std::list<Monster*>::iterator it;
	std::list<Bullet*>::iterator biter;

	// 플레이어 총알 충돌 ( 클라이언트 화면 ) 
	for (biter = player->GetGun()->GetBulletList().begin(); biter != player->GetGun()->GetBulletList().end(); biter++)
	{

		// 몬스터 총알 발사 
		if ((*biter)->GetIsBulletFire())
		{
			if ((*biter)->GetPivotX() <= 15 || (*biter)->GetPivotX() >= WINSIZEX + 15 ||
				(*biter)->GetPivotY() <= 15 || (*biter)->GetPivotY() >= WINSIZEY)
			{
				(*biter)->SetIsBulletFire(false);
			}

			// 몬스터 ( 플레이어 총알 -> 몬스터 순회 ) 
			for (it = monsterlist.begin(); it != monsterlist.end(); it++)
			{
				if (CollisionCircleAndRect((*biter)->GetRadius(), (*biter)->GetPivotX(), (*biter)->GetPivotY(),
					(*it)->GetRectMonster()))
				{
					if ((*it)->GetIsLive())
					{
						(*it)->SetIsLive(false);
						//DeleteObject(monsterlist);
						(*biter)->SetIsBulletFire(false);

					}
					

				}

			}
			
		}
	}


	// 플레이어 총알 삭제 
	for (biter = player->GetGun()->GetBulletList().begin(); biter != player->GetGun()->GetBulletList().end(); )
	{
		if (!(*biter)->GetIsBulletFire())
		{
			biter = player->GetGun()->GetBulletList().erase(biter);

		}
		else
		{
			++biter;
		}
	}



	//===========================================================================================================
	// 몬스터 총알 충돌 ( 클라이언트 화면 ) 
	for (it = monsterlist.begin(); it != monsterlist.end(); it++)
	{
		if ((*it)->GetIsLive())
		{

			// 몬스터 플레이어 충돌 
			if (CollisionCircleAndRect(player->GetRadius(), player->GetX(), player->GetY(), (*it)->GetRectMonster()))
			{
				player->SetIsDead(true);
			}

			// 몬스터와 총알 충돌 
			for (biter = (*it)->GetGun()->GetBulletList().begin(); biter != (*it)->GetGun()->GetBulletList().end(); biter++)
			{
				if ((*biter)->GetIsBulletFire())
				{
					if ((*biter)->GetPivotX() <= 15 || (*biter)->GetPivotX() >= WINSIZEX + 15 ||
						(*biter)->GetPivotY() <= 15 || (*biter)->GetPivotY() >= WINSIZEY)
					{
						(*biter)->SetIsBulletFire(false);
					}
					if (!player->GetIsDead())
					{
						if (CollisionCircleAndCircle((*biter)->GetRadius(), (*biter)->GetPivotX(), (*biter)->GetPivotY(),
							player->GetRadius(), player->GetX(), player->GetY()))
						{
							player->SetIsDead(true);
							(*biter)->SetIsBulletFire(false);

						}

					}

				}
			}
		}
	}


	// 총알 삭제 
	for (it = monsterlist.begin(); it != monsterlist.end(); it++)
	{
		for (biter = (*it)->GetGun()->GetBulletList().begin(); biter != (*it)->GetGun()->GetBulletList().end(); )
		{
			if (!(*biter)->GetIsBulletFire())
			{
				biter = (*it)->GetGun()->GetBulletList().erase(biter);
			}
			else
			{
				++biter;
			}
		}
	}

}

void GameSystem::DeleteObject(std::list<Monster*> monsterlist)
{
	// 몬스터 삭제 
	std::list<Monster*>::iterator it;
	for (it = monsterlist.begin(); it != monsterlist.end(); )
	{
		if (!(*it)->GetIsLive())
		{
			it = monsterlist.erase(it);
		}
		else
		{
			++it;
		}
	}
}

