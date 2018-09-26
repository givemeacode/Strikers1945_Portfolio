#pragma once

// 사용자 정의 자료형

//enum DS_STATE
//{
//	LEFT = -1,
//	NONE,
//	RIGHT = 1
//};

//Extern

extern HWND			_hWnd;
extern HINSTANCE	_hInst;
extern POINT		_ptMouse;


enum OBJ_TYPE
{
	ELLIPSE = 0,
	RECTANGLE,

};


struct SPERE
{
	float x, y;
	float r;
};

enum GAMEPOS
{
	G_NONE, 

	G_LEFT1,
	G_LEFT2,
	G_LEFT3,

	G_RIGHT1,
	G_RIGHT2,
	G_RIGHT3,

	G_UPDOWN,

	G_CENTER,
	

};