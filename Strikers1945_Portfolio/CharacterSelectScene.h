#pragma once
#include "GameNode.h"

class CharacterSelectScene : public GameNode
{
	Image* CharacterSelectImage;
	int characterSelectIndex; // 선택 인덱스
	
	Image* redTimerImage;
	int redTimerIndex; // 인덱스
	
	int whoIsChoice;

	bool isChoice;

	// 시간체크에 필요한것들
	DWORD runTimer;	  // 전체 진행시간 체크
	DWORD startTimer; // 전체 시작시간

	int choiceTime;	// 선택 시간.
public:
	CharacterSelectScene();
	~CharacterSelectScene();
public:
	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
public:
	//
	void ChoiceKey();
	void SelectKeyAndTimeOver();

	//
	inline int GetSelect() { return whoIsChoice; }

	inline void	SetSelect(int _CharacterSelectIndex)
	{
		whoIsChoice = _CharacterSelectIndex + 1;
	}
};

