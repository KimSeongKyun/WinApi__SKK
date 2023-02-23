#include "PlayLevel.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>


// 나랑 같은 등급의 헤더들
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "ContentsEnums.h"
#include "Menu.h"

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
		GameEngineImage* Player = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Player.BMP"));
		Player->Cut(10, 3);
	}
	{
		GameEngineImage* Map = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map.BMP"));
		GameEngineImage* Menu = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Menu.BMP"));
		//GameEngineImage* ColMap = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ColMap.BMP"));
	}
	{
	/*	GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Number.BMP"));
		Image2->Cut(10, 1);*/
		//GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Number.BMP"));
		
	
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
		Player::MainPlayer->ChangeMenuOpen();
	}

float4 Pos = Player::MainPlayer->GetPos();
	SetCameraPos(Pos - GameEngineWindow::GetScreenSize().half());

if (Player::MainPlayer->GetMenuOpen() == true)
	{
		Menu* Menu1 = CreateActor<Menu>(PoketMonRenderOrder::Menu);
		Menu1->SetPos(GetCameraPos());
	}
	
	
	
}

void PlayLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}


