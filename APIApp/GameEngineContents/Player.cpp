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

#include "Menu.h"

#include "NPC.h"

Player* Player::MainPlayer;

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::MenuOn()
{
	MenuOpen = true;
}
void Player::MenuOff()
{
	MenuOpen = false;
}

pokemon* Player::GetPokemon(int _PokemonNum)
{
	return Pokemon[_PokemonNum];
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
	GameEngineInput::CreateKey("Select", 'J');



	{
		AnimationRender = CreateRender(PoketMonRenderOrder::Player);
		AnimationRender->SetScale({ 80, 80 });

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "Player.bmp", .Start = 9, .End = 9, .InterTime = 0.02f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Player.bmp", .Start = 8, .End = 9 , .InterTime = 0.2f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "Player.bmp", .Start = 7, .End = 7, .InterTime = 0.02f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "Player.bmp", .Start = 6, .End = 7 , .InterTime = 0.2f });
		AnimationRender->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "Player.bmp", .Start = 3, .End = 3, .InterTime = 0.2f });
		AnimationRender->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "Player.bmp", .Start = 4, .End = 5 , .InterTime = 0.2f });
		AnimationRender->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "Player.bmp", .Start = 0, .End = 0, .InterTime = 0.02f });
		AnimationRender->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "Player.bmp", .Start = 1, .End = 2 , .InterTime = 0.f });
	}
	

	{
		//GameEngineRender* Render = CreateRender(PoketMonRenderOrder::Player);
		//Render->SetText("aaaa");
	}

	// NumbersRender NewRender;
	// NewRender.SetActor(this);
	// NewRender.SetValue(10000);


		BodyCollision = CreateCollision(PoketMonCollisionOrder::Player);
		BodyCollision->SetScale({ 80, 80 });
		


	ChangeState(PlayerState::IDLE);
}

float tilescale = 80.0f;

void Player::Movecalculation(float _DeltaTime)
{
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("ColMap.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	if (MenuOpen == true)
	{
		return;
	}

	Start1 = GetPos();

	if (false == MoveStart1)
	{
		if (true == GameEngineInput::IsPress("LeftMove"))
		{
			End1 = Start1 + float4(-tilescale, 0.0f);
			MoveStart1 = true;
			
			if (RGB(74, 66, 66) == ColImage->GetPixelColor(End1, RGB(58, 58, 58)))
			{
				MoveStart1 = false;
				return;
			}


		}
		else if (true == GameEngineInput::IsPress("RightMove"))
		{
			End1 = Start1 + float4(tilescale, 0.0f);
			MoveStart1 = true;
			
			if (RGB(74, 66, 66) == ColImage->GetPixelColor(End1, RGB(58, 58, 58)))
			{
				MoveStart1 = false;
				return;
			}

		}
		else if (true == GameEngineInput::IsPress("UpMove"))
		{
			End1 = Start1 + float4(0.0f, -tilescale);
			MoveStart1 = true;
			
			if (RGB(74, 66, 66) == ColImage->GetPixelColor(End1, RGB(58, 58, 58)))
			{
				MoveStart1 = false;
				return;
			}


		}
		else if (true == GameEngineInput::IsPress("DownMove"))
		{
			End1 = Start1 + float4(0.0f, tilescale);
			MoveStart1 = true;
			
			if (RGB(74, 66, 66) == ColImage->GetPixelColor(End1, RGB(58, 58, 58)))
			{
				MoveStart1 = false;
				return;
			}


		}
	}

	if (true == MoveStart1)
	{
		// 시작에서 끝까지 이동하는데 1초가 걸리는 함수
		Time += _DeltaTime * 10.0f;
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
	// 주인공 방의 출구
	float4 PlayerRoomExit1 = { 3000.0f, 1320.0f };
	float4 PlayerRoomExit2 = { 3000.0f, 1400.0f };

	//주인공 집 1층 계단
	float4 PlayerHomeStairs1 = { 3160.0f, 440.0f };
	float4 PlayerHomeStairs2 = { 3160.0f, 360.0f };

	//주인공 집 입구
	float4 PlayerHome1_1 = { 2920.0f, 1000.0f };
	float4 PlayerHome1_2 = { 3000.0f, 1000.0f };
	float4 PlayerHome2 = { 3000.0f, 920.0f };

	//주인공 집 출구
	float4 PlayerHomeExit1 = { 1480.0f, 760.0f };
	float4 PlayerHomeExit2 = { 1480.0f, 840.0f };



	//오박사 건물 입구
	float4 DrOhHome1 = { 920.0f, 600.0f };
	float4 DrOhHome2 = { 920.0f, 680.0f };


	//오박사 건물 출구
	float4 DrOhHomeExit1_1 = { 6040.0f, 1320.0f };
	float4 DrOhHomeExit1_2 = { 6120.0f, 1320.0f };
	float4 DrOhHomeExit2 = { 6120.0f, 1240.0f };

	//마을 출구 (나갈 때)
	float4 TownExit1_1 = { 360.0f, 1000.0f };
	float4 TownExit1_2 = { 360.0f, 1080.0f };

	//들어올 때
	float4 TownExit2_1 = { 440.0f, 1000.0f };
	float4 TownExit2_2 = { 440.0f, 1080.0f };


	//도시 입구 (나갈 때)
	float4 CityExit1_1 = { 5240.0f, 920.0f };
	float4 CityExit1_2 = { 5240.0f, 1000.0f };
	//들어올 때
	float4 CityExit2_1 = { 5160.0f, 920.0f };
	float4 CityExit2_2 = { 5160.0f, 1000.0f };

	//상점 입구 들어갈 때
	float4 Store1 = { 4040.0f, 760.0f };
	//상점 입구 나올 때
	float4 Store2 = { 4040.0f, 840.0f };
	//상점 출구 나갈 때
	float4 StoreExit1_1 = { 1800.0f, 2760.0f };
	float4 StoreExit1_2 = { 1880.0f, 2760.0f };
	//상점 출구 들어올 때
	float4 StoreExit2 = { 1880.0f, 2680.0f };


	//포켓몬센터 입구 들어갈 때
	float4 PC1 = { 4680.0f, 760.0f };
	//포켓몬센터 입구 나올 때
	float4 PC2 = { 4680.0f, 840.0f };

	//포켓몬센터 출구 들어올때
	float4 PCExit1_1 = { 760.0f, 2680.0f };
	//포켓몬센터 출구 나갈 때
	float4 PCExit2_1 = { 680.0f, 2760.0f };
	float4 PCExit2_2 = { 760.0f, 2760.0f };

	//체육관 입구 들어갈 때
	float4 Gym1 = { 4600.0f, 1240.0f };
	//체육관 입구 나올 때
	float4 Gym2 = { 4600.0f, 1320.0f };

	//체육관 출구 들어올 때
	float4 GymExit1 = { 6120.0f, 2600.0f };
	//체육관 출구 나올 때
	float4 GymExit2_1 = { 6040.0f, 2680.0f };
	float4 GymExit2_2 = { 6120.0f, 2680.0f };

	if (true == GameEngineInput::IsDown("Select"))
	{
		//주인공 2층 -> 1층, 2층 -> 1층
		TelePort(PlayerRoomExit1, PlayerHomeStairs1);
		TelePort(PlayerHomeStairs2, PlayerRoomExit2);

		//주인공 집 입구 ->  출구, 출구 -> 입구
		TelePort(PlayerHome1_1, PlayerHomeExit2);
		TelePort(PlayerHome1_2, PlayerHomeExit2);
		TelePort(PlayerHomeExit1, PlayerHome2);

		//오박사 건물 입구 ->  출구, 출구 -> 입구
		TelePort(DrOhHomeExit1_1, DrOhHome2);
		TelePort(DrOhHomeExit1_2, DrOhHome2);
		TelePort(DrOhHome1, DrOhHomeExit2);

		//마을-> 도시
		TelePort(TownExit1_1, CityExit2_1);
		TelePort(TownExit1_2, CityExit2_2);

		//도시->마을
		TelePort(CityExit1_1, TownExit2_1);
		TelePort(CityExit1_2, TownExit2_2);
		//상점들어갈때
		TelePort(Store1, StoreExit2);
		//상점 나올 때
		TelePort(StoreExit1_1, Store2);
		TelePort(StoreExit1_2, Store2);
		//포켓몬센터 들어갈 때
		TelePort(PC1, PCExit1_1);
		//포켓몬센터 나갈 때
		TelePort(PCExit2_1, PC2);
		TelePort(PCExit2_2, PC2);
		//체육관 들어갈 때
		TelePort(Gym1, GymExit1);
		//체육관 나올 때
		TelePort(GymExit2_1, Gym2);
		TelePort(GymExit2_2, Gym2);
		if (nullptr != BodyCollision)
		{
			
			if (true == BodyCollision->Collision({ .TargetGroup = static_cast<int>(PoketMonCollisionOrder::NPCDown), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, Collision))
			{
				
			}
			if (true == BodyCollision->Collision({ .TargetGroup = static_cast<int>(PoketMonCollisionOrder::NPCUp), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, Collision))
			{

			}
			if (true == BodyCollision->Collision({ .TargetGroup = static_cast<int>(PoketMonCollisionOrder::NPCLeft), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, Collision))
			{

			}
			if (true == BodyCollision->Collision({ .TargetGroup = static_cast<int>(PoketMonCollisionOrder::NPCRight), .TargetColType = CT_Rect, .ThisColType = CT_Rect }, Collision))
			{

			}
		}
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

	//std::string Text = "출력";
	//SetBkMode(DoubleDC, TRANSPARENT);
	//TextOut(DoubleDC, 0, 0, Text.c_str(), Text.size());

	// 디버깅용.
}

