#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Nurse : public GameEngineActor
{
public:


	// constrcuter destructer
	Nurse();
	~Nurse();

	// delete Function
	Nurse(const Nurse& _Other) = delete;
	Nurse(Nurse&& _Other) noexcept = delete;
	Nurse& operator=(const Nurse& _Other) = delete;
	Nurse& operator=(Nurse&& _Other) noexcept = delete;

public:
	



protected:
	void Start() override;
	void Update(float _DeltaTime) override;



private:
	float4 _1Tile = { 80.0f, 80.0f };
	GameEngineRender* Render = nullptr;
	GameEngineRender* PCChoice = nullptr;
	GameEngineRender* PCCommuni = nullptr;
	GameEngineCollision* BodyCollision = nullptr;
	std::vector<GameEngineCollision*> Collision;
};

