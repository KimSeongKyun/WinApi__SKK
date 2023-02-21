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

#include "PlayLevel.h"

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


	GameEngineInput::CreateKey("LeftMove", 'A');
	GameEngineInput::CreateKey("RightMove", 'D');
	GameEngineInput::CreateKey("DownMove", 'S');
	GameEngineInput::CreateKey("UpMove", 'W');


	{
		AnimationRender = CreateRender(PoketMonRenderOrder::Player);
		AnimationRender->SetScale({ 80, 80 });

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "Player.bmp", .Start = 9, .End = 9, .InterTime = 0.01f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Player.bmp", .Start = 8, .End = 9 , .InterTime = 0.1f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "Player.bmp", .Start = 7, .End = 7, .InterTime = 0.01f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "Player.bmp", .Start = 6, .End = 7 , .InterTime = 0.1f });
		AnimationRender->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "Player.bmp", .Start = 3, .End = 3, .InterTime = 0.01f });
		AnimationRender->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "Player.bmp", .Start = 4, .End = 5 , .InterTime = 0.17f });
		AnimationRender->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "Player.bmp", .Start = 0, .End = 0, .InterTime = 0.01f });
		AnimationRender->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "Player.bmp", .Start = 1, .End = 2 , .InterTime = 0.17f });
	}
	

	{
		//GameEngineRender* Render = CreateRender(PoketMonRenderOrder::Player);
		//Render->SetText("aaaa");
	}

	// NumbersRender NewRender;
	// NewRender.SetActor(this);
	// NewRender.SetValue(10000);

	{
		BodyCollision = CreateCollision(PoketMonCollisionOrder::Player);
		BodyCollision->SetScale({ 80, 80 });
	}

	ChangeState(PlayerState::IDLE);
}

float tilescale = 80.0f;

void Player::Movecalculation(float _DeltaTime)
{
	Start1 = GetPos();
	
	if (false == MoveStart1)
	{
		if (true == GameEngineInput::IsPress("LeftMove"))
		{
			End1 = Start1 + float4(-tilescale, 0.0f);
			MoveStart1 = true;
		}
		else if (true == GameEngineInput::IsPress("RightMove"))
		{
			End1 = Start1 + float4(tilescale, 0.0f);
			MoveStart1 = true;
		}
		else if (true == GameEngineInput::IsPress("UpMove"))
		{
			End1 = Start1 + float4(0.0f, -tilescale);
			MoveStart1 = true;
		}
		else if (true == GameEngineInput::IsPress("DownMove"))
		{
			End1 = Start1 + float4(0.0f, tilescale);
			MoveStart1 = true;
		}
	}

	if (true == MoveStart1)
	{
		// ���ۿ��� ������ �̵��ϴµ� 1�ʰ� �ɸ��� �Լ�
		Time += _DeltaTime * 4.0f;
		float4 Pos = float4::LerpClamp(Start1, End1, Time);
		SetPos(Pos);

		if (Time >= 1.0f)
		{
			MoveStart1 = false;
			Time = 0.0f;
			Start1 = Pos;
		}
	}

}

bool Player::PlayerPosCheck(float4 _MapLocation)
{
	if (GetPos().ix() == _MapLocation.ix() && GetPos().iy() == _MapLocation.iy())
	{
		return true;
	}
	return false;
}

void Player::TelePort(float4 _Entrance, float4 _Exit)
{
	if (PlayerPosCheck(_Entrance))
	{
		SetPos(_Exit);
	}
}

void Player::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	MainPlayer = this;
	int a = 0;
}



void Player::Update(float _DeltaTime) 
{

	//if (nullptr != BodyCollision)
	//{
	//	std::vector<GameEngineCollision*> Collision;
	//	if (true == BodyCollision->Collision({ .TargetGroup = static_cast<int>(PoketMonCollisionOrder::Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, Collision))
	//	{
	//		for (size_t i = 0; i < Collision.size(); i++)
	//		{
	//			GameEngineActor* ColActor = Collision[i]->GetActor();
	//			ColActor->Death();
	//		}
	//	}
	//}
	
	// ���ΰ� ���� �ⱸ
	float4 PlayerRoomExit1 = { 3000.0f, 1320.0f };
	float4 PlayerRoomExit2 = { 3000.0f, 1400.0f };

	//���ΰ� �� 1�� ���
	float4 PlayerHomeStairs1 = { 3160.0f, 440.0f };
	float4 PlayerHomeStairs2 = { 3160.0f, 360.0f };

	//���ΰ� 2�� -> 1��, 2�� -> 1��
	TelePort(PlayerRoomExit1, PlayerHomeStairs1);
	TelePort(PlayerHomeStairs2, PlayerRoomExit2);

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
	if(GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
	}
	if (GameEngineInput::IsPress("UpMove"))
	{
		DirString = "Up_";
	}
	if (GameEngineInput::IsPress("DownMove"))
	{
		DirString = "Down_";
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
	MouseText += GetPos().ToString();

	std::string CameraMouseText = "MousePositionCamera : ";
	CameraMouseText += GetLevel()->GetMousePosToCamera().ToString();

	GameEngineLevel::DebugTextPush(MouseText);
	GameEngineLevel::DebugTextPush(CameraMouseText);

	//std::string Text = "���";
	//SetBkMode(DoubleDC, TRANSPARENT);
	//TextOut(DoubleDC, 0, 0, Text.c_str(), Text.size());

	// ������.
}