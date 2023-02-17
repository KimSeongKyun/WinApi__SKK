#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCore.h>

#include "ContentsEnums.h"

#include "Map.h"

Player* Player::MainPlayer;

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	MainPlayer = this;

	/*TestNumber.SetOwner(this);
	TestNumber.SetImage("Number.BMp", {40, 40});*/

	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');

		GameEngineInput::CreateKey("FreeMoveSwitch", '1');
		GameEngineInput::CreateKey("StageClear", '2');
	}

	{
		AnimationRender = CreateRender(PoketMonRenderOrder::Player);
		AnimationRender->SetScale({ 80, 80 });

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "Player.bmp", .Start = 8, .End = 8, .InterTime = 0.3f});
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Player.bmp", .Start = 8, .End = 9 });

		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "Player.bmp", .Start = 6, .End = 6, .InterTime = 0.3f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "Player.bmp", .Start = 6, .End = 7 });
	}

	{
		GameEngineRender* Render = CreateRender(PoketMonRenderOrder::Player);
		Render->SetText("aaaa");
	}

	// NumbersRender NewRender;
	// NewRender.SetActor(this);
	// NewRender.SetValue(10000);

	{
		BodyCollision = CreateCollision(PoketMonCollisionOrder::Player);
		BodyCollision->SetScale({ 50, 50 });
	}

	ChangeState(PlayerState::IDLE);
}


void Player::Movecalculation(float _DeltaTime)
{
	bool ScrollStart = false;

	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayLevel");
	}

	if (false == ScrollStart)
	{
		if (true == GameEngineInput::IsDown("LeftMove"))
		{
			End1 = Start1 + float4(-80.0f, 0.0f);
			ScrollStart = true;
		}
		else if (true == GameEngineInput::IsDown("RightMove"))
		{
			End1 = Start1 + float4(80.0f, 0.0f);
			ScrollStart = true;
		}
		else if (true == GameEngineInput::IsDown("UpMove"))
		{
			End1 = Start1 + float4(0.0f, -80.0f);
			ScrollStart = true;
		}
		else if (true == GameEngineInput::IsDown("DownMove"))
		{
			End1 = Start1 + float4(0.0f, 80.0f);
			ScrollStart = true;
		}
	}


	if (true == ScrollStart)
	{
		// 시작에서 끝까지 이동하는데 1초가 걸리는 함수
		Time += _DeltaTime * 0.5f;
		float4 Pos = float4::LerpClamp(Start1, End1, Time);
		SetMove(Pos);

		if (Time >= 1.0f)
		{
			ScrollStart = false;
			Time = 0.0f;
			Start1 = Pos;
		}
	}

}

void Player::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	MainPlayer = this;
	int a = 0;
}



void Player::Update(float _DeltaTime) 
{

	if (nullptr != BodyCollision)
	{
		std::vector<GameEngineCollision*> Collision;
		if (true == BodyCollision->Collision({ .TargetGroup = static_cast<int>(PoketMonCollisionOrder::Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, Collision))
		{
			for (size_t i = 0; i < Collision.size(); i++)
			{
				GameEngineActor* ColActor = Collision[i]->GetActor();
				ColActor->Death();
			}
		}
	}



	if (GameEngineInput::IsDown("StageClear"))
	{
		Map::MainMap->StageClearOn();
	}

	UpdateState(_DeltaTime);
	Movecalculation(_DeltaTime);
}

void Player::DirCheck(const std::string_view& _AnimationName)
{
	
	std::string PrevDirString = DirString;		//PrevDirString = "right"
	AnimationRender->ChangeAnimation(DirString + _AnimationName.data()); 
	
	if (GameEngineInput::IsPress("LeftMove"))
	{
		DirString = "Left_";
	}
	else if(GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
	}

	if (PrevDirString != DirString)
	{
		AnimationRender->ChangeAnimation(DirString + _AnimationName.data());
	}
}



void Player::Render(float _DeltaTime)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos() - GetLevel()->GetCameraPos();;

	Rectangle(DoubleDC, 
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
		);


	std::string MouseText = "MousePosition : ";
	MouseText += GetLevel()->GetMousePos().ToString();

	std::string CameraMouseText = "MousePositionCamera : ";
	CameraMouseText += GetLevel()->GetMousePosToCamera().ToString();

	GameEngineLevel::DebugTextPush(MouseText);
	GameEngineLevel::DebugTextPush(CameraMouseText);

	//std::string Text = "출력";
	//SetBkMode(DoubleDC, TRANSPARENT);
	//TextOut(DoubleDC, 0, 0, Text.c_str(), Text.size());

	// 디버깅용.
}