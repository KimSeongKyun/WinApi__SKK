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
			MapRender0 = CreateRender(PoketMonRenderOrder::Map);
			MapRender0->SetImage("Map.Bmp");
			MapRender0->SetScaleToImage();
			float4 MapSize = MapRender0->GetScale();
			MapRender0->SetPosition(MapSize.half());
			
			
			
		}

		{
			
			/*
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
	int a = 0;
}