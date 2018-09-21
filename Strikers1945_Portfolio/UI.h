#pragma once

class UI
{
	Image* scoreImage;
	Image* scoreImage10;
	Image* scoreImage100;
	Image* scoreImage1000;
	Image* scoreImage10000;

	int scoreIndex;
	int scoreIndex10;
	int scoreIndex100;
	int scoreIndex1000;
	int scoreIndex10000;

	
	int score;
	

public:
	UI();
	~UI();
public:
	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
public:
	void ScoreFunc(int _score);
public:
	int getScore() { return score; }
	void SetScore(int _score) { score = _score; }
};

