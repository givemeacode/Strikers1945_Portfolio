#pragma once

// 사용자 정의 빌드 구분

// 메모리 해제 매크로
// Backbuffer
#define SAFE_DELETE(p)	{if(p) {delete(p);(p) = NULL;}}
#define SAFE_RELEASE(p)	{if(p) {(p)->Release(); (p) = NULL;}}

// 윈도우 사이즈 관련 매크로
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define WINSIZEX	1000
#define WINSIZEY	800
#define WINSTARTX	0
#define WINSTARTY	0

// 싱글턴 객체 매크로
#define RAND		RandomFunction::getSingleton()
#define KEYMANAGER	KeyManager::getSingleton()
#define GAMESYS     GameSystem::getSingleton()
#define TIMEMANAGER		TimeManager::getSingleton()
#define IMAGEMANAGER	ImageManager::getSingleton()
#define RESOURCEMANAGER ResourceManager::getSingleton()
#define EFFECTMANAGER	EffectManager::getSingleton()

//
#define PI			3.141592f
#define PI2			PI*2
#define THOU		1000
#define COLOR_M		RGB(255,0,255)