#include "stdafx.h"
#include "ResourceManager.h"

#include <fstream>	
#include <iostream>
#include <queue>


ResourceManager::ResourceManager()
{
	width = 0;
	height = 0;
	frameX = 0;
	frameY = 0;
	trans = false;
	_r, _g, _b = 0;
}


ResourceManager::~ResourceManager()
{
}

void ResourceManager::AddResource(eReSourceType type, const TCHAR* _fileName)
{
	ParsingData(type, _fileName);

	//switch (type)
	//{
	//case eReSourceType::R_BOMB:
	//	break;
	//case eReSourceType::R_BULLET:

	//	break;
	//case eReSourceType::R_EFFECT:

	//	break;
	//case eReSourceType::R_ITEM:
	//	break;
	//case eReSourceType::R_MONSTER:
	//	break;
	//case eReSourceType::R_PLAYER:
	//	break;
	//case eReSourceType::R_SCORE:
	//	break;
	//case eReSourceType::R_STAGE:
	//	break;
	//}
}

void ResourceManager::ParsingData(eReSourceType type, const TCHAR* _fileName)
{
	char _filePath[256] = { 0 } ;
	switch (type)
	{
	case eReSourceType::R_BOMB:
		//wsprintf(_filePath, TEXT("../Resource/Script/Bomb/%s.bmp"), _fileName);
		_stprintf(_filePath, "../Resource/Script/Bomb/%s.csv", _fileName);
		break;
	case eReSourceType::R_BULLET:
		_stprintf(_filePath, "../Resource/Script/Bullet/%s.csv", _fileName);

		break;
	case eReSourceType::R_EFFECT:
		_stprintf(_filePath, "../Resource/Script/Effect/%s.csv", _fileName);
		break;
	case eReSourceType::R_ITEM:
		_stprintf(_filePath, "../Resource/Script/Item/%s.csv", _fileName);
		break;
	case eReSourceType::R_MONSTER:
		_stprintf(_filePath, "../Resource/Script/Monster/%s.csv", _fileName);
		break;
	case eReSourceType::R_PLAYER:
		_stprintf(_filePath, "../Resource/Script/Player/%s.csv", _fileName);
		break;
	case eReSourceType::R_SCORE:
		_stprintf(_filePath, "../Resource/Script/Score/%s.csv", _fileName);
		break;
	case eReSourceType::R_STAGE:
		_stprintf(_filePath, "../Resource/Script/StageBack/%s.csv", _fileName);
		break;
	}

	std::string sBuffer;
	std::queue<std::string> q_data;
	std::ifstream inFile((_filePath));



	if (!inFile.is_open())
	{
		std::cout << " File is Not Read " << std::endl;
	}


	while (getline(inFile, sBuffer))
	{
		//std::cout << sBuffer << std::endl;
		q_data.push(sBuffer);

	}

	inFile.close();

	q_data.pop();

	std::string sRecord;
	std::string token;
	int iIndex;

	

	while (!q_data.empty())
	{
		sRecord = q_data.front().substr(0, q_data.front().size());
		iIndex = sRecord.find(",");
		token = sRecord.substr(0, iIndex);
		fileKey = token;
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		iIndex = sRecord.find(",");
		token = sRecord.substr(0, iIndex);
		width =atoi(token.c_str());
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		iIndex = sRecord.find(",");
		token = sRecord.substr(0, iIndex);
		height = atoi(token.c_str());
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		iIndex = sRecord.find(",");
		token = sRecord.substr(0, iIndex);
		frameX = atoi(token.c_str());
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		iIndex = sRecord.find(",");
		token = sRecord.substr(0, iIndex);
		frameY = atoi(token.c_str());
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		iIndex = sRecord.find(",");
		token = sRecord.substr(0, iIndex);
		trans = static_cast<bool>(atoi(token.c_str()));
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		iIndex = sRecord.find(",");
		token = sRecord.substr(0, iIndex);
		_r = atoi(token.c_str());
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		iIndex = sRecord.find(",");
		token = sRecord.substr(0, iIndex);
		_g = atoi(token.c_str());
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		iIndex = sRecord.find(",");
		token = sRecord.substr(0, iIndex);
		_b = atoi(token.c_str());
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		q_data.pop();
	}
	transColor = RGB(_r, _g, _b);


	TCHAR _fileImagePath[256] = { 0 ,};
	switch (type)
	{
	case eReSourceType::R_BOMB:
		wsprintf(_fileImagePath, TEXT("../Resource/Image/Bomb/%s.bmp"), _fileName);
		break;
	case eReSourceType::R_BULLET:
		wsprintf(_fileImagePath, TEXT("../Resource/Image/Bomb/%s.bmp"), _fileName);
		break;
	case eReSourceType::R_EFFECT:
		wsprintf(_fileImagePath, TEXT("../Resource/Image/Effect/%s.bmp"), _fileName);
		break;
	case eReSourceType::R_ITEM:
		wsprintf(_fileImagePath, TEXT("../Resource/Image/Item/%s.bmp"), _fileName);
		break;
	case eReSourceType::R_MONSTER:
		wsprintf(_fileImagePath, TEXT("../Resource/Image/Monster/%s.bmp"), _fileName);
		break;
	case eReSourceType::R_PLAYER:
		wsprintf(_fileImagePath, TEXT("../Resource/Image/Player/%s.bmp"), _fileName);
		break;
	case eReSourceType::R_SCORE:
		wsprintf(_fileImagePath, TEXT("../Resource/Image/Score/%s.bmp"), _fileName);
		break;
	case eReSourceType::R_STAGE:
		wsprintf(_fileImagePath, TEXT("../Resource/Image/StageBack/%s.bmp"), _fileName);
		break;
	}

	IMAGEMANAGER->AddFrameImage(fileKey, _fileImagePath, width, height, frameX, frameY, trans, transColor);
}
