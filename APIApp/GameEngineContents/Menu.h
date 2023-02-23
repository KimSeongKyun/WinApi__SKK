#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Menu : public GameEngineActor
{
public:
	static Menu* MainMap;


public:
	// constrcuter destructer
	Menu();
	~Menu();

	// delete Function
	Menu(const Menu& _Other) = delete;
	Menu(Menu&& _Other) noexcept = delete;
	Menu& operator=(const Menu& _Other) = delete;
	Menu& operator=(Menu&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* Menu1 = nullptr;
	
};