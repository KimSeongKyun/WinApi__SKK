#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCore.h>


#include "ContentsEnums.h"
#include "NPC.h"
#include "PlayLevel.h"

NPC::NPC()
{
}

NPC::~NPC()
{
}





void NPC::Start()
{
	
	NPCRender = CreateRender(PoketMonRenderOrder::NPC);
	NPCRender->SetScale(_1Tile);
	NPCRender->CreateAnimation({ .AnimationName = "DROH",  .ImageName = "NPC.bmp", .Start = 0, .End = 0 });
	NPCRender->CreateAnimation({ .AnimationName = "Mom",  .ImageName = "NPC.bmp", .Start = 11, .End = 11 });
	NPCRender->CreateAnimation({ .AnimationName = "GymMaster",  .ImageName = "NPC.bmp", .Start = 101, .End = 101 });
	NPCRender->CreateAnimation({ .AnimationName = "Trainer1",  .ImageName = "NPC.bmp", .Start = 41, .End = 41 });
	NPCRender->CreateAnimation({ .AnimationName = "Trainer2",  .ImageName = "NPC.bmp", .Start = 61, .End = 61 });
	NPCRender->CreateAnimation({ .AnimationName = "Trainer3",  .ImageName = "NPC.bmp", .Start = 81, .End = 81 });
	NPCRender->CreateAnimation({ .AnimationName = "Nurse",  .ImageName = "NPC.bmp", .Start = 90, .End = 90 });
	NPCRender->CreateAnimation({ .AnimationName = "Customer",  .ImageName = "NPC.bmp", .Start = 78, .End = 78 });
	
	float4 Left = { -80.0f, 0.0f };
	float4 Right = { 80.0f, 0.0f };
	float4 Up = { 0.0f, -80.0f };
	float4 Down = { 0.0f, 80.0f };

	BodyCollisionLeft = CreateCollision(PoketMonCollisionOrder::NPCLeft);
	BodyCollisionLeft->SetScale({80.0f, 80.0f });
	BodyCollisionLeft->SetPosition(GetPos() + Left);
	BodyCollisionRight = CreateCollision(PoketMonCollisionOrder::NPCRight);
	BodyCollisionRight->SetScale({ 80.0f, 80.0f });
	BodyCollisionRight->SetPosition(GetPos() + Right);
	BodyCollisionUp = CreateCollision(PoketMonCollisionOrder::NPCUp);
	BodyCollisionUp->SetScale({ 80.0f, 80.0f });
	BodyCollisionUp->SetPosition(GetPos() + Up);
	BodyCollisionDown = CreateCollision(PoketMonCollisionOrder::NPCDown);
	BodyCollisionDown->SetScale({ 80.0f, 80.0f });
	BodyCollisionDown->SetPosition(GetPos() + Down);
	BodyCollision = CreateCollision(PoketMonCollisionOrder::NPC);
	BodyCollision->SetScale({ 80.0f, 80.0f });
	

	
}

void NPC::Update(float _DeltaTime)
{
	
}

pokemon* NPC::GetPokemon(int _PokemonNum)
{
	return Pokemon[_PokemonNum];
}

void NPC::RenderOn(const std::string_view& _ImageName)
{
	NPCRender->ChangeAnimation(_ImageName);
}


