#include "stdafx.h"
#include "TitleScene.h"


TitleScene::TitleScene()
{
	sceneType = eSceneType::SCENE_TITLE;
}


TitleScene::~TitleScene()
{
}

bool TitleScene::Init()
{
	TitleLogo = new Image;
	TitleLogo->Init(TEXT("../Resource/Image/logo/logo.bmp"), 800, 900, 1, 1, false, RGB(0, 0, 0));
	TitleLogo->SetX(100); // set은 화면에서 그려기 시작할 위치 x값, y값.
	TitleLogo->SetY(0);
	return true;
}

void TitleScene::Release()
{
	SAFE_DELETE(TitleLogo);
}

void TitleScene::Update()
{
	if (KEYMANAGER->IsOnceKeyDown(VK_RETURN))
	{
		SceneManager::getSingleton()->ChangeScene(eSceneType::SCENE_CHARACTER);

	}
}

void TitleScene::Render(HDC hdc)
{
	//	TitleLogo->FrameRender(hdc, 100, 0, 2, 1);
	TitleLogo->FrameRender(hdc, TitleLogo->GetX(), TitleLogo->GetY(),
		TitleLogo->GetFrameX(), TitleLogo->GetFrameY());
}