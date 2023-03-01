#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class NPCState
{
	DROH,
	MOM
};
class NPC : public GameEngineActor
{
public:
	static NPC* MainPlayer;

	// constrcuter destructer
	NPC();
	~NPC();

	// delete Function
	NPC(const NPC& _Other) = delete;
	NPC(NPC&& _Other) noexcept = delete;
	NPC& operator=(const NPC& _Other) = delete;
	NPC& operator=(NPC&& _Other) noexcept = delete;

public:
	void RenderOn(NPCState _Num);



protected:
	void Start() override;
	void Update(float _DeltaTime) override;



private:
	float4 _1Tile = { 80.0f, 80.0f };
	GameEngineRender* AnimationRender[2] = {};
	GameEngineCollision* BodyCollision = nullptr;
	std::string DirString = "DROH";
};

