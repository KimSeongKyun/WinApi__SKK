#include "Nurse.h"
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "ContentsEnums.h"
#include "Player.h"

Nurse::Nurse()
{
}

Nurse::~Nurse()
{
}

void Nurse::Start()
{
	float4 Down = { 0.0f, -80.0f };
	Render = CreateRender(PoketMonRenderOrder::NPC);
	Render->SetScale(_1Tile);
	Render->CreateAnimation({ .AnimationName = "Nurse",  .ImageName = "NPC.bmp", .Start = 90, .End = 90 });
	PCChoice = CreateRender(PoketMonRenderOrder::Menu);
	PCChoice->SetImage("YesNo.BMP");
	PCChoice->SetScaleToImage();
	PCChoice->SetPosition({ 680.0f, 360.0f });
	PCChoice->EffectCameraOff();
	PCChoice->Off();
	PCCommuni = CreateRender(PoketMonRenderOrder::Menu);
	PCCommuni->SetImage("Message.BMP");
	PCCommuni->SetScaleToImage();
	PCCommuni->SetPosition({ 400.0f,600.0f });
	PCCommuni->EffectCameraOff();
	PCCommuni->Off();
	BodyCollision = CreateCollision(PoketMonCollisionOrder::Nurse);
	BodyCollision->SetScale(_1Tile);
	BodyCollision->SetPosition(GetPos() + Down + Down);
}

void Nurse::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("Select"))
	{
		if (nullptr != BodyCollision)
		{
			if (true == BodyCollision->Collision({ .TargetGroup = static_cast<int>(PoketMonCollisionOrder::Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, Collision))
			{
				Player::MainPlayer->MenuOn();
				PCChoice->On();
				PCCommuni->On();
			}
		}
	}

}
