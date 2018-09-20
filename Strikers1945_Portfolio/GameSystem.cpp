#include "stdafx.h"
#include "GameSystem.h"




GameSystem::GameSystem()
{
	GetClientRect(_hWnd, &rcClient);
}


GameSystem::~GameSystem()
{
}


bool GameSystem::Init()
{

	{
		//RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("Bomb_Airplan"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("Bomb_Bullet2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("Bomb_Bullet3"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_BOMB, TEXT("Bomb_Bullet4"));
	}

	//{
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("BMBasic_Bullet2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("MBasic_Bullet"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("MBasic_Bullet2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Stage2_Bullet"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Stage2_Bullet2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_BULLET, TEXT("Bomb_Bullet"));

	//}

	//{
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_3"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_4"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_5"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_6"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_7"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_Boss"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_Crash"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_EFFECT, TEXT("Effect_Power"));


	//}

	//{
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_ITEM, TEXT("Item_Bomb"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_ITEM, TEXT("Item_Power"));

	//}

	//{
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster3"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster4"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster5"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster6"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster7"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster8"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("air_Monster9"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("BigAirPlan"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("BigAirPlan2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_body"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_body2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_change"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_change2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_head"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_head2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_left"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_left2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_propeller"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_right"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Boss_right2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("fish"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("fish2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("MidAirPlan"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_3"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_4"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_5"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_6_left"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_MONSTER, TEXT("Monster_6_right"));


	//}

	//{

	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet_1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet_2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet1")); // 플레이어 총알1
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet2"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet3"));
		RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Bullet4"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("AV_8_Player_Ending"));

	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet3"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet4"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet5"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet6"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Bullet7"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Ending"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Explosion1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F4_Player_Explosion2"));

	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player_Bullet1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player_Bullet2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player_Bullet3"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F22_Player_Ending"));

	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet_Explosion1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet2"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet3"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet4"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet5"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet6"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet7"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Bullet8"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Ending"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_PLAYER, TEXT("F117_Player_Obj"));
	//}

	//{
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_SCORE, TEXT("Score"));
	//}

	//{
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_STAGE, TEXT("Stage_1"));
	//	RESOURCEMANAGER->AddResource(eReSourceType::R_STAGE, TEXT("Stage_2"));

	//}

	return true;
}


RECT GameSystem::GetGameClientRect()
{
	return rcClient;
}

void GameSystem::SetPlayer(Player * _player)
{
	player = _player;
}

