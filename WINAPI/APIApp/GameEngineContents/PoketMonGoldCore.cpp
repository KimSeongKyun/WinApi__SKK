#include "PoketMonGoldCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "PlayLevel.h"
#include "TitleLevel.h"

// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// 중간에 절대로 지워지지 않을애를 포인터형으로 만들어서 동적할당해서 사용한다는건
// 제가보기에는 왜??? 그래야하지?
PoketMonGoldCore PoketMonGoldCore::Core;

PoketMonGoldCore::PoketMonGoldCore() 
{
}

PoketMonGoldCore::~PoketMonGoldCore() 
{
}

void PoketMonGoldCore::Start()
{
	// 정수의 연산 결과값은? 무조건 정수만 나옵니다.
	// 실수 1.2 원한다면 
	GameEngineWindow::SettingWindowSize({800, 720});

	new int();

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<PlayLevel>("PlayLevel");
	ChangeLevel("TitleLevel");
}

void PoketMonGoldCore::Update()
{
	
}
void PoketMonGoldCore::End() 
{
	
}