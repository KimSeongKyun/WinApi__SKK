#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "pokemon.h"

enum class NPCState
{
	DROH,
	MOM,
	GymMaster,
	Trainer1,
	Trainer2,
	Trainer3,
	Nurse,

};
class NPC : public GameEngineActor
{
public:
	

	// constrcuter destructer
	NPC();
	~NPC();

	// delete Function
	NPC(const NPC& _Other) = delete;
	NPC(NPC&& _Other) noexcept = delete;
	NPC& operator=(const NPC& _Other) = delete;
	NPC& operator=(NPC&& _Other) noexcept = delete;

public:
	void RenderOn(const std::string_view& _ImageName);



protected:
	void Start() override;
	void Update(float _DeltaTime) override;

public:
	pokemon* GetPokemon(int _PokemonNum);

private:
	float4 _1Tile = { 80.0f, 80.0f };
	GameEngineRender* NPCRender = nullptr;
	GameEngineCollision* BodyCollisionLeft  = nullptr;
	GameEngineCollision* BodyCollisionRight = nullptr;
	GameEngineCollision* BodyCollisionUp    = nullptr;
	GameEngineCollision* BodyCollisionDown  = nullptr;
	GameEngineCollision* BodyCollision = nullptr;
	pokemon* Pokemon[6] = {};
	

};

