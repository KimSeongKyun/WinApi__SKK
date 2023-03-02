#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Bag : public GameEngineActor
{
public:
	static Bag* MainBag;


public:
	// constrcuter destructer
	Bag();
	~Bag();

	// delete Function
	Bag(const Bag& _Other) = delete;
	Bag(Bag&& _Other) noexcept = delete;
	Bag& operator=(const Bag& _Other) = delete;
	Bag& operator=(Bag&& _Other) noexcept = delete;


public:
	void RenderOn();
	void ItemInsert(int _Num);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* Bag1 = nullptr;
	std::vector< GameEngineRender*> ItemRenderers;
	GameEngineRender* NewitemRender[3];
	int CurPoketballNumber = 0;
	int MaxPoketballNumber = 0;
	int CurItemNumber = 0;
	int MaxItemNumber = 0;
	int BagType = 0;
	int MaxBagType = 0;

};