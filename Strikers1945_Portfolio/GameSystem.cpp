#include "stdafx.h"
#include "GameSystem.h"
#include "Monster.h"
#include "Gun.h"
#include "Bullet.h"

GameSystem::GameSystem()
{
	GetClientRect(_hWnd, &rcClient);
}


GameSystem::~GameSystem()
{
}


RECT GameSystem::GetGameClientRect()
{
	return rcClient;
}

void GameSystem::SetPlayer(Player * _player)
{
	player = _player;
}

void GameSystem::CollisionCharacter(Monster* _monster, RECT& rcTest)
{
	std::list<Bullet*>::iterator  it;
 	std::list<Bullet*>::iterator itBegin = _monster->GetGun()->GetBulletList().begin();
	std::list<Bullet*>::iterator itEnd = _monster->GetGun()->GetBulletList().end();

	if (!_monster->GetGun()->GetBulletList().empty())
	{
		for (it = itBegin; it != itEnd; it++)
		{
			if ((*it)->GetIsBulletFire())
			{
				if (CollisionCircleAndRect((*it)->GetRadius(), (*it)->GetPivotX(), (*it)->GetPivotY(), rcTest))
				{
					(*it)->SetIsBulletFire(false);
				}
			}
		}
	}
	

}

void GameSystem::GameSceneMonsterInit()
{
}
