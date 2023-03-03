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
	for (int i = 0; i < 2; i++)
	{
		AnimationRender[i] = CreateRender(PoketMonRenderOrder::NPC);
		AnimationRender[i]->SetScale({ 80.0f,80.0f });
	}
	AnimationRender[0]->CreateAnimation({ .AnimationName = "DROH",  .ImageName = "NPC.bmp", .Start = 0, .End = 0 });
	AnimationRender[1]->CreateAnimation({ .AnimationName = "Mom",  .ImageName = "NPC.bmp", .Start = 11, .End = 11 });
	AnimationRender[0]->ChangeAnimation("DROH");
	
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

void NPC::RenderOn(NPCState _Num)
{
	

	AnimationRender[static_cast<int>(_Num)]->On();
	
	for (int i = 0; i < 2; i++)
	{
		if (i != static_cast<int>(_Num))
		{
			AnimationRender[i]->Off();
		}
	}
	if (static_cast<int>(_Num) == 0)
	{
		DirString = "DROH";
	}

	if (static_cast<int>(_Num) == 1)
	{
		DirString = "Mom";
	}
	//if (static_cast<int>(_Num) == 3)
	//{
	//	DirString = "Mom";
	//}
	AnimationRender[static_cast<int>(_Num)]->ChangeAnimation(DirString);
}


