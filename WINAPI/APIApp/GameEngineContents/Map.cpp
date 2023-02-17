#include "Map.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

Map* Map::MainMap = nullptr;

Map::Map() 
{
	MainMap = this;
}

Map::~Map() 
{
}


void Map::Start()
{
	{
		// float4 Scree = GameEngineWindow::GetScreenSize();

		{
			BackGroundRender = CreateRender(PoketMonRenderOrder::BackGround);
			BackGroundRender->SetPosition(GameEngineWindow::GetScreenSize().half());
			BackGroundRender->SetScale(GameEngineWindow::GetScreenSize());
			BackGroundRender->CreateAnimation({ .AnimationName = "Loop",  .ImageName = "BackGround.bmp", .Start = 0, .End = 2, .InterTime = 0.5f });
			BackGroundRender->ChangeAnimation("Loop");
			
		}

		{
			MapRender0 = CreateRender(PoketMonRenderOrder::Map);
			MapRender0->SetImage("Map.Bmp");
			MapRender0->SetPosition({1150, -150});
			MapRender0->SetScale({6880, 2080});
		}

		{/*
			MapRender1 = CreateRender(PoketMonRenderOrder::Map);
			MapRender1->SetImage("Map.Bmp");

			float4 StartPos = MapRender0->GetImage()->GetImageScale().half();
			StartPos.x += GameEngineWindow::GetScreenSize().x;
			MapRender1->SetPosition(GameEngineWindow::GetScreenSize().half());
			MapRender1->SetScale(GameEngineWindow::GetScreenSize());*/
		}

		/*AnimationRender->SetImage("Map_Spaceport.Bmp");
		AnimationRender->SetPosition(AnimationRender->GetImage()->GetImageScale().half());
		AnimationRender->SetScaleToImage();*/
		// AnimationRender->ChangeAnimation("Loop");
	}

}


void Map::Update(float _DeltaTime)
{
	if (false == IsStageClear)
	{
		return;
	}

	MapRender0->SetMove(float4::Left * 200.0f * _DeltaTime);
	MapRender1->SetMove(float4::Left * 200.0f * _DeltaTime);

	// IsStageClear = false;
}