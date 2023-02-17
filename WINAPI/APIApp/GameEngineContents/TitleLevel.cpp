#include "TitleLevel.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "TitleBack.h"

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}


void TitleLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Title");

	// 이미지 로드
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("backgroud_title.BMP"));
		GameEngineImage* Image1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("title_ani1.BMP"));
						 Image1->Cut(5, 1);
	}

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');
	}

	CreateActor<TitleBack>();

	Start = float4::Zero;
	End = float4(0.0f, GameEngineWindow::GetScreenSize().half().y);

}

bool ScrollStart = false;
float4 DownPosTitle = float4::Zero;

void TitleLevel::Update(float _DeltaTime)
{
	// if (true == GameEngineInput::IsDown("LevelChange"))
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayLevel");
	}



	//if (true == ScrollStart)
	//{
	//	// 시작에서 끝까지 이동하는데 1초가 걸리는 함수
	//	Time += _DeltaTime * 0.5f;
	//	float4 Pos = float4::LerpClamp(Start, End, Time);
	//	SetCameraPos(Pos);

	//	if (Time >= 1.0f)
	//	{
	//		ScrollStart = false;
	//		Time = 0.0f;
	//		Start = Pos;
	//	}
	}


