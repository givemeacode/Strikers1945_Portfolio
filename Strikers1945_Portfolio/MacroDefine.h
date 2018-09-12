#pragma once

// ����� ���� ���� ����





// �޸� ���� ��ũ��
// Backbuffer
#define SAFE_DELETE(p)	{if(p) {delete(p);(p) = NULL;}}
#define SAFE_RELEASE(p)	{if(p) {(p)->Release(); (p) = NULL;}}

// ������ ������ ���� ��ũ��
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define WINSIZEX	800
#define WINSIZEY	800
#define WINSTARTX	0
#define WINSTARTY	0

// �̱��� ��ü ��ũ��
#define RAND		RandomFunction::getSingleton()
#define KEYMANAGER	KeyManager::getSingleton()

//
#define PI			3.141592f
#define PI2			PI*2