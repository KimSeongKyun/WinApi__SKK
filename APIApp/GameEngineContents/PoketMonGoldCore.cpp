#include "PoketMonGoldCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "PlayLevel.h"
#include "TitleLevel.h"

// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// �߰��� ����� �������� �����ָ� ������������ ���� �����Ҵ��ؼ� ����Ѵٴ°�
// �������⿡�� ��??? �׷�������?
PoketMonGoldCore PoketMonGoldCore::Core;

PoketMonGoldCore::PoketMonGoldCore() 
{
}

PoketMonGoldCore::~PoketMonGoldCore() 
{

}

void PoketMonGoldCore::Start()
{
	// ������ ���� �������? ������ ������ ���ɴϴ�.
	// �Ǽ� 1.2 ���Ѵٸ� 
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