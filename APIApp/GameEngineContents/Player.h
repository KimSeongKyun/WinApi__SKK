#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>

enum class PlayerState
{
	IDLE,
	MOVE
	
};

// 설명 :
class Player : public GameEngineActor
{
public:
	static Player* MainPlayer;

	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

public:
	void ChangeMenuOpen();
	GameEngineCollision* GetCollision();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;


private:
	NumberRenderObject TestNumber;

	float AccTime = 0.0f;
	int StartFrame = 0;
	float MoveSpeed = 1.0f;
	float Time = 0.0f;
	float4 Start1 = float4::Zero;
	float4 End1 = float4::Zero;
	bool MoveStart1 = false;
	float4 _1Tile = { 80.0f, 80.0f };
	bool MenuOpen = false;
	


	std::string DirString = "Right_";
	PlayerState StateValue = PlayerState::IDLE;
	float4 MoveDir = float4::Zero;


	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* BodyCollision = nullptr;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void DirCheck(const std::string_view& _AnimationName);

	// State
	

	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);

	// FSM 내가 어떤일을 할때 이동하면서 가만히 있을수 없다.
	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void Movecalculation(float _DeltaTime);
	bool PlayerPosCheck(float4 _MapLocation);
	void TelePort(float4 _Entrance, float4 _Exit);
	
};

