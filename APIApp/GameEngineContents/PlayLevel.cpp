#include "PlayLevel.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineBase/GameEngineFile.h>


// 나랑 같은 등급의 헤더들
#include "Player.h"
#include "NPC.h"
#include "Map.h"
#include "ContentsEnums.h"
#include "Menu.h"
#include "Bag.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::SoundLoading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	std::vector<GameEngineFile> Files = Dir.GetAllFile();

	for (size_t i = 0; i < Files.size(); i++)
	{
		GameEngineResources::GetInst().SoundLoad(Files[i].GetFullPath());
	}
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
		GameEngineImage* Map = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map.BMP"));
		GameEngineImage* ColMap = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ColMap.BMP"));
		GameEngineImage* Menu = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Menu.BMP"));
		GameEngineImage* Botton = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Button.BMP"));
		GameEngineImage* Bag = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bag.BMP"));
		GameEngineImage* NPC = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("NPC.BMP"));
		NPC->Cut(10, 11);
		GameEngineImage* Item = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Medicine.BMP"));
		GameEngineImage* Message = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Message.BMP"));
		GameEngineImage* YesNo = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("YesNo.BMP"));
		
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
		Actor->SetPos(StartLocation);
		Menu* Menu1 = CreateActor<Menu>(PoketMonRenderOrder::Menu);
		Bag* Bag1 = CreateActor<Bag>(PoketMonRenderOrder::Bag);
		NPC* Mom = CreateActor<NPC>(PoketMonRenderOrder::NPC);
		float4 TileRange = { 0.0f, 80.0f };
		Mom->SetPos({ 3000.0f, 600.0f });
		Mom->RenderOn("Mom");
		NPC* DROH = CreateActor<NPC>(PoketMonRenderOrder::NPC);
		DROH->SetPos({6120.0f, 520.0f});
		DROH->RenderOn("DROH");

		
		NPC* GymMaster = CreateActor<NPC>(PoketMonRenderOrder::NPC);
		GymMaster->SetPos({6120.0f,2040.0f});
		GymMaster->RenderOn("GymMaster");
		NPC* Trainer1_1 = CreateActor<NPC>(PoketMonRenderOrder::NPC);
		Trainer1_1->SetPos({ 6040.0f, 2280.0f });
		Trainer1_1->RenderOn("Trainer1");
		NPC* Trainer1_2 = CreateActor<NPC>(PoketMonRenderOrder::NPC);
		Trainer1_2->SetPos({ 6120.0f, 2280.0f });
		Trainer1_2->RenderOn("Trainer1");
		NPC* Trainer2 = CreateActor<NPC>(PoketMonRenderOrder::NPC);
		Trainer2->SetPos({5720.0f, 1640.0f});
		Trainer2->RenderOn("Trainer2");
		NPC* Trainer3 = CreateActor<NPC>(PoketMonRenderOrder::NPC);
		Trainer3->SetPos({6120.0f, 1720.0f});
		Trainer3->RenderOn("Trainer3");
		NPC* Nurse = CreateActor<NPC>(PoketMonRenderOrder::NPC);
		Nurse->SetPos({ 680.0f, 2200.0f });
		Nurse->RenderOn("Nurse");
		NPC* Customer = CreateActor<NPC>(PoketMonRenderOrder::NPC);
		Customer->SetPos({ 1720.0f, 2280.0f });
		Customer->RenderOn("Customer");
		
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

	if (false == GameEngineInput::IsKey("ChangeTitleLevel"))
	{
		GameEngineInput::CreateKey("ChangeTitleLevel", 'P');
	}
	// class NumbersRender : GameEngineActor
	// {
	// }

	// NumbersRender = CreateActor<NumbersRender>();
	// NumbersRender->SetValue(190111);
}

void PlayLevel::Update(float _DeltaTime)
{
	
	float4 Pos = Player::MainPlayer->GetPos();
	SetCameraPos(Pos - GameEngineWindow::GetScreenSize().half());

	if (GameEngineInput::IsDown("DebugRenderSwitch"))
	{
		DebugRenderSwitch();
	}

	if (GameEngineInput::IsDown("MenuOpen"))
	{
		Menu::MainMenu->RenderOn();
		Player::MainPlayer->MenuOff();
	}
}

void PlayLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	
}


