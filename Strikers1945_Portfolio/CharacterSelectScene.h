#pragma once
#include "GameNode.h"

class CharacterSelectScene : public GameNode
{
	Image* CharacterSelectImage;
	int characterSelectIndex; // ���� �ε���
	
	Image* redTimerImage;
	int redTimerIndex; // �ε���
	
	int whoIsChoice;

	bool isChoice;

	// �ð�üũ�� �ʿ��Ѱ͵�
	DWORD runTimer;	  // ��ü ����ð� üũ
	DWORD startTimer; // ��ü ���۽ð�

	int choiceTime;	// ���� �ð�.
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

