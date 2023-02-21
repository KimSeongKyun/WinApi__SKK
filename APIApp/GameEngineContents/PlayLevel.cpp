#include "PlayLevel.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>

// 나랑 같은 등급의 헤더들
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "ContentsEnums.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Loading()
{
	// 상대경로 탐색
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// 이미지 로드
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Player.BMP"));
		Image->Cut(10, 3);
	}
	{
		GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map.BMP"));
		GameEngineImage* Image3 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ColMap.BMP"));
	}
	{
		GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Number.BMP"));
		Image2->Cut(10, 1);
	}

	{
		Map* Actor = CreateActor<Map>();
	}
	{	
		float ErrorRange = 40.0f;
		float4 StartLocation = { 2720.0f + ErrorRange, 1600.0f - ErrorRange };
		Player* Actor = CreateActor<Player>(PoketMonRenderOrder::Player);
		Actor->SetMove(StartLocation);
		
	}
	{
		/*srand(static_cast<unsigned int>(time(nullptr)));
		for (size_t i = 0; i < 0; i++)
		{
			Monster* Actor = CreateActor<Monster>(PoketMonRenderOrder::Monster);
			Actor->SetMove(
				float4(static_cast<float>(rand() % GameEngineWindow::GetScreenSize().ix()), static_cast<float>(rand() % GameEngineWindow::GetScreenSize().iy()))
			);
		}*/
	}


	if (false == GameEngineInput::IsKey("DebugRenderSwitch"))
	{
		GameEngineInput::CreateKey("DebugRenderSwitch", 'R');
	}

	if (false == GameEngineInput::IsKey("MenuOpen"))
	{
		GameEngineInput::CreateKey("MenuOpen", VK_RETURN );
	}
	// class NumbersRender : GameEngineActor
	// {
	// }

	// NumbersRender = CreateActor<NumbersRender>();
	// NumbersRender->SetValue(190111);
}

void PlayLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("DebugRenderSwitch"))
	{
		DebugRenderSwitch();
		// Player::MainPlayer->Death()p;
	}

	if (GameEngineInput::IsDown("MenuOpen"))
	{
		if (MenuOpen == false)
		{
			MenuOpen = true;
		}

		if (MenuOpen == true)
		{
			MenuOpen = false;
		}
			
	}
	float4 Pos = Player::MainPlayer->GetPos();
	SetCameraPos(Pos - GameEngineWindow::GetScreenSize().half());
	
}

void PlayLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

bool PlayLevel::GetMenuOpen()
{
	return MenuOpen;
}
