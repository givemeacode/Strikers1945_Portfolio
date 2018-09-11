#include "stdafx.h"
#include "GameNode.h"

GameNode::GameNode()
{
}

GameNode::~GameNode()
{
}

void GameNode::SetBackBuffer()
{
	_backBuffer = new Backbuffer;
	_backBuffer->Init(WINSIZEX, WINSIZEY);

}

bool GameNode::Init()
{
	SetTimer(_hWnd, 1, 10, NULL);
	SetBackBuffer();
	return false;
}

void GameNode::Release()
{
	KillTimer(_hWnd, 1);
}

void GameNode::Update()
{
	InvalidateRect(_hWnd, NULL, false);
}

void GameNode::Render(HDC hdc)
{
}

LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT	ps;
	
	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_TIMER:
		this->Update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		this->Render(hdc);

		EndPaint(_hWnd, &ps);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
